/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
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
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "adc.h"
#include "dma.h"
#include "tim.h"
#include "usart.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include <stdio.h>
#include "LCD_16x2_PARALLEL.h"
#include <string.h>
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
#define NUM_OF_CHANNELS 3
#define ADC_BUFFER_SIZE 240
#define UART_BUFFER_SIZE 40
#define LCD_BUFFER_SIZE 32
#define UART_RX_SIZE 16

#define ADC_V_Step 8.05861e-4f

#define LCD_UPDATE_CNT 10

#define GAIN_RESISTANCE 820
#define DIODE_coefficient 2.5e6

#define SHOW_ABSOLUTE 1
#define SHOW_DIFFERENCE 0

volatile int TICK=0;
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */
volatile uint16_t ADC_Samples[ADC_BUFFER_SIZE] = {0};
//AVERAGES
volatile float ADC_Voltages[NUM_OF_CHANNELS] = {0};
volatile double LUX_Values[NUM_OF_CHANNELS-1] = {0};
volatile double LUX_Difference;
volatile uint32_t SUM[NUM_OF_CHANNELS] = {0};
uint8_t pData_RX[UART_RX_SIZE] = {0};

char UART_data[UART_BUFFER_SIZE];

uint8_t ERROR_FLAG = 0;
volatile uint8_t LCD_SHOW_FLAG = 0;
volatile uint8_t UART_UPDATE_FLAG = 0;
volatile uint8_t ADC_CALC_AVG_FLAG = 0;
volatile uint8_t LCD_SHOW_TYPE = SHOW_ABSOLUTE;
volatile uint8_t LCD_CLEAR_ONCE = 0;
volatile uint8_t UART_SEND_FLAG = 0; // flag from PC to start UART data transmission


volatile uint8_t LCD_Delay_cnt;

char LCD_top_text[LCD_BUFFER_SIZE]="Starting...";
char LCD_bottom_text[LCD_BUFFER_SIZE]="LuxIn";
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */
double Voltage_to_lux(float Vadc);
void DELAY_US(uint16_t TIME_US);
/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{

  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_DMA_Init();
  MX_ADC1_Init();
  MX_TIM2_Init();
  MX_USART2_UART_Init();
  MX_TIM3_Init();
  /* USER CODE BEGIN 2 */
  HAL_Delay(500);

  if(HAL_ADCEx_Calibration_Start(&hadc1) != HAL_OK)
  {
  	sprintf(LCD_top_text,"ERR CALIBRATION");
  	sprintf(LCD_bottom_text,"RESET MCU");
  	ERROR_FLAG = 1;
  }

  if(HAL_ADC_Start_DMA(&hadc1,(uint32_t*)ADC_Samples,ADC_BUFFER_SIZE) != HAL_OK)
  {
  	sprintf(LCD_top_text,"ERROR ADC");
  	sprintf(LCD_bottom_text,"RESET MCU");
  	ERROR_FLAG = 1;
  }

  if(HAL_TIM_Base_Start_IT(&htim2) != HAL_OK)
  {
  	sprintf(LCD_top_text,"DISPLAY TIM ERR");
  	sprintf(LCD_bottom_text,"RESET MCU");
  	ERROR_FLAG = 1;
  }

  if(HAL_TIM_Base_Start(&htim3) != HAL_OK)
  {
  	sprintf(LCD_top_text,"ERROR MAIN TIM");
  	sprintf(LCD_bottom_text,"RESET MCU");
  	ERROR_FLAG = 1;
  }

  if(HAL_UARTEx_ReceiveToIdle_IT(&huart2, pData_RX, UART_RX_SIZE) != HAL_OK)
  {
  	sprintf(LCD_top_text,"ERROR UART");
  	sprintf(LCD_bottom_text,"CHECK CABLE");
  	ERROR_FLAG = 1;
  }

  //HAL_GPIO_WritePin(LUX_VCC_GPIO_Port, LUX_VCC_Pin, GPIO_PIN_SET);// turn on LCD DATA transmission power
  LCD_Init();
  HAL_Delay(10);
  LCD_SEND_COMMAND(LCD_DISPLAY_OFF);
  HAL_Delay(5);
  LCD_SEND_COMMAND(LCD_Entry_MODE);
  HAL_Delay(5);
  LCD_SEND_STR(LCD_top_text,0x3,0);
  LCD_SEND_STR(LCD_bottom_text,5,1);
  LCD_SEND_COMMAND(LCD_SET_DISPLAY_DEFAULT);
  HAL_Delay(2000);
  LCD_CLEAR();
  LCD_SEND_COMMAND(LCD_RETURN_HOME);
	if(ERROR_FLAG) Error_Handler();//REIKIA PALEISTI TAIMERI TIM6 PRIES ATVAIZDAVIMA, us delay
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
	  while (1)
	  {
		  if(ADC_CALC_AVG_FLAG)
		  {
			  for(uint8_t x = 0;x<ADC_BUFFER_SIZE;x++)
			  {
				  SUM[x%3] += ADC_Samples[x];
			  }

			  for(uint8_t x = 0;x<NUM_OF_CHANNELS;x++)
			  {
				  SUM[x] /= (ADC_BUFFER_SIZE/NUM_OF_CHANNELS);
				  ADC_Voltages[x] = SUM[x]*ADC_V_Step;
				  LUX_Values[x] = Voltage_to_lux(ADC_Voltages[x]);
			  }
			  ADC_CALC_AVG_FLAG=0;
			  if(!LCD_SHOW_TYPE)
			  {
				  LUX_Difference = LUX_Values[0]-LUX_Values[1];
			  }
		  }
		  if(UART_UPDATE_FLAG && !ADC_CALC_AVG_FLAG && UART_SEND_FLAG)

		  {
			  if(LCD_SHOW_TYPE)
			  {
				  sprintf(UART_data, "CH1 value = %1.1f at %d ms\r\n",LUX_Values[0],(int)HAL_GetTick());
				  HAL_UART_Transmit(&huart2, (uint8_t*)UART_data, strlen(UART_data), 100);
				  sprintf(UART_data, "CH2 value = %1.1f at %d ms\r\n",LUX_Values[1],(int)HAL_GetTick());
				  HAL_UART_Transmit(&huart2, (uint8_t*)UART_data, strlen(UART_data), 100);
				  UART_UPDATE_FLAG = 0;
			  }
			  else
			  {
				  sprintf(UART_data, "CH1-CH2 value = %1.1f at %d ms\r\n",LUX_Difference,(int)HAL_GetTick());
				  HAL_UART_Transmit(&huart2, (uint8_t*)UART_data, strlen(UART_data), 100);
				  UART_UPDATE_FLAG = 0;
			  }
		  }

		  if(LCD_SHOW_FLAG && !ADC_CALC_AVG_FLAG)
		  {
			  HAL_GPIO_TogglePin(USER_LED_GPIO_Port, USER_LED_Pin);
			  if(LCD_SHOW_TYPE)
			  {
				  sprintf((char*)LCD_top_text,"CH1=%1.1f lx    ",LUX_Values[0]);
				  LCD_SEND_COMMAND(LCD_RETURN_HOME);
				  LCD_SEND_STR((char*)LCD_top_text, 0, 0);
				  sprintf((char*)LCD_bottom_text,"CH2=%1.1f lx    ",LUX_Values[1]);
				  LCD_SEND_STR((char*)LCD_bottom_text, 0, 1);
				  LCD_SHOW_FLAG = 0;
			  }
			  else
			  {
				  if(LCD_CLEAR_ONCE)
				  {
					  LCD_CLEAR_DRAM();
					  LCD_CLEAR_ONCE = 0;
					  sprintf((char*)LCD_top_text,"DIFFERENCE");
					  LCD_SEND_STR((char*)LCD_top_text, 3, 0);
					  sprintf((char*)LCD_bottom_text,"%1.1f lx",LUX_Difference);
					  LCD_SEND_STR((char*)LCD_bottom_text, ((16-(int)strlen(LCD_bottom_text))/2), 1);
					  LCD_SHOW_FLAG = 0;
				  }
				  else
				  {
					  sprintf((char*)LCD_bottom_text,"   %1.1f lx   ",LUX_Difference);
					  LCD_SEND_STR((char*)LCD_bottom_text, ((16-(int)strlen(LCD_bottom_text))/2), 1);
					  LCD_SHOW_FLAG = 0;
				  }
			  }
		  }
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};
  RCC_PeriphCLKInitTypeDef PeriphClkInit = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.HSEPredivValue = RCC_HSE_PREDIV_DIV2;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL9;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV2;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_1) != HAL_OK)
  {
    Error_Handler();
  }
  PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_ADC;
  PeriphClkInit.AdcClockSelection = RCC_ADCPCLK2_DIV2;
  if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */
double Voltage_to_lux(float Vadc)
{
	// Vdda maitinimas operacinio Vadc nuskaityta isejimo reiksme
	volatile  double Current=0;
	static double LUX=0;

	//GAIN RES 820 k DIODE_COEF 2.5 e9, galima rodiklius suprastinti per 3
	Current = Vadc/GAIN_RESISTANCE;
	LUX = (double)(DIODE_coefficient*Current);
	return LUX;
}

void DELAY_US(uint16_t TIME_US)
{
    uint32_t old_timer_value = TIM3->CNT;
    uint32_t target_time = (old_timer_value + TIME_US) % (TIM3->ARR + 1);

    if (target_time < old_timer_value)  // Handle timer overflow
    {
        while (TIM3->CNT >= old_timer_value);  // Wait for overflow
    }

    while (TIM3->CNT < target_time);  // Wait until target time is reached
}
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
if(htim == &htim2)
{
	UART_UPDATE_FLAG = 1;
	ADC_CALC_AVG_FLAG = 1;
	if(LCD_Delay_cnt<LCD_UPDATE_CNT) LCD_Delay_cnt++;
	else
	{
		LCD_Delay_cnt %=LCD_UPDATE_CNT;
		LCD_SHOW_FLAG = 1;
	}
}
}
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
	if(GPIO_Pin == Button_SET_Pin)
	{
		LCD_SHOW_FLAG = 1;
		ADC_CALC_AVG_FLAG = 1;
		UART_UPDATE_FLAG = 1;
		LCD_CLEAR_ONCE = 1;
		if(LCD_SHOW_TYPE) LCD_SHOW_TYPE = SHOW_DIFFERENCE;
		else LCD_SHOW_TYPE = SHOW_ABSOLUTE;
	}
	for(uint8_t x = 0;x<UART_BUFFER_SIZE;x++)
	{
		UART_data[x] = '\0';
	}
	for(uint8_t x = 0;x<LCD_BUFFER_SIZE;x++)
	{
		LCD_top_text[x] = ' ';
		LCD_bottom_text[x] = ' ';
	}
}

void HAL_UARTEx_RxEventCallback(UART_HandleTypeDef *huart, uint16_t Size)
{
	char Start_string[] = "Start\r\n";
	char Stop_string[] = "Stop\r\n";
	if(huart == &huart2)
	{
		if(Size == strlen(Start_string) && strncmp(Start_string,(char*)pData_RX,Size)==0)
		{
			UART_SEND_FLAG = 1;
		}
		else if(Size == strlen(Stop_string) && strncmp(Stop_string,(char*)pData_RX,Size)==0)
		{
			UART_SEND_FLAG = 0;
		}
	}
	HAL_UARTEx_ReceiveToIdle_IT(&huart2, pData_RX, UART_RX_SIZE);// See more Start and stop flags
}

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
