/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include <software_timer.h>
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
TIM_HandleTypeDef htim2;

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_TIM2_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
void display7SEG(int counter) {
	if(counter == 0) {
		HAL_GPIO_WritePin(SEG0_GPIO_Port, SEG0_Pin, RESET);
		HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, RESET);
		HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, RESET);
		HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, RESET);
		HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin, RESET);
		HAL_GPIO_WritePin(SEG5_GPIO_Port, SEG5_Pin, RESET);
		HAL_GPIO_WritePin(SEG6_GPIO_Port, SEG6_Pin, SET);
	}
	else if(counter == 1) {
		HAL_GPIO_WritePin(SEG0_GPIO_Port, SEG0_Pin, SET);
		HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, RESET);
		HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, RESET);
		HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, SET);
		HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin, SET);
		HAL_GPIO_WritePin(SEG5_GPIO_Port, SEG5_Pin, SET);
		HAL_GPIO_WritePin(SEG6_GPIO_Port, SEG6_Pin, SET);
	}
	else if(counter == 2) {
		HAL_GPIO_WritePin(SEG0_GPIO_Port, SEG0_Pin, RESET);
		HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, RESET);
		HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, SET);
		HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, RESET);
		HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin, RESET);
		HAL_GPIO_WritePin(SEG5_GPIO_Port, SEG5_Pin, SET);
		HAL_GPIO_WritePin(SEG6_GPIO_Port, SEG6_Pin, RESET);
	}

	else if(counter == 3) {
		HAL_GPIO_WritePin(SEG0_GPIO_Port, SEG0_Pin, RESET);
		HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, RESET);
		HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, RESET);
		HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, RESET);
		HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin, SET);
		HAL_GPIO_WritePin(SEG5_GPIO_Port, SEG5_Pin, SET);
		HAL_GPIO_WritePin(SEG6_GPIO_Port, SEG6_Pin, RESET);
	}
	else if(counter == 4) {
		HAL_GPIO_WritePin(SEG0_GPIO_Port, SEG0_Pin, SET);
		HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, RESET);
		HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, RESET);
		HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, SET);
		HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin, SET);
		HAL_GPIO_WritePin(SEG5_GPIO_Port, SEG5_Pin, RESET);
		HAL_GPIO_WritePin(SEG6_GPIO_Port, SEG6_Pin, RESET);
	}
	else if(counter == 5) {
		HAL_GPIO_WritePin(SEG0_GPIO_Port, SEG0_Pin, RESET);
		HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, SET);
		HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, RESET);
		HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, RESET);
		HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin, SET);
		HAL_GPIO_WritePin(SEG5_GPIO_Port, SEG5_Pin, RESET);
		HAL_GPIO_WritePin(SEG6_GPIO_Port, SEG6_Pin, RESET);
	}
	else if(counter == 6) {
		HAL_GPIO_WritePin(SEG0_GPIO_Port, SEG0_Pin, RESET);
		HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, SET);
		HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, RESET);
		HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, RESET);
		HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin, RESET);
		HAL_GPIO_WritePin(SEG5_GPIO_Port, SEG5_Pin, RESET);
		HAL_GPIO_WritePin(SEG6_GPIO_Port, SEG6_Pin, RESET);
	}
	else if(counter == 7) {
		HAL_GPIO_WritePin(SEG0_GPIO_Port, SEG0_Pin, RESET);
		HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, RESET);
		HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, RESET);
		HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, SET);
		HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin, SET);
		HAL_GPIO_WritePin(SEG5_GPIO_Port, SEG5_Pin, SET);
		HAL_GPIO_WritePin(SEG6_GPIO_Port, SEG6_Pin, SET);
	}
	else if(counter == 8) {
		HAL_GPIO_WritePin(SEG0_GPIO_Port, SEG0_Pin, RESET);
		HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, RESET);
		HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, RESET);
		HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, RESET);
		HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin, RESET);
		HAL_GPIO_WritePin(SEG5_GPIO_Port, SEG5_Pin, RESET);
		HAL_GPIO_WritePin(SEG6_GPIO_Port, SEG6_Pin, RESET);
	}
	else if(counter == 9) {
		HAL_GPIO_WritePin(SEG0_GPIO_Port, SEG0_Pin, RESET);
		HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, RESET);
		HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, RESET);
		HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, RESET);
		HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin, SET);
		HAL_GPIO_WritePin(SEG5_GPIO_Port, SEG5_Pin, RESET);
		HAL_GPIO_WritePin(SEG6_GPIO_Port, SEG6_Pin, RESET);
	}

}

const int MAX_LED = 4;
int index_led = 0;
int led_buffer[4] = {1,2,3,4};

void update7SEG(int index) {
	switch(index) {
	  case 0:
		  HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, RESET);
		  HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, SET);
		  HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, SET);
		  HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, SET);
		  display7SEG(led_buffer[0]);
		  break;
	  case 1:
		  HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, SET);
		  HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, RESET);
		  HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, SET);
		  HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, SET);
		  display7SEG(led_buffer[1]);
		  break;
	  case 2:
		  HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, SET);
		  HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, SET);
		  HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, RESET);
		  HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, SET);
		  display7SEG(led_buffer[2]);
		  break;
	  case 3:
		  HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, SET);
		  HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, SET);
		  HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, SET);
		  HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, RESET);
		  display7SEG(led_buffer[3]);
		  break;
	  default:
		  break;

	}
}

int hour = 15, minute = 8, second = 50;
void updateClockBuffer() {
	int temp;
	if(hour >= 10) {
		temp = hour;
		led_buffer[0] = temp/10;
		temp = temp%10;
		led_buffer[1] = temp;
	}
	else {
		led_buffer[0] = 0;
		led_buffer[1] = hour;
	}

	if(minute >= 10) {
		temp = minute;
		led_buffer[2] = temp/10;
		temp = temp%10;
		led_buffer[3] = temp;
	}
	else {
		led_buffer[2] = 0;
		led_buffer[3] = minute;
	}
}

const int MAX_LED_MATRIX = 8;
const int MAX_SHIFT_NUM = 8;
int index_led_matrix = 0;
int shift_number = 1;
int shift_number2 = 6;
uint8_t matrix_buffer[8] = {0x18, 0x3C, 0x66, 0x66, 0x7E, 0x7E, 0x66, 0x66};
uint8_t temp_matrix_buffer1[8];
uint8_t matrix_buffer2[8] = {0x7E, 0x7E, 0x06, 0x3E, 0x3E, 0x06, 0x7E, 0x7E};
void displayMatrixColumn(uint8_t counter) {
	HAL_GPIO_WritePin(GPIOA, ENM0_Pin, counter >> 0 & GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOA, ENM1_Pin, counter >> 1 & GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOA, ENM2_Pin, counter >> 2 & GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOA, ENM3_Pin, counter >> 3 & GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOA, ENM4_Pin, counter >> 4 & GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOA, ENM5_Pin, counter >> 5 & GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOA, ENM6_Pin, counter >> 6 & GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOA, ENM7_Pin, counter >> 7 & GPIO_PIN_SET);
}
void updateLEDMatrix(int index) {
	switch(index) {
	case 0:
		HAL_GPIO_WritePin(GPIOB, ROW0_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOB, ROW1_Pin | ROW2_Pin | ROW3_Pin | ROW4_Pin | ROW5_Pin | ROW6_Pin | ROW7_Pin, GPIO_PIN_RESET);
		break;
	case 1:
		HAL_GPIO_WritePin(GPIOB, ROW1_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOB, ROW0_Pin | ROW2_Pin | ROW3_Pin | ROW4_Pin | ROW5_Pin | ROW6_Pin | ROW7_Pin, GPIO_PIN_RESET);
		break;
	case 2:
		HAL_GPIO_WritePin(GPIOB, ROW2_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOB, ROW0_Pin | ROW1_Pin | ROW3_Pin | ROW4_Pin | ROW5_Pin | ROW6_Pin | ROW7_Pin, GPIO_PIN_RESET);
		break;
	case 3:
		HAL_GPIO_WritePin(GPIOB, ROW3_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOB, ROW0_Pin | ROW1_Pin | ROW2_Pin | ROW4_Pin | ROW5_Pin | ROW6_Pin | ROW7_Pin, GPIO_PIN_RESET);
		break;
	case 4:
		HAL_GPIO_WritePin(GPIOB, ROW4_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOB, ROW0_Pin | ROW1_Pin | ROW2_Pin | ROW3_Pin | ROW5_Pin | ROW6_Pin | ROW7_Pin, GPIO_PIN_RESET);
		break;
	case 5:
		HAL_GPIO_WritePin(GPIOB, ROW5_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOB, ROW0_Pin | ROW1_Pin | ROW2_Pin | ROW3_Pin | ROW4_Pin | ROW6_Pin | ROW7_Pin, GPIO_PIN_RESET);
		break;
	case 6:
		HAL_GPIO_WritePin(GPIOB, ROW6_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOB, ROW0_Pin | ROW1_Pin | ROW2_Pin | ROW3_Pin | ROW4_Pin | ROW5_Pin | ROW7_Pin, GPIO_PIN_RESET);
		break;
	case 7:
		HAL_GPIO_WritePin(GPIOB, ROW7_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOB, ROW0_Pin | ROW1_Pin | ROW2_Pin | ROW3_Pin | ROW4_Pin | ROW5_Pin | ROW6_Pin, GPIO_PIN_RESET);
		break;
	default:
		break;
	}
}

void moveLeft(int shift_number, int shift_number2, uint8_t matrix1[8], uint8_t matrix2[8]) {
	temp_matrix_buffer1[0] = (matrix1[0] >> shift_number) | (matrix2[0] << shift_number2);
	temp_matrix_buffer1[1] = (matrix1[1] >> shift_number) | (matrix2[1] << shift_number2);
	temp_matrix_buffer1[2] = (matrix1[2] >> shift_number) | (matrix2[2] << shift_number2);
	temp_matrix_buffer1[3] = (matrix1[3] >> shift_number) | (matrix2[3] << shift_number2);
	temp_matrix_buffer1[4] = (matrix1[4] >> shift_number) | (matrix2[4] << shift_number2);
	temp_matrix_buffer1[5] = (matrix1[5] >> shift_number) | (matrix2[5] << shift_number2);
	temp_matrix_buffer1[6] = (matrix1[6] >> shift_number) | (matrix2[6] << shift_number2);
	temp_matrix_buffer1[7] = (matrix1[7] >> shift_number) | (matrix2[7] << shift_number2);
}

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
  MX_TIM2_Init();
  /* USER CODE BEGIN 2 */
  HAL_TIM_Base_Start_IT(&htim2);
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  setTimer1(100);	//Every second 2 LED blinks
  setTimer2(25);	//Half second each 7 led segment will display
  setTimer3(100);
  setTimer4(10);
  int currState = 1;
  while (1)
  {
	  if(timer1_flag == 1) {
		  setTimer1(100);
		  HAL_GPIO_TogglePin(DOT_GPIO_Port, DOT_Pin);
	  }

	  if(timer2_flag == 1) {
		  updateClockBuffer();
		  setTimer2(25);
		  update7SEG(index_led);
		  index_led++;
		  if(index_led == MAX_LED) index_led = 0;
	  }

	  if(timer3_flag == 1) {
		  setTimer3(100);
		  second++;
		  if(second >= 60) {
			  second = 0;
			  minute++;
		  }
		  if(minute >= 60) {
			  minute = 0;
			  hour++;
		  }
		  if(hour >= 24) {
			  hour = 0;
		  }
	  }

	  if(timer4_flag == 1) {
		  setTimer4(10);
		  updateLEDMatrix(index_led_matrix);
		  if(currState == 1) {
			  temp_matrix_buffer1[index_led_matrix] = matrix_buffer[index_led_matrix];
		  }
		  else if(currState == 2) {
			  temp_matrix_buffer1[index_led_matrix] = matrix_buffer2[index_led_matrix];
		  }
		  displayMatrixColumn(temp_matrix_buffer1[index_led_matrix]);
		  index_led_matrix++;
		  if(index_led_matrix == MAX_LED_MATRIX) {
			  index_led_matrix = 0;
			  if(currState == 1) currState = 3;
			  else if(currState == 2) currState = 4;
			  if(currState == 3) {
				  moveLeft(shift_number, shift_number2, matrix_buffer, matrix_buffer2);
			  }
			  else if(currState == 4) {
				  moveLeft(shift_number, shift_number2, matrix_buffer2, matrix_buffer);
			  }
			  shift_number++;
			  shift_number2--;
			  if(shift_number == MAX_SHIFT_NUM) shift_number = 1;
			  if(shift_number2 < 0) {
				  shift_number2 = 6;
				  if(currState == 3) currState = 2;
				  else if(currState == 4) currState = 1;
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

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief TIM2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM2_Init(void)
{

  /* USER CODE BEGIN TIM2_Init 0 */

  /* USER CODE END TIM2_Init 0 */

  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};

  /* USER CODE BEGIN TIM2_Init 1 */

  /* USER CODE END TIM2_Init 1 */
  htim2.Instance = TIM2;
  htim2.Init.Prescaler = 7999;
  htim2.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim2.Init.Period = 9;
  htim2.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim2.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim2) != HAL_OK)
  {
    Error_Handler();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim2, &sClockSourceConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim2, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM2_Init 2 */

  /* USER CODE END TIM2_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, ENM0_Pin|ENM1_Pin|DOT_Pin|LED_RED_Pin
                          |EN0_Pin|EN1_Pin|EN2_Pin|EN3_Pin
                          |ENM2_Pin|ENM3_Pin|ENM4_Pin|ENM5_Pin
                          |ENM6_Pin|ENM7_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, SEG0_Pin|SEG1_Pin|SEG2_Pin|ROW2_Pin
                          |ROW3_Pin|ROW4_Pin|ROW5_Pin|ROW6_Pin
                          |ROW7_Pin|SEG3_Pin|SEG4_Pin|SEG5_Pin
                          |SEG6_Pin|ROW0_Pin|ROW1_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : ENM0_Pin ENM1_Pin DOT_Pin LED_RED_Pin
                           EN0_Pin EN1_Pin EN2_Pin EN3_Pin
                           ENM2_Pin ENM3_Pin ENM4_Pin ENM5_Pin
                           ENM6_Pin ENM7_Pin */
  GPIO_InitStruct.Pin = ENM0_Pin|ENM1_Pin|DOT_Pin|LED_RED_Pin
                          |EN0_Pin|EN1_Pin|EN2_Pin|EN3_Pin
                          |ENM2_Pin|ENM3_Pin|ENM4_Pin|ENM5_Pin
                          |ENM6_Pin|ENM7_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : SEG0_Pin SEG1_Pin SEG2_Pin ROW2_Pin
                           ROW3_Pin ROW4_Pin ROW5_Pin ROW6_Pin
                           ROW7_Pin SEG3_Pin SEG4_Pin SEG5_Pin
                           SEG6_Pin ROW0_Pin ROW1_Pin */
  GPIO_InitStruct.Pin = SEG0_Pin|SEG1_Pin|SEG2_Pin|ROW2_Pin
                          |ROW3_Pin|ROW4_Pin|ROW5_Pin|ROW6_Pin
                          |ROW7_Pin|SEG3_Pin|SEG4_Pin|SEG5_Pin
                          |SEG6_Pin|ROW0_Pin|ROW1_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim) {
	timerRun();
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

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
