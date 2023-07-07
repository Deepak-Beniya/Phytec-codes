/*
 * Application : UART Interfacing with Bare Metal Programming
 * Step 1:Write the function for all 0 to 9
 * Step 2:call them in sequential from 0 to 9
 * Step 3: give some delay
 * Author : Deepak
 * Date : 25/04/23

 */

#include <stdint.h>
#include "uart.h"

   /*Steps to follow UART  - Initialization
    *
    * Step 1:-Enable clock access to GPIO
    *
    * Ex:- uint32_t *portaAHB1ENR =(uint32_t *)0x40023830;
    *      uint32_t *APB1ENR =(uint32_t *)0x40023840;
    *
    * Step 2:- SET PA2 MODE to alternative mode
    *
    * Ex:- uint32_t *GPIOA_MODER  =(uint32_t *)0x40020000;
    *
    * Step 3:- SET PA2 Alternative Function type to UART-Tx (AF07)
    *
    * Step 4:- Configure UART Module
    *
    * Step 5:- Configure UART BaudRate
    *
    *
    *
    */



int main(void)
{
	UART2_Init();
	while(1){

		Usart2_Transmit("Deepak");
		//printf("Deepak \r \n");
		delay(500);
	}
    /* Loop forever */
	//for(;;);
}

