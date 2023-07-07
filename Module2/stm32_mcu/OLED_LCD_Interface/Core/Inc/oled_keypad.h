/*
 * oled_keypad.h
 *
 *  Created on: 16-May-2023
 *      Author: vasundhra
 */

#ifndef INC_OLED_KEYPAD_H_
#define INC_OLED_KEYPAD_H_
#include "main.h"

void oled_keypad(void){
	              HAL_GPIO_WritePin(GPIOC,GPIO_PIN_0,1);
	    		  HAL_GPIO_WritePin(GPIOC,GPIO_PIN_1,1);
	    		  HAL_GPIO_WritePin(GPIOC,GPIO_PIN_2,1);
	    		  HAL_GPIO_WritePin(GPIOC,GPIO_PIN_3,1);
	    		  HAL_GPIO_WritePin(GPIOC,GPIO_PIN_0,0);

	    		  if(!(HAL_GPIO_ReadPin(GPIOC,GPIO_PIN_4)))
	    		  {
	    			  HAL_Delay(300);
	    			  SSD1306_GotoXY (10,10);
	    			  SSD1306_Puts ("1", &Font_11x18, 1);
	    			  SSD1306_UpdateScreen();
	    			  HAL_Delay(300);

	    		  }
	    		  if(!(HAL_GPIO_ReadPin(GPIOC,GPIO_PIN_5)))
	    		  {
	    			  HAL_Delay(100);
	    			  SSD1306_GotoXY (10,10);
	    			  SSD1306_Puts ("2", &Font_11x18, 1);
	    			  SSD1306_UpdateScreen();
	    			  HAL_Delay(300);
	    		  }
	    		  if(!(HAL_GPIO_ReadPin(GPIOC,GPIO_PIN_6)))
	    		  {
	    			  HAL_Delay(300);
	    			  SSD1306_GotoXY (10,10);
	    			  SSD1306_Puts ("3", &Font_11x18, 1);
	    			  SSD1306_UpdateScreen();
	    			  HAL_Delay(300);

	    		  }
	    		  if(!(HAL_GPIO_ReadPin(GPIOC,GPIO_PIN_7)))
	    		  {

	    			  HAL_Delay(300);
	    			  SSD1306_GotoXY (10,10);
	    			  SSD1306_Puts ("A", &Font_11x18, 1);
	    			  SSD1306_UpdateScreen();
	    			  HAL_Delay(300);

	    		  }

	    		  HAL_GPIO_WritePin(GPIOC,GPIO_PIN_0,1);
	    		  HAL_GPIO_WritePin(GPIOC,GPIO_PIN_1,1);
	    		  HAL_GPIO_WritePin(GPIOC,GPIO_PIN_2,1);
	    		  HAL_GPIO_WritePin(GPIOC,GPIO_PIN_3,1);
	    		  HAL_GPIO_WritePin(GPIOC,GPIO_PIN_1,0);
	    		  if(!(HAL_GPIO_ReadPin(GPIOC,GPIO_PIN_4)))
	    		  {
	    			  HAL_Delay(300);
	    			  SSD1306_GotoXY (10,10);
	    			  SSD1306_Puts ("4", &Font_11x18, 1);
	    			  SSD1306_UpdateScreen();
	    			  HAL_Delay(300);
	    		  }
	    		  if(!(HAL_GPIO_ReadPin(GPIOC,GPIO_PIN_5)))
	    		  {
	    			  HAL_Delay(300);
	    			  SSD1306_GotoXY (10,10);
	    			  SSD1306_Puts ("5", &Font_11x18, 1);
	    			  SSD1306_UpdateScreen();
	    			  HAL_Delay(300);

	    		  }
	    		  if(!(HAL_GPIO_ReadPin(GPIOC,GPIO_PIN_6)))
	    		  {
	    			  HAL_Delay(300);
	    			  SSD1306_GotoXY (10,10);
	    			  SSD1306_Puts ("6", &Font_11x18, 1);
	    			  SSD1306_UpdateScreen();
	    			  HAL_Delay(300);


	    		  }
	    		  if(!(HAL_GPIO_ReadPin(GPIOC,GPIO_PIN_7)))
	    		  {
	    			  HAL_Delay(300);
	    			  SSD1306_GotoXY (10,10);
	    			  SSD1306_Puts ("B", &Font_11x18, 1);
	    			  SSD1306_UpdateScreen();
	    			  HAL_Delay(300);

	    		  }

	    		  HAL_GPIO_WritePin(GPIOC,GPIO_PIN_0,1);
	    		  HAL_GPIO_WritePin(GPIOC,GPIO_PIN_1,1);
	    		  HAL_GPIO_WritePin(GPIOC,GPIO_PIN_2,1);
	    		  HAL_GPIO_WritePin(GPIOC,GPIO_PIN_3,1);
	    		  HAL_GPIO_WritePin(GPIOC,GPIO_PIN_2,0);
	    		  if(!(HAL_GPIO_ReadPin(GPIOC,GPIO_PIN_4)))
	    		  {
	    			  HAL_Delay(300);
	    			  SSD1306_GotoXY (10,10);
	    			  SSD1306_Puts ("7", &Font_11x18, 1);
	    			  SSD1306_UpdateScreen();
	    			  HAL_Delay(300);


	    		  }
	    		  if(!(HAL_GPIO_ReadPin(GPIOC,GPIO_PIN_5)))
	    		  {
	    			  HAL_Delay(300);
	    			  SSD1306_GotoXY (10,10);
	    			  SSD1306_Puts ("8", &Font_11x18, 1);
	    			  SSD1306_UpdateScreen();
	    			  HAL_Delay(300);


	    		  }
	    		  if(!(HAL_GPIO_ReadPin(GPIOC,GPIO_PIN_6)))
	    		  {
	    			  HAL_Delay(300);
	    			  SSD1306_GotoXY (10,10);
	    			  SSD1306_Puts ("9", &Font_11x18, 1);
	    			  SSD1306_UpdateScreen();
	    			  HAL_Delay(300);

	    		  }
	    		  if(!(HAL_GPIO_ReadPin(GPIOC,GPIO_PIN_7)))
	    		  {
	    			  HAL_Delay(300);
	    			  SSD1306_GotoXY (10,10);
	    			  SSD1306_Puts ("C", &Font_11x18, 1);
	    			  SSD1306_UpdateScreen();
	    			  HAL_Delay(300);

	    		  }

	    		  HAL_GPIO_WritePin(GPIOC,GPIO_PIN_0,1);
	    		  HAL_GPIO_WritePin(GPIOC,GPIO_PIN_1,1);
	    		  HAL_GPIO_WritePin(GPIOC,GPIO_PIN_2,1);
	    		  HAL_GPIO_WritePin(GPIOC,GPIO_PIN_3,1);
	    		  HAL_GPIO_WritePin(GPIOC,GPIO_PIN_3,0);
	    		  if(!(HAL_GPIO_ReadPin(GPIOC,GPIO_PIN_4)))
	    		  {
	    			  HAL_Delay(300);
	    			  SSD1306_GotoXY (10,10);
	    			  SSD1306_Puts ("*", &Font_11x18, 1);
	    			  SSD1306_UpdateScreen();
	    			  HAL_Delay(300);

	    		  }
	    		  if(!(HAL_GPIO_ReadPin(GPIOC,GPIO_PIN_5)))
	    		  {
	    			  HAL_Delay(300);
	    			  SSD1306_GotoXY (10,10);
	    			  SSD1306_Puts ("0", &Font_11x18, 1);
	    			  SSD1306_UpdateScreen();
	    			  HAL_Delay(300);

	    		  }
	    		  if(!(HAL_GPIO_ReadPin(GPIOC,GPIO_PIN_6)))
	    		  {
	    			  HAL_Delay(300);
	    			  SSD1306_GotoXY (10,10);
	    			  SSD1306_Puts ("#", &Font_11x18, 1);
	    			  SSD1306_UpdateScreen();
	    			  HAL_Delay(300);

	    		  }
	    		  if(!(HAL_GPIO_ReadPin(GPIOC,GPIO_PIN_7)))
	    		  {
	    			  HAL_Delay(300);
	    			  SSD1306_GotoXY (10,10);
	    			  SSD1306_Puts ("D", &Font_11x18, 1);
	    			  SSD1306_UpdateScreen();
	    			  HAL_Delay(300);

	    		  }

}


#endif /* INC_OLED_KEYPAD_H_ */
