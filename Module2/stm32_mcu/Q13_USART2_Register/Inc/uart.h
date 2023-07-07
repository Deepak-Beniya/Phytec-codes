/*
 * uart.h
 *
 *  Created on: 25-Apr-2023
 *      Author: vasundhra
 */

#ifndef UART_H_
#define UART_H_

void delay(int T);
void UART2_Init();
int __io_putchar(unsigned char ch);
void Usart2_Transmit(unsigned char ch);


#endif /* UART_H_ */
