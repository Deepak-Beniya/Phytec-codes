/*
 * Lcd.h
 *
 *  Created on: Apr 24, 2023
 *      Author: vasundhra
 */

#ifndef INC_LCD_H_
#define INC_LCD_H_
void print(unsigned char);
void lcd_init(void);
void lcd_data(unsigned char);
void lcd_cmd(unsigned char);
void lcd_display(unsigned char *,unsigned int);


#endif /* INC_LCD_H_ */
