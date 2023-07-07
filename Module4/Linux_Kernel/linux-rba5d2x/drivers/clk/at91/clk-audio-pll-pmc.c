/*
 *  Copyright (C) 2016 Atmel Corporation,
 *                     Nicolas Ferre <nicolas.ferre@atmel.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 */
#include <linux/clk.h>
#include <linux/clk-provider.h>
#include <linux/clkdev.h>
#include <linux/clk/at91_pmc.h>
#include <linux/of.h>
#include <linux/mfd/syscon.h>
#include <linux/regmap.h>

#include "pmc.h"

/*
 * DOC: PMC output for fractional PLL clock for audio
 *
 * Traits of this clock:
 * enable - clk_enable writes qdpmc, and enables PMC output
 * rate - rate is adjustable.
 *        clk->rate = parent->rate / (qdpmc + 1)
 * parent - fixed parent.  No clk_set_parent support
 */

#define AUDIO_PLL_FOUT_MIN		620000000
#define AUDIO_PLL_FOUT_MAX		700000000
#define AUDIO_PLL_REFERENCE_FOUT	660000000
#define AUDIO_PLL_QDPMC_MAX		(AT91_PMC_AUDIO_PLL_QDPMC_MASK >> \
						AT91_PMC_AUDIO_PLL_QDPMC_OFFSET)
struct clk_audio_pmc {
	struct clk_hw hw;
	struct regmap *regmap;
	u8 qdpmc;
};

#define to_clk_audio_pmc(hw) container_of(hw, struct clk_audio_pmc, hw)

static int clk_audio_pll_pmc_enable(struct clk_hw *hw)
{
	struct clk_audio_pmc *apmc_ck = to_clk_audio_pmc(hw);

	regmap_update_bits(apmc_ck->regmap, AT91_PMC_AUDIO_PLL0,
			   AT91_PMC_AUDIO_PLL_PMCEN |
			   AT91_PMC_AUDIO_PLL_QDPMC_MASK,
			   AT91_PMC_AUDIO_PLL_PMCEN |
			   AT91_PMC_AUDIO_PLL_QDPMC(apmc_ck->qdpmc));
	return 0;
}

static void clk_audio_pll_pmc_disable(struct clk_hw *hw)
{
	struct clk_audio_pmc *apmc_ck = to_clk_audio_pmc(hw);

	regmap_update_bits(apmc_ck->regmap, AT91_PMC_AUDIO_PLL0,
			   AT91_PMC_AUDIO_PLL_PMCEN, 0);
}

static unsigned long clk_audio_pll_pmc_recalc_rate(struct clk_hw *hw,
					           unsigned long parent_rate)
{
	struct clk_audio_pmc *apmc_ck = to_clk_audio_pmc(hw);
	unsigned long apmc_rate = 0;

	apmc_rate = parent_rate / (apmc_ck->qdpmc + 1);

	pr_debug("A PLL/PMC: %s, apmc_rate = %lu (qdpmc = %u)\n" ,
		 __func__ , apmc_rate, apmc_ck->qdpmc);

	return apmc_rate;
}

static int clk_audio_pll_compute_qdpmc(unsigned long q_rate, unsigned long rate,
				       unsigned long *qd)
{
	unsigned long tmp_qd;

	if (!rate)
		return -EINVAL;

	tmp_qd = q_rate / rate;
	if (!tmp_qd || tmp_qd > AUDIO_PLL_QDPMC_MAX)
		return -EINVAL;

	*qd = tmp_qd;
	return 0;
}

static long clk_audio_pll_pmc_round_rate(struct clk_hw *hw, unsigned long rate,
					 unsigned long *parent_rate)
{
	struct clk_hw *pclk = clk_hw_get_parent(hw);
	long best_rate = -EINVAL;
	unsigned long best_parent_rate = 0;
	unsigned long tmp_qd;

	pr_debug("A PLL/PMC: %s, rate = %lu (parent_rate = %lu)\n" ,
		 __func__ , rate, *parent_rate);

	if (clk_audio_pll_compute_qdpmc(AUDIO_PLL_REFERENCE_FOUT, rate, &tmp_qd))
		return -EINVAL;

	best_parent_rate = clk_hw_round_rate(pclk, rate * tmp_qd);
	best_rate = best_parent_rate / tmp_qd;

	pr_debug("A PLL/PMC: %s, best_rate = %ld, best_parent_rate = %lu (qd = %lu)\n",
		 __func__, best_rate, best_parent_rate, tmp_qd - 1);

	*parent_rate = best_parent_rate;
	return best_rate;
}

static int clk_audio_pll_pmc_set_rate(struct clk_hw *hw, unsigned long rate,
				      unsigned long parent_rate)
{
	struct clk_audio_pmc *apmc_ck = to_clk_audio_pmc(hw);
	unsigned long tmp_qd;
	int ret;

	pr_debug("A PLL/PMC: %s, rate = %lu (parent_rate = %lu)\n" ,
		 __func__ , rate, parent_rate);

	ret = clk_audio_pll_compute_qdpmc(parent_rate, rate, &tmp_qd);
	if (!ret)
		apmc_ck->qdpmc = tmp_qd - 1;

	return ret;
}

static const struct clk_ops audio_pll_pmc_ops = {
	.enable = clk_audio_pll_pmc_enable,
	.disable = clk_audio_pll_pmc_disable,
	.recalc_rate = clk_audio_pll_pmc_recalc_rate,
	.round_rate = clk_audio_pll_pmc_round_rate,
	.set_rate = clk_audio_pll_pmc_set_rate,
};

static void __init of_sama5d2_clk_audio_pll_pmc_setup(struct device_node *np)
{
	struct clk_audio_pmc *apmc_ck;
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

	apmc_ck = kzalloc(sizeof(*apmc_ck), GFP_KERNEL);
	if (!apmc_ck)
		return;

	init.name = name;
	init.ops = &audio_pll_pmc_ops;
	init.parent_names = (parent_name ? &parent_name : NULL);
	init.num_parents = 1;
	init.flags = CLK_SET_RATE_GATE |
		     CLK_SET_PARENT_GATE | CLK_SET_RATE_PARENT;

	apmc_ck->hw.init = &init;
	apmc_ck->regmap = regmap;

	ret = clk_hw_register(NULL, &apmc_ck->hw);
	if (ret)
		kfree(apmc_ck);
	else
		of_clk_add_hw_provider(np, of_clk_hw_simple_get, &apmc_ck->hw);

	return;
}
CLK_OF_DECLARE(of_sama5d2_clk_audio_pll_pmc_setup,
	       "atmel,sama5d2-clk-audio-pll-pmc",
	       of_sama5d2_clk_audio_pll_pmc_setup);
