/*
 * Application : Generating 1s delay through internal timers
 * Step 1:Enable the required buses
 * Step 2:Setting up the timers
 * Step 3: When timer is triggered then the given event will execute
 * Author : Deepak
 * Date : 20/04/23

 */

#include<main.h>

void timer_delay(){
	RCC->APB1ENR |=0x1;
//	GPIOB->MODER |=0x20000;
//	GPIOB->AFR[1] |=0x3;
	TIM2->PSC = 15999-1;
	TIM2->ARR = 1000-1;
	TIM2->CNT =0;
	TIM2->CR1 =1;

}

int main(){
	RCC->AHB1ENR |=0x1;
	GPIOA->MODER |= 0x400;
	timer_delay();

	while(1){
		while(!(TIM2->SR & 1));
		GPIOA->ODR ^=0x20;
		TIM2->SR =0;
	}
}
