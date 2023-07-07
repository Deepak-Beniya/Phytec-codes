/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx.h"

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
void delay_ms(uint32_t ms);
void print(uint8_t dat);
void lcd_cmd(uint8_t cmd);
void lcd_data(uint8_t mydat);
void lcd_init(void);
void lcd_display(uint8_t *str, uint16_t length);

/* Private functions ---------------------------------------------------------*/


void delay_ms(uint32_t ms)
{
  HAL_Delay(ms);
}

void print(uint8_t dat)
{
  GPIOA->ODR &= ~(GPIO_PIN_10 | GPIO_PIN_8 | GPIO_PIN_9);
  GPIOB->ODR &= ~(GPIO_PIN_3 | GPIO_PIN_5 | GPIO_PIN_4 | GPIO_PIN_10);
  GPIOC->ODR &= ~(GPIO_PIN_7);

  if (dat & 0x01)
  {
    GPIOA->ODR |= GPIO_PIN_10;
  }
  if (dat & 0x02)
  {
    GPIOB->ODR |= GPIO_PIN_3;
  }
  if (dat & 0x04)
  {
    GPIOB->ODR |= GPIO_PIN_5;
  }
  if (dat & 0x08)
  {
    GPIOB->ODR |= GPIO_PIN_4;
  }
  if (dat & 0x10)
  {
    GPIOB->ODR |= GPIO_PIN_10;
  }
  if (dat & 0x20)
  {
    GPIOA->ODR |= GPIO_PIN_8;
  }
  if (dat & 0x40)
  {
    GPIOA->ODR |= GPIO_PIN_9;
  }
  if (dat & 0x80)
  {
    GPIOC->ODR |= GPIO_PIN_7;
  }
}

void lcd_cmd(uint8_t cmd)
{
  print(cmd);
  GPIOB->ODR &= ~GPIO_PIN_5; // RS = 0 for command
  GPIOA->ODR &= ~GPIO_PIN_6; // RW = 0 for write
  GPIOA->ODR |= GPIO_PIN_7; // EN = 1
  delay_ms(1);
  GPIOA->ODR &= ~GPIO_PIN_7; // EN = 0
  }

  void lcd_data(uint8_t mydat)
  {
  print(mydat);
  GPIOB->ODR |= GPIO_PIN_5; // RS = 1 for data
  GPIOA->ODR &= ~GPIO_PIN_6; // RW = 0 for write
  GPIOA->ODR |= GPIO_PIN_7; // EN = 1
  delay_ms(1);
  GPIOA->ODR &= ~GPIO_PIN_7; // EN = 0
  }

  void lcd_init(void)
  {
  delay_ms(20); // Wait for power-up
  lcd_cmd(0x38); // 8-bit mode, 2 lines, 5x7 font
  lcd_cmd(0x0C); // Display on, cursor off, blink off
  lcd_cmd(0x01); // Clear display
  delay_ms(2);
  lcd_cmd(0x06); // Entry mode: increment, no shift
  }

  void lcd_display(uint8_t *str, uint16_t length)
  {
  for (uint16_t i = 0; i < length; i++)
  {
  lcd_data(str[i]);
  }
  }

  int main(void)
  {
  HAL_Init();
  //SystemClock_Config();

  // Enable GPIOA, GPIOB, GPIOC clocks
  RCC->AHB1ENR |= (RCC_AHB1ENR_GPIOAEN | RCC_AHB1ENR_GPIOBEN | RCC_AHB1ENR_GPIOCEN);

  // Configure PA6, PA7, PB3, PB4, PB5, PB10 as output
  GPIOA->MODER |= (GPIO_MODER_MODER6_0 | GPIO_MODER_MODER7_0 | GPIO_MODER_MODER10_0 | GPIO_MODER_MODER8_0 | GPIO_MODER_MODER9_0);
  GPIOB->MODER |= (GPIO_MODER_MODER3_0 | GPIO_MODER_MODER4_0 | GPIO_MODER_MODER5_0 | GPIO_MODER_MODER10_0 | GPIO_MODER_MODER6_0);
  GPIOC->MODER |= GPIO_MODER_MODER7_0;

  // Initialize LCD
  lcd_init();

  // Display "Hello, World!" on LCD
  uint8_t str[] = "Hello, World!";
  uint16_t length = sizeof(str) - 1; // Excluding null terminator
//  lcd_display(str, length);

  while (1)
  {
	      lcd_cmd(0x80);
	  	  lcd_display("Hello",12);
  // Main program loop
  }
  }
