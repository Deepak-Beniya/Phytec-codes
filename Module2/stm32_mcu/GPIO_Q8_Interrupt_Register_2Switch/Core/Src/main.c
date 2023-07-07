/*
 * Application : Diplay from 0 to 1 in 7 segment Display Common Anode using Register Programming
 * Step 1:Write the function for all 0 to 9
 * Step 2:call them in sequential from 0 to 9
 * Step 3: give some delay
 * Author : Deepak
 * Date : 15/04/23

 */

#include "main.h"

void EXTI15_10_IRQHandler(void) //Request Handler
{
	GPIOA->ODR ^= 0X20;         //ISR Functionality
	for(int i=0;i<30000;i++); //Delay
	EXTI->PR |=0X2000;          //Return back from ISR to Main program
}

void EXTI0_IRQHandler(void) //Request Handler
{
	GPIOA->ODR ^= 0X40;         //ISR Functionality
	for(int i=0;i<30000;i++); //Delay
	EXTI->PR |=0X1;          //Return back from ISR to Main program
}



int main()
{
	__disable_irq();                //At first We Disable IRQ line
	RCC->AHB1ENR  |= 0X5;           // Enable Clock for PA and PC (enable Port A and C)
	GPIOA->MODER |= 0x1400;          //Set out put for PA
	RCC->APB2ENR |= 0x4000;         // Enable SYS CFG
	SYSCFG->EXTICR[3] |=0x20;       //Enable SYSCFG for Trigger the Interrupt
	SYSCFG->EXTICR[0] |=0x0;
	EXTI->IMR |=0X2000;             //Make mask pin set to 1 of corresponding IRQ - PIN
	EXTI->IMR |=0X1;
	GPIOA->PUPDR |=0x2001;
	EXTI->FTSR |=0X2001;            //Trigger the interrupt on Falling edge
 	NVIC_EnableIRQ(EXTI15_10_IRQn); //Generate IRQ
 	NVIC_EnableIRQ(EXTI0_IRQn); //Generate IRQ
	__enable_irq();                 // Enable the Request line
	while(1);



}
