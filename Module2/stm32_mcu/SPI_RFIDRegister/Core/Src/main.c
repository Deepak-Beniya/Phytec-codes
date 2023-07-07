#include "LiquidCrystal_PCF8574.h"
#include "delay.h"
#include "stdio.h"
#include "RFID.h"
extern void SysClockConfig(void);

uint8_t rfid_id[4];
uint8_t rfid1;
uint8_t rfid2;
uint8_t rfid3;
uint8_t rfid4;
int main(void)
		{
		//SysClockConfig();
		systick_init_ms(16000000);
		rc522_init();
		lcd_init();
		setCursor(0,0);
		lcd_send_string("RFID RC522 with");
		setCursor(7,1);
		lcd_send_string("STM32F4");
		setCursor(0,2);
		lcd_send_string("IO");
		delay(2000);
		lcd_clear();
		while(1)
				{
				if(rc522_checkCard(rfid_id))

							{
//					rfid1=rfid_id[0];
//					rfid2=rfid_id[1];
//					rfid3=rfid_id[2];
//					rfid4=rfid_id[3];
//					if((rfid_id[0]==rfid1)&&(rfid_id[1]==rfid2)&&(rfid_id[2]==rfid3)&&(rfid_id[3]==rfid4))
//					{
//						lcd_clear();
//						lcd_send_string("ACCESS GRANTED");
//					}
							lcd_clear();
							char data[20];
							setCursor(0,0);
							lcd_send_string("RFID code is");
							setCursor(0,1);
							sprintf(data,"0x%x 0x%x 0x%x 0x%x",rfid_id[0],rfid_id[1],rfid_id[2],rfid_id[3]);
							lcd_send_string(data);
							delay(1000);
							}
				delay(100);

				}

		}
