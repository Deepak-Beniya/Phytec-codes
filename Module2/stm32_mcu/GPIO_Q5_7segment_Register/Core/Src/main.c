/*
 * Application : Diplay from 0 to 1 in 7 segment Display Common Anode using Register Programming
 * Step 1:Write the function for all 0 to 9
 * Step 2:call them in sequential from 0 to 9
 * Step 3: give some delay
 * Author : Deepak
 * Date : 15/04/23

 */
#include<main.h>
void delay(int T)
{
   int i;
    while (T--){
    	for(i=0;i<5000;i++);

    	}
    }

void display0(){
//	GPIOA->ODR |= 0x000;
//	GPIOB->ODR |= 0x100;
//	GPIOC->ODR |= 0x000;
//	GPIOA->BSRR|= 0x000;
//	GPIOB->BSRR|= 0x000;
//	GPIOC->BSRR|= 0x000;

//	delay(100);

	GPIOA->BSRR|= 0x13000;
	GPIOB->BSRR|= 0x1010000;
	GPIOC->BSRR|= 0x30000;
	delay(100);

	    GPIOA->BSRR|= 0x000;
		GPIOB->BSRR|= 0x000;
		GPIOC->BSRR|= 0x000;
		delay(100);
}
void display1(){
//    GPIOA->ODR |= 0x001;
//    GPIOB->ODR |= 0x101;
//    GPIOC->ODR |= 0x003;
	    GPIOA->BSRR |= 0x001;
	    GPIOB->BSRR |= 0x101;
	    GPIOC->BSRR |= 0x003;

}
void display2(){
//    GPIOA->ODR |= 0x010;
//    GPIOB->ODR |= 0x000;
//    GPIOC->ODR |= 0x001;
	    GPIOA->BSRR |= 0x010;
	    GPIOB->BSRR |= 0x000;
	    GPIOC->BSRR |= 0x001;

}
void display3(){
    GPIOA->ODR |= 0x000;
    GPIOB->ODR |= 0x000;
    GPIOC->ODR |= 0x003;
}
void display4(){
    GPIOA->ODR |= 0x001;
    GPIOB->ODR |= 0x001;
    GPIOC->ODR |= 0x002;
}




int main(){

	RCC->AHB1ENR |= 0x7;     //Enable PORT A,B,C
	GPIOA->MODER  |= 0x105;   //Enable PA_0,PA_1
	GPIOB->MODER  |= 0x10001;  //Enable PB_0,PB_8
	GPIOC->MODER  |= 0x5;     //Enable PC_0,PC_1

	while(1){
    display0();
//     delay(100);
//    display1();
//    delay(100);
//    display2();
//    delay(100);

	}
}

