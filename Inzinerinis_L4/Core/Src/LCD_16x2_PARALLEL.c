/*
 * LCD_16x2_PARALLEL.c
 *
 *  Created on: Mar 30, 2025
 *      Author: Linas
 */

#include "main.h"
#include "stm32l4xx_hal.h"
#include "LCD_16x2_PARALLEL.h"

void SEND_4_BIT(char data, int rsPin)//rs=0 yra instruction register o HIGH(1) data register
{
	  HAL_GPIO_WritePin(RS_GPIO_Port, RS_Pin, rsPin);

	  HAL_GPIO_WritePin(D4_GPIO_Port, D4_Pin, (data>>0)&0x1);
	  HAL_GPIO_WritePin(D5_GPIO_Port, D5_Pin, (data>>1)&0x1);
	  HAL_GPIO_WritePin(D6_GPIO_Port, D6_Pin, (data>>2)&0x1);
	  HAL_GPIO_WritePin(D7_GPIO_Port, D7_Pin, (data>>3)&0x1);
	  HAL_GPIO_WritePin(EN_GPIO_Port, EN_Pin, SET);
	  DELAY_US(500);
	  HAL_GPIO_WritePin(EN_GPIO_Port, EN_Pin, RESET);
}

void LCD_SEND_COMMAND(char komanda)
{
	  //upper
	  static char siuntimas;
	  siuntimas=(komanda>>4)&0x0f;
	  SEND_4_BIT(siuntimas, LCD_RS_INSTRUCTION);

	  //lower
	  siuntimas=(komanda)&0x0f;
	  SEND_4_BIT(siuntimas, LCD_RS_INSTRUCTION);
}
void LCD_SEND_DATA(char komanda)
{
	  //upper
	  static char siuntimas;
	  siuntimas=(komanda>>4)&0x0f;
	  SEND_4_BIT(siuntimas, LCD_RS_DATA);

	  //lower
	  siuntimas=(komanda)&0x0f;
	  SEND_4_BIT(siuntimas, LCD_RS_DATA);
}

void LCD_CLEAR()
{
	LCD_SEND_COMMAND(LCD_DISPLAY_CLEAR);
}

void LCD_CLEAR_DRAM()
{
	LCD_SEND_COMMAND(LCD_RETURN_HOME);
	for(uint8_t x = 0;x<0x28;x++)
	{
		LCD_SEND_DATA(' ');
	}
	for(uint8_t x = 0x40;x<0x68;x++)
	{
		LCD_SEND_DATA(' ');
	}
	LCD_SEND_COMMAND(LCD_RETURN_HOME);
}

void LCD_Init()
{
	  HAL_Delay(70);
	  LCD_SEND_COMMAND(LCD_FUNCTION_SET);//x28 kad 2 line
	  HAL_Delay(2);
	  LCD_SEND_COMMAND(0x28);
	  HAL_Delay(2);
////////////////////////
	  LCD_SEND_COMMAND(LCD_SET_DISPLAY_DEFAULT);//display
	  HAL_Delay(2);
	  LCD_CLEAR();

}

void LCD_SEND_STR(const char data[], unsigned int place, unsigned int level)
{
	if(level==1)
		{
		LCD_SEND_COMMAND(0xC0+place);
		}
	else LCD_SEND_COMMAND(0x80+place);
//kai N=high 2 line tai 1 line 0-4F o 2 0-27h   40-67h
// KAI level 0 tai pirmas kai 1 tai antras levelis
	static uint8_t x;
	x = 0;
	while(data[x]!='\0')
	{
		LCD_SEND_DATA(data[x]);
		x++;
	}
}
