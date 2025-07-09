/*
 * File: LCD16X2_cfg.c
 * Driver Name: [[ LCD16X2 Display (GPIO 4-Bit Mode) ]]
 * SW Layer:   ECUAL
 * Created on: Jun 28, 2020
 * Author:     Khaled Magdy
 * -------------------------------------------
 * For More Information, Tutorials, etc.
 * Visit Website: www.DeepBlueMbedded.com
 *
 */

#include "LCD16X2_cfg.h"
#include "LCD16X2.h"

const LCD16X2_CfgType LCD16X2_CfgParam[LCD16X2_MAX] =
{
	{   /*  Configuration Parameter For LCD Instance #1   */
		LCD16X2_1,			/* Index of LCD Instance #1   */
		GPIOB,	GPIO_PIN_5, /* LCD D4 Pin GPIO Port & Pin */
		GPIOB,	GPIO_PIN_6, /* LCD D5 Pin GPIO Port & Pin */
		GPIOB,	GPIO_PIN_7, /* LCD D6 Pin GPIO Port & Pin */
		GPIOB,	GPIO_PIN_8, /* LCD D7 Pin GPIO Port & Pin */
		GPIOA,	GPIO_PIN_11, /* LCD EN Pin GPIO Port & Pin */
		GPIOA,	GPIO_PIN_9  /* LCD RS Pin GPIO Port & Pin */
		/*
		 * #define RS_Pin GPIO_PIN_9
#define RS_GPIO_Port GPIOA
#define RW_Pin GPIO_PIN_10
#define RW_GPIO_Port GPIOA
#define EN_Pin GPIO_PIN_11
#define EN_GPIO_Port GPIOA
#define D4_Pin GPIO_PIN_5
#define D4_GPIO_Port GPIOB
#define D5_Pin GPIO_PIN_6
#define D5_GPIO_Port GPIOB
#define D6_Pin GPIO_PIN_7
#define D6_GPIO_Port GPIOB
#define D7_Pin GPIO_PIN_8
#define D7_GPIO_Port GPIOB
		 */
	}
};
