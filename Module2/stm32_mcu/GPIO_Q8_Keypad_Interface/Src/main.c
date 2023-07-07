/*
 * Application : Interfacing with 4*4 keypad matrix
 * Step 1:Write the function for all 0 to 9
 * Step 2:call them in sequential from 0 to 9
 * Step 3: give some delay
 * Author : Deepak
 * Date : 19/04/23

 */

#include <stdint.h>
#include<stdio.h>

#if !defined(_SOFT_FP) && defined(_ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

void delay(int T)
{
	int i;
	while(T--)
	{
	for(i=0;i<4000;i++);
	}
}


int main(void)
{
	uint32_t *portcMODER =(uint32_t *)0x40020800;
	uint32_t *portcAHB1ENR =(uint32_t *)0x40023830;
	uint32_t *portcIDR =(uint32_t *)0x40020810;
	uint32_t *portcODR =(uint32_t *)0x40020814;

	uint32_t *portcPUPDR =(uint32_t *)0x4002080c;

	 /*Enable the peripheral clock for GPIOC*/
		*portcAHB1ENR |= 0x4;

     //Rows -- PC0 -PC3 output mode
	    *portcMODER |= 0x55;

	 //columns --PC4-PC7 input mode
	    *portcMODER |= 0x00000000;

     //Setting up the PULL UP for C1,C2,C3,C4
	    *portcPUPDR |= 0x5500;


	while(1)
	{
		//Make R1 low
		*portcODR |= 0x0F;
		*portcODR &= ~(1<<0);
		if(!(*portcIDR & (1<<4)))
		{
			delay(100);
			printf("1 pressed\n");
		}
		if(!(*portcIDR & (1<<5)))
		{
			delay(100);
			printf("2 pressed\n");
		}
		if(!(*portcIDR & (1<<6)))
		{
			delay(100);
			printf("3 pressed\n");
		}
		if(!(*portcIDR & (1<<7)))
		{
			delay(100);
			printf("A pressed\n");
		}
		*portcODR |= 0x0F;
		*portcODR &= ~(1<<1);
		if(!(*portcIDR & (1<<4)))
		{
			delay(100);
			printf("4 pressed\n");
		}
		if(!(*portcIDR & (1<<5)))
		{
			delay(100);
			printf("5 pressed\n");
		}
		if(!(*portcIDR & (1<<6)))
		{
			delay(100);
			printf("6 pressed\n");
		}
		if(!(*portcIDR & (1<<7)))
		{
			delay(100);
			printf("B pressed\n");
		}
		*portcODR |= 0x0F;
		*portcODR &= ~(1<<2);
		if(!(*portcIDR & (1<<4)))
		{
			delay(100);
			printf("7 pressed\n");
		}
		if(!(*portcIDR & (1<<5)))
		{
			delay(100);
			printf("8 pressed\n");
		}
		if(!(*portcIDR & (1<<6)))
		{
			delay(100);
			printf("9 pressed\n");
		}
		if(!(*portcIDR & (1<<7)))
		{
			delay(100);
			printf("C pressed\n");
		}
		*portcODR |= 0x0F;
		*portcODR &= ~(1<<3);
		if(!(*portcIDR & (1<<4)))
		{
			delay(100);
			printf("* pressed\n");
		}
		if(!(*portcIDR & (1<<5)))
		{
			delay(100);
			printf("0 pressed\n");
		}
		if(!(*portcIDR & (1<<6)))
		{
			delay(100);
			printf("# pressed\n");
		}
		if(!(*portcIDR & (1<<7)))
		{
			delay(100);
			printf("D pressed\n");
		}

		//End Of While Loop
	}


    /* Loop forever */
	for(;;);
}
