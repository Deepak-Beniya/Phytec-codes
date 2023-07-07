/*
 * AHT25.h
 *
 *  Created on: May 11, 2023
 *      Author: chaman
 */

#ifndef INC_AHT25_H_
#define INC_AHT25_H_

#include "main.h"

#define AHT25_device_address		(uint8_t)0b01110000
#define AHT25_initialization		(uint8_t)0b11100001
#define AHT25_measurement_trigger	(uint8_t)0b10101100
#define AHT25_soft_reset			(uint8_t)0b10111010
#define I2C_read					(uint8_t)0b00000001
#define I2C_write					(uint8_t)0b00000000

#define LED_ON						HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_SET)
#define LED_OFF						HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_RESET)

extern I2C_HandleTypeDef hi2c1;

extern float AHT25_relative_humidity, AHT25_temperature;
extern uint8_t measure_humidity;

extern void AHT25_init();
extern void AHT25_reset();
extern void AHT25_read_data();


#endif /* INC_AHT25_H_ */
