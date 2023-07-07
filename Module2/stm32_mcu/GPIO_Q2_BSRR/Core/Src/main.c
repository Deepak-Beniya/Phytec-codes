/*
 * Application : Using GPIO BSRR Register program
 * Step 1:Enabled AHB1
 * Step 2:
 * Step 3:
 * Author : Deepak
 *

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
	RCC->AHB1ENR |= 0x1;
	GPIOA->MODER |= 0x400 ;


	while(1){
	GPIOA->BSRR |= 0x20;
	delay(100);
	GPIOA->BSRR |= (1<<21);
	delay(100);
	}
}
