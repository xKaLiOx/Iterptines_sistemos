/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f1xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */
extern void DELAY_US(uint16_t TIME_US);
/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define USER_LED_Pin GPIO_PIN_13
#define USER_LED_GPIO_Port GPIOC
#define LUX_VCC_Pin GPIO_PIN_7
#define LUX_VCC_GPIO_Port GPIOA
#define Button_SET_Pin GPIO_PIN_11
#define Button_SET_GPIO_Port GPIOB
#define Button_SET_EXTI_IRQn EXTI15_10_IRQn
#define RS_Pin GPIO_PIN_9
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

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
