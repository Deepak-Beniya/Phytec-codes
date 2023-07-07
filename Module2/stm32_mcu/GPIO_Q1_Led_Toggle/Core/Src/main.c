/*
 * Application : 1st GPIO program
 * Step 1:Enabled AHB1
 * Step 2:
 * Step 3:
 * Author : Deepak
 * Date: 11/04/23
 */

#include"main.h"

void delay(int T)
{
   int i;
    while (T--){
    	for(i=0;i<5000;i++);

    	}
    }
int main(){
	RCC->AHB1ENR |= 0x7;
	GPIOA->MODER |= 0x1400;
	GPIOB->MODER |= 0x400;
	GPIOC->MODER |= 0x1000;

	while(1){
	GPIOA->ODR |= 0x20;
	delay(100);
	GPIOA->ODR &= ~(0x20);
	delay(100);

	GPIOA->ODR |= 0x40;
    delay(100);
	GPIOA->ODR &= ~(0x40);
	delay(100);

	GPIOB->ODR |= 0x400;
    delay(100);
	GPIOB->ODR &= ~(0x400);
	delay(100);

	GPIOC->ODR |= 0x40;
    delay(100);
	GPIOC->ODR &= ~(0x40);
	delay(100);

	//HAL_GPIO_TogglePin();


	}
}
