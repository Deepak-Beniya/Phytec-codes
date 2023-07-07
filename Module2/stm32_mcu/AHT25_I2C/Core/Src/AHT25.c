/*
 * AHT25.c
 *
 *  Created on: May 11, 2023
 *      Author: chaman
 */




#include "AHT25.h"

float AHT25_relative_humidity = -100.0f, AHT25_temperature = -100.0f;
uint8_t measure_humidity = 0;

void AHT25_init()
{
	uint8_t init = AHT25_initialization;
	HAL_Delay(25);//needs 20 ms for i2c to stabilize after power up
	LED_ON;
	HAL_I2C_Master_Transmit(&hi2c1, AHT25_device_address | I2C_write, &init, 1, 50);
	LED_OFF;
}

void AHT25_reset()
{
	uint8_t reset = AHT25_soft_reset;
	LED_ON;
	HAL_I2C_Master_Transmit(&hi2c1, AHT25_device_address | I2C_write, &reset, 1, 50);
	LED_OFF;
	HAL_Delay(25);//takes some time to reset
}

void AHT25_read_data()
{
	uint8_t data[3] = { AHT25_measurement_trigger, 0b00110011, 0b00000000 };
	uint8_t received_data[6];
	LED_ON;
	HAL_I2C_Master_Transmit(&hi2c1, AHT25_device_address | I2C_write, &data[0], 3, 50);
	LED_OFF;
	uint8_t attempts = 5;
	do{
		attempts--;
		HAL_Delay(200);//measurement takes 75 ms
		LED_ON;
		HAL_I2C_Master_Receive(&hi2c1, AHT25_device_address | I2C_read, &received_data[0], 6, 50);
		LED_OFF;
	}while((received_data[5] & 0b10000000) == 128 && attempts > 0);


	if((received_data[5] & 0b10000000) == 0)
	{
		const uint32_t constant = 1400000;

		uint32_t humidity_bytes = (((uint32_t)received_data[4]) << 12) + (((uint32_t)received_data[3]) << 4) + (((uint32_t)received_data[2] & 0b11110000) >> 4);
		AHT25_relative_humidity = ((float)humidity_bytes / (float)constant) * 100.0f;

		uint32_t temperature_bytes = ((uint32_t)(received_data[2] & 0b00001111) << 16) + ((uint32_t)received_data[1] << 8) + (uint32_t)received_data[0];
		AHT25_temperature = (((float)temperature_bytes / (float)constant ) * 200.0f) - 50.0f;
	}
	else{
		  AHT25_reset();
		  HAL_Delay(100);
		  AHT25_init();
		  HAL_Delay(100);
	}
}
