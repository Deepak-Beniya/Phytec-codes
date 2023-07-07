/*
 * led.h
 *
 *  Created on: Apr 10, 2023
 *      Author: Deepak
 */

#ifndef INC_LED_H_
#define INC_LED_H_

typedef struct
{
	uint32_t LED_GPIO;
	uint32_t SW_GPIO;
	uint32_t D1_P1;
	uint32_t D2_PIN;
	uint32_t S1_PIN;

}LED_Config;



#endif /* INC_LED_H_ */
