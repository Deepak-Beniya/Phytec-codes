/*
 *  Copyright (C) 2016 Atmel Corporation,
 *  		       Songjun Wu <songjun.wu@atmel.com>,
 *                     Nicolas Ferre <nicolas.ferre@atmel.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 */
#include <linux/clk-provider.h>
#include <linux/clkdev.h>
#include <linux/clk/at91_pmc.h>
#include <linux/of.h>
#include <linux/mfd/syscon.h>
#include <linux/regmap.h>

#include "pmc.h"

/*
 * DOC: Fractional PLL clock for audio
 *
 * Traits of this clock:
 * prepare - clk_prepare puts audio PLL in reset state
 * enable - clk_enable writes nd, fracr parameters and enables PLL
 * rate - rate is adjustable.
 *        clk->rate = parent->rate * ((nd + 1) + (fracr / 2^22))
 * parent - fixed parent.  No clk_set_parent support
 */

#define AUDIO_PLL_DIV_FRAC	(1 << 22)
#define AUDIO_PLL_ND_MAX	(AT91_PMC_AUDIO_PLL_ND_MASK >> \
					AT91_PMC_AUDIO_PLL_ND_OFFSET)

struct clk_audio_frac {
	struct clk_hw hw;
	struct regmap *regmap;
	spinlock_t *lock;
	u32 fracr;
	u8 nd;
};

#define to_clk_audio_frac(hw) container_of(hw, struct clk_audio_frac, hw)

/* make sure that pll is in reset state beforehand */
static int clk_audio_pll_prepare(struct clk_hw *hw)
{
	struct clk_audio_frac *fck = to_clk_audio_frac(hw);

	regmap_update_bits(fck->regmap, AT91_PMC_AUDIO_PLL0,
			   AT91_PMC_AUDIO_PLL_RESETN, 0);
	return 0;
}

static void clk_audio_pll_unprepare(struct clk_hw *hw)
{
	clk_audio_pll_prepare(hw);
}

static int clk_audio_pll_enable(struct clk_hw *hw)
{
	struct clk_audio_frac *fck = to_clk_audio_frac(hw);
	unsigned long flags;

	spin_lock_irqsave(fck->lock, flags);
	regmap_update_bits(fck->regmap, AT91_PMC_AUDIO_PLL0,
			   AT91_PMC_AUDIO_PLL_RESETN,
			   AT91_PMC_AUDIO_PLL_RESETN);
	regmap_update_bits(fck->regmap, AT91_PMC_AUDIO_PLL1,
			   AT91_PMC_AUDIO_PLL_FRACR_MASK, fck->fracr);

	/*
	 * reset and enable have to be done in 2 separated writes
	 * for AT91_PMC_AUDIO_PLL0
	 */
	regmap_update_bits(fck->regmap, AT91_PMC_AUDIO_PLL0,
			   AT91_PMC_AUDIO_PLL_PLLEN |
			   AT91_PMC_AUDIO_PLL_ND_MASK,
			   AT91_PMC_AUDIO_PLL_PLLEN |
			   AT91_PMC_AUDIO_PLL_ND(fck->nd));
	spin_unlock_irqrestore(fck->lock, flags);
	return 0;
}

static void clk_audio_pll_disable(struct clk_hw *hw)
{
	struct clk_audio_frac *fck = to_clk_audio_frac(hw);
	unsigned long flags;

	spin_lock_irqsave(fck->lock, flags);
	regmap_update_bits(fck->regmap, AT91_PMC_AUDIO_PLL0,
			   AT91_PMC_AUDIO_PLL_PLLEN, 0);
	/* do it in 2 separated writes */
	regmap_update_bits(fck->regmap, AT91_PMC_AUDIO_PLL0,
			   AT91_PMC_AUDIO_PLL_RESETN, 0);
	spin_unlock_irqrestore(fck->lock, flags);
}

static unsigned long clk_audio_pll_fout(unsigned long parent_rate,
					unsigned long nd, unsigned long fracr)
{
	unsigned long long fr = (unsigned long long)parent_rate *
						(unsigned long long)fracr;

	pr_debug("A PLL: %s, fr = %llu\n" ,
		 __func__ , fr);

	fr = DIV_ROUND_CLOSEST_ULL(fr, AUDIO_PLL_DIV_FRAC);

	pr_debug("A PLL: %s, fr = %llu\n" ,
		 __func__ , fr);

	return parent_rate * (nd + 1) + fr;
}

static unsigned long clk_audio_pll_recalc_rate(struct clk_hw *hw,
					       unsigned long parent_rate)
{
	struct clk_audio_frac *fck = to_clk_audio_frac(hw);
	unsigned long fout;

	fout = clk_audio_pll_fout(parent_rate, fck->nd, fck->fracr);

	pr_debug("A PLL: %s, fout = %lu (nd = %u, fracr = %lu)\n" ,
		 __func__ , fout, fck->nd, (unsigned long)fck->fracr);

	return fout;
}

static int clk_audio_pll_compute_frac(unsigned long rate, unsigned long parent_rate,
				      unsigned long *nd, unsigned long *fracr)
{
	unsigned long long tmp;
	unsigned long long r;

	if (!rate)
		return -EINVAL;

	tmp = rate;
	r = do_div(tmp, parent_rate);
	if (tmp == 0 || (tmp - 1) > AUDIO_PLL_ND_MAX)
		return -EINVAL;

	*nd = tmp - 1;

	tmp = r * AUDIO_PLL_DIV_FRAC;
	tmp = DIV_ROUND_CLOSEST_ULL(tmp, parent_rate);
	if (tmp > AT91_PMC_AUDIO_PLL_FRACR_MASK)
		return -EINVAL;

	/* we can cast here as we verified the bounds just above */
	*fracr = (unsigned long)tmp;

	return 0;
}

static long clk_audio_pll_round_rate(struct clk_hw *hw, unsigned long rate,
				     unsigned long *parent_rate)
{
	long best_rate = -EINVAL;
	unsigned long fracr;
	unsigned long nd;
	int ret;

	pr_debug("A PLL: %s, rate = %lu (parent_rate = %lu)\n" ,
		 __func__ , rate, *parent_rate);

	ret = clk_audio_pll_compute_frac(rate, *parent_rate, &nd, &fracr);
	if (ret)
		return ret;

	best_rate = clk_audio_pll_fout(*parent_rate, nd, fracr);

	pr_debug("A PLL: %s, best_rate = %lu (nd = %lu, fracr = %lu)\n" ,
		 __func__ , best_rate, nd, fracr);

	return best_rate;
}

static int clk_audio_pll_set_rate(struct clk_hw *hw, unsigned long rate,
				  unsigned long parent_rate)
{
	struct clk_audio_frac *fck = to_clk_audio_frac(hw);
	unsigned long fracr;
	unsigned long nd;
	int ret;

	pr_debug("A PLL: %s, rate = %lu (parent_rate = %lu)\n" ,
		 __func__ , rate, parent_rate);

	ret = clk_audio_pll_compute_frac(rate, parent_rate, &nd, &fracr);
	if (ret)
		return ret;

	fck->nd = nd;
	fck->fracr = fracr;

	return 0;
}

static const struct clk_ops audio_pll_ops = {
	.prepare = clk_audio_pll_prepare,
	.unprepare = clk_audio_pll_unprepare,
	.enable = clk_audio_pll_enable,
	.disable = clk_audio_pll_disable,
	.recalc_rate = clk_audio_pll_recalc_rate,
	.round_rate = clk_audio_pll_round_rate,
	.set_rate = clk_audio_pll_set_rate,
};

static void __init of_sama5d2_clk_audio_pll_setup(struct device_node *np)
{
	struct clk_audio_frac *fck;
	struct clk_init_data init;
	struct regmap *regmap;
	const char *parent_name;
	const char *name = np->name;
	int ret;

	parent_name = of_clk_get_parent_name(np, 0);

	of_property_read_string(np, "clock-output-names", &name);

	regmap = syscon_node_to_regmap(of_get_parent(np));
	if (IS_ERR(regmap))
		return;

	fck = kzalloc(sizeof(*fck), GFP_KERNEL);
	if (!fck)
		return;

	init.name = name;
	init.ops = &audio_pll_ops;
	init.parent_names = (parent_name ? &parent_name : NULL);
	init.num_parents = 1;
	init.flags = CLK_SET_RATE_GATE;

	fck->hw.init = &init;
	fck->regmap = regmap;
	fck->lock = &pmc_pcr_lock;

	ret = clk_hw_register(NULL, &fck->hw);
	if (ret)
		kfree(fck);
	else
		of_clk_add_hw_provider(np, of_clk_hw_simple_get, &fck->hw);

	return;
}
CLK_OF_DECLARE(of_sama5d2_clk_audio_pll_setup,
	       "atmel,sama5d2-clk-audio-pll-frac",
	       of_sama5d2_clk_audio_pll_setup);
