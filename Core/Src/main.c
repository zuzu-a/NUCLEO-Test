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
#include "dac.h"
#include "i2c.h"
#include "spi.h"
#include "usart.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

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

/* USER CODE BEGIN PV */
  // Incremented by 1 ms systick interrupt
  uint32_t systick_counter = 0;
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */

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
  LL_APB1_GRP1_EnableClock(LL_APB1_GRP1_PERIPH_PWR);
  LL_APB2_GRP1_EnableClock(LL_APB2_GRP1_PERIPH_SYSCFG);

  /* System interrupt init*/
  NVIC_SetPriorityGrouping(NVIC_PRIORITYGROUP_4);

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_ADC1_Init();
  MX_ADC2_Init();
  MX_ADC3_Init();
  MX_DAC_Init();
  MX_I2C2_Init();
  MX_SPI1_Init();
  MX_SPI3_Init();
  MX_SPI4_Init();
  MX_USART3_UART_Init();
  /* USER CODE BEGIN 2 */
  LL_SYSTICK_EnableIT();

  /* @param commandBuffer While we try to figure out the command buffer's endiannes, 
   *                      the best we can do is to try and parse both sides. 
   *
   *
   */
  uint8_t commandBuffer[3];
  
  float desiredVoltage = 2.0;
  uint16_t desiredVoltageCode = voltCodeConvert(desiredVoltage);

  setChannel(commandBuffer, LTC2620_CHANNEL_ALL);
  setCommand(commandBuffer, LTC2620_COMMAND_WRITE_N_UPDATE_ALL);
  setVoltage(commandBuffer, desiredVoltageCode);

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
    /*
    if(LL_GPIO_IsInputPinSet(PUSH_BUTTON_GPIO_Port, PUSH_BUTTON_Pin)) {
      LL_GPIO_SetOutputPin(LD1_GPIO_Port, LD1_Pin);
      LL_mDelay(50);
      LL_GPIO_ResetOutputPin(LD1_GPIO_Port, LD1_Pin);
      LL_GPIO_SetOutputPin(LD2_GPIO_Port, LD2_Pin);
      LL_mDelay(50);
      LL_GPIO_ResetOutputPin(LD2_GPIO_Port, LD2_Pin);
      LL_GPIO_SetOutputPin(LD3_GPIO_Port, LD3_Pin);
      LL_mDelay(50);    
      LL_GPIO_ResetOutputPin(LD3_GPIO_Port, LD3_Pin);  
    }
  */
    LL_GPIO_SetOutputPin(LD1_GPIO_Port, LD1_Pin);

    LL_GPIO_ResetOutputPin(SPI1_CS_GPIO_Port, SPI1_CS_Pin);
    SPI_SendBytes(SPI1, commandBuffer, 3);
    LL_GPIO_SetOutputPin(SPI1_CS_GPIO_Port, SPI1_CS_Pin);

    LL_mDelay(300);

    LL_GPIO_ResetOutputPin(LD1_GPIO_Port, LD1_Pin);
    LL_GPIO_SetOutputPin(LD2_GPIO_Port, LD2_Pin);

    desiredVoltage = 2.5;
    desiredVoltageCode = voltCodeConvert(desiredVoltage);
    setChannel(commandBuffer, LTC2620_CHANNEL_ALL);
    setCommand(commandBuffer, LTC2620_COMMAND_WRITE_N_UPDATE_ALL);
    setVoltage(commandBuffer, desiredVoltageCode);
    

    LL_GPIO_ResetOutputPin(SPI1_CS_GPIO_Port, SPI1_CS_Pin);
    SPI_SendBytes(SPI1, commandBuffer, 3);
    LL_GPIO_SetOutputPin(SPI1_CS_GPIO_Port, SPI1_CS_Pin);

    LL_mDelay(300);

    LL_GPIO_ResetOutputPin(LD2_GPIO_Port, LD2_Pin);
    LL_GPIO_SetOutputPin(LD3_GPIO_Port, LD2_Pin);

    desiredVoltage = 3.0;
    desiredVoltageCode = voltCodeConvert(desiredVoltage);
    setChannel(commandBuffer, LTC2620_CHANNEL_ALL);
    setCommand(commandBuffer, LTC2620_COMMAND_WRITE_N_UPDATE_ALL);
    setVoltage(commandBuffer, desiredVoltageCode);

    LL_GPIO_ResetOutputPin(SPI1_CS_GPIO_Port, SPI1_CS_Pin);
    SPI_SendBytes(SPI1, commandBuffer, 3);
    LL_GPIO_SetOutputPin(SPI1_CS_GPIO_Port, SPI1_CS_Pin);
    
    LL_mDelay(300);

    LL_GPIO_ResetOutputPin(LD3_GPIO_Port, LD2_Pin);


  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  LL_FLASH_SetLatency(LL_FLASH_LATENCY_3);
  while(LL_FLASH_GetLatency()!= LL_FLASH_LATENCY_3)
  {
  }
  LL_PWR_SetRegulVoltageScaling(LL_PWR_REGU_VOLTAGE_SCALE3);
  LL_PWR_EnableOverDriveMode();
  LL_RCC_HSE_EnableBypass();
  LL_RCC_HSE_Enable();

   /* Wait till HSE is ready */
  while(LL_RCC_HSE_IsReady() != 1)
  {

  }
  LL_RCC_PLL_ConfigDomain_SYS(LL_RCC_PLLSOURCE_HSE, LL_RCC_PLLM_DIV_4, 96, LL_RCC_PLLP_DIV_2);
  LL_RCC_PLL_Enable();

   /* Wait till PLL is ready */
  while(LL_RCC_PLL_IsReady() != 1)
  {

  }
  while (LL_PWR_IsActiveFlag_VOS() == 0)
  {
  }
  LL_RCC_SetAHBPrescaler(LL_RCC_SYSCLK_DIV_1);
  LL_RCC_SetAPB1Prescaler(LL_RCC_APB1_DIV_2);
  LL_RCC_SetAPB2Prescaler(LL_RCC_APB2_DIV_1);
  LL_RCC_SetSysClkSource(LL_RCC_SYS_CLKSOURCE_PLL);

   /* Wait till System clock is ready */
  while(LL_RCC_GetSysClkSource() != LL_RCC_SYS_CLKSOURCE_STATUS_PLL)
  {

  }
  LL_Init1msTick(96000000);
  LL_SetSystemCoreClock(96000000);

   /* Set Timers Clock Prescalers */
  LL_RCC_SetTIMPrescaler(LL_RCC_TIM_PRESCALER_TWICE);
}

/* USER CODE BEGIN 4 */

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
  while (1) {
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
