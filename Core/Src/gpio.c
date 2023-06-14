/* USER CODE BEGIN Header */
/**
 ******************************************************************************
 * @file    gpio.c
 * @brief   This file provides code for the configuration
 *          of all used GPIO pins.
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2023 STMicroelectronics.
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
#include "gpio.h"

/* USER CODE BEGIN 0 */
GPIO_Value SIDE_RIGHT_LED = {LED1_GPIO_Port, LED1_Pin};
GPIO_Value FRONT_RIGHT_LED = {LED2_GPIO_Port, LED2_Pin};
GPIO_Value FRONT_LEFT_LED = {LED3_GPIO_Port, LED3_Pin};
GPIO_Value SIDE_LEFT_LED = {LED4_GPIO_Port, LED4_Pin};

GPIO_Value BACK_RIGHT_RED_LED = {LED5_GPIO_Port, LED5_Pin};
GPIO_Value BACK_RIGHT_ORANGE_LED = {LED6_GPIO_Port, LED6_Pin};
GPIO_Value BACK_LEFT_RED_LED = {LED7_GPIO_Port, LED5_Pin};
GPIO_Value BACK_LEFT_ORANGE_LED = {LED8_GPIO_Port, LED6_Pin};

GPIO_Value USER_SW = {SW_GPIO_Port, SW_Pin};
GPIO_Value SPI_CS_ENC_L = {SPI1_CS_ENC_L_GPIO_Port, SPI1_CS_ENC_L_Pin};
GPIO_Value SPI_CS_ENC_R = {SPI1_CS_ENC_R_GPIO_Port, SPI1_CS_ENC_R_Pin};
/* USER CODE END 0 */

/*----------------------------------------------------------------------------*/
/* Configure GPIO                                                             */
/*----------------------------------------------------------------------------*/
/* USER CODE BEGIN 1 */

/* USER CODE END 1 */

/** Configure pins as
        * Analog
        * Input
        * Output
        * EVENT_OUT
        * EXTI
*/
void MX_GPIO_Init(void)
{

  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOH_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(LED6_GPIO_Port, LED6_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(LED7_GPIO_Port, LED7_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, LED8_Pin|LED1_Pin|LED2_Pin|SPI1_CS_IMU_Pin
                          |LED5_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, SPI1_CS_ENC_L_Pin|LED3_Pin|LED4_Pin|SPI1_CS_ENC_R_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin : PtPin */
  GPIO_InitStruct.Pin = LED6_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(LED6_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : PtPin */
  GPIO_InitStruct.Pin = LED7_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(LED7_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : PBPin PBPin PBPin PBPin
                           PBPin */
  GPIO_InitStruct.Pin = LED8_Pin|LED1_Pin|LED2_Pin|SPI1_CS_IMU_Pin
                          |LED5_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pin : PtPin */
  GPIO_InitStruct.Pin = SW_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(SW_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : PAPin PAPin PAPin PAPin */
  GPIO_InitStruct.Pin = SPI1_CS_ENC_L_Pin|LED3_Pin|LED4_Pin|SPI1_CS_ENC_R_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

}

/* USER CODE BEGIN 2 */
GPIO_PinState Read_GPIO(GPIO_Value GPIO)
{
  return HAL_GPIO_ReadPin(GPIO.GPIOx, GPIO.GPIO_PIN_x);
}

void Toggle_GPIO(GPIO_Value GPIO)
{
  HAL_GPIO_TogglePin(GPIO.GPIOx, GPIO.GPIO_PIN_x);
}

void Write_GPIO(GPIO_Value GPIO, GPIO_PinState PinState)
{
  HAL_GPIO_WritePin(GPIO.GPIOx, GPIO.GPIO_PIN_x, PinState);
}
/* USER CODE END 2 */
