/*
 * led.c
 *
 *  Created on: Apr 4, 2023
 *      Author: vasundhra
 */
#include "main.h"
void Led_Toggle_ON()
{

	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_5,1);
	HAL_Delay(100);

	}
void Led_Toggle_OFF()
{
	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_5,0);
	HAL_Delay(100);

	}

void Led_External_ON()
{

	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_6,1);
	HAL_Delay(100);

	}
void Led_External_OFF()
{

	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_6,0);
	HAL_Delay(100);

	}


