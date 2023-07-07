/*
 * internal_RTC.h
 *
 *  Created on: May 16, 2023
 *      Author: vasundhra
 */

#ifndef INC_INTERNAL_RTC_H_
#define INC_INTERNAL_RTC_H_
#include "main.h"
RTC_HandleTypeDef hrtc;

char time[10];
char date[10];
uint8_t alarm =0;
	void set_time (void)
	{
		  RTC_TimeTypeDef sTime;
		  RTC_DateTypeDef sDate;
	    /**Initialize RTC and set the Time and Date
	    */
	  sTime.Hours = 0x10;
	  sTime.Minutes = 0x20;
	  sTime.Seconds = 0x30;
	  sTime.DayLightSaving = RTC_DAYLIGHTSAVING_NONE;
	  sTime.StoreOperation = RTC_STOREOPERATION_RESET;
	  if (HAL_RTC_SetTime(&hrtc, &sTime, RTC_FORMAT_BCD) != HAL_OK)
	  {
	    //_Error_Handler(__FILE__, __LINE__);
	  }
	  /* USER CODE BEGIN RTC_Init 3 */

	  /* USER CODE END RTC_Init 3 */

	  sDate.WeekDay = RTC_WEEKDAY_TUESDAY;
	  sDate.Month = RTC_MONTH_AUGUST;
	  sDate.Date = 0x12;
	  sDate.Year = 0x0;

	  if (HAL_RTC_SetDate(&hrtc, &sDate, RTC_FORMAT_BCD) != HAL_OK)
	  {
	    //_Error_Handler(__FILE__, __LINE__);
	  }
	  /* USER CODE BEGIN RTC_Init 4 */

	  HAL_RTCEx_BKUPWrite(&hrtc, RTC_BKP_DR1, 0x32F2);  // backup register

	  /* USER CODE END RTC_Init 4 */
	}

	void set_alarm (void)
	{
		  RTC_AlarmTypeDef sAlarm;

	    /**Enable the Alarm A
	    */
	  sAlarm.AlarmTime.Hours = 0x10;
	  sAlarm.AlarmTime.Minutes = 0x21;
	  sAlarm.AlarmTime.Seconds = 0x0;
	  sAlarm.AlarmTime.SubSeconds = 0x0;
	  sAlarm.AlarmTime.DayLightSaving = RTC_DAYLIGHTSAVING_NONE;
	  sAlarm.AlarmTime.StoreOperation = RTC_STOREOPERATION_RESET;
	  sAlarm.AlarmMask = RTC_ALARMMASK_NONE;
	  sAlarm.AlarmSubSecondMask = RTC_ALARMSUBSECONDMASK_ALL;
	  sAlarm.AlarmDateWeekDaySel = RTC_ALARMDATEWEEKDAYSEL_DATE;
	  sAlarm.AlarmDateWeekDay = 0x12;
	  sAlarm.Alarm = RTC_ALARM_A;
	  if (HAL_RTC_SetAlarm_IT(&hrtc, &sAlarm, RTC_FORMAT_BCD) != HAL_OK)
	  {
	    _Error_Handler(__FILE__, __LINE__);
	  }
	  /* USER CODE BEGIN RTC_Init 5 */

	  /* USER CODE END RTC_Init 5 */
	}

	void get_time(void)
	{
	  RTC_DateTypeDef gDate;
	  RTC_TimeTypeDef gTime;

	  /* Get the RTC current Time */
	  HAL_RTC_GetTime(&hrtc, &gTime, RTC_FORMAT_BIN);
	  /* Get the RTC current Date */
	  HAL_RTC_GetDate(&hrtc, &gDate, RTC_FORMAT_BIN);

	  /* Display time Format: hh:mm:ss */
	  sprintf((char*)time,"%02d:%02d:%02d",gTime.Hours, gTime.Minutes, gTime.Seconds);

	  /* Display date Format: mm-dd-yy */
	  sprintf((char*)date,"%02d-%02d-%2d",gDate.Date, gDate.Month, 2000 + gDate.Year);  // I like the date first
	}

	//Let's display the time and date on lcd

	void display_time (void)
	{
		lcd_send_cmd (0x80);
//		lcd_send_string (time);
//		lcd_send_cmd (0xc0);
//		lcd_send_string (date);
	}

	void HAL_RTC_AlarmAEventCallback(RTC_HandleTypeDef *hrtc)
	{
		alarm = 1;
	}

	void to_do_on_alarm (void)
	{
		HAL_GPIO_WritePin (GPIOA, GPIO_PIN_5, 1);  // set led ON
		lcd_send_cmd (0x80);
		lcd_send_string ("SUBSCRIBE TO");
		lcd_send_cmd (0xc0);
		lcd_send_string ("this CHANNEL");
		HAL_Delay (3000);
		lcd_send_cmd (0x80);
		for (int i=0;i<60;i++)
		{
			lcd_send_data (' ');  // clear lcd
		}
	}




#endif /* INC_INTERNAL_RTC_H_ */
