/* USER CODE BEGIN Header */
/**
 ******************************************************************************
 * @file    spi.h
 * @brief   This file contains all the function prototypes for
 *          the spi.c file
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
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __SPI_H__
#define __SPI_H__

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* USER CODE BEGIN Includes */
/* USER CODE END Includes */

extern SPI_HandleTypeDef hspi1;

/* USER CODE BEGIN Private defines */
    typedef struct _SPI_Value
    {
        SPI_HandleTypeDef *hspi;
        GPIO_Value *SPI_CS;
    } SPI_Value;

    extern SPI_Value spi_encoderL;
    extern SPI_Value spi_encoderR;
    extern SPI_Value spi_imu;
/* USER CODE END Private defines */

void MX_SPI1_Init(void);

/* USER CODE BEGIN Prototypes */
    uint8_t Read_1byte(SPI_Value *spi_value, uint8_t reg, uint16_t size, uint32_t timeout);
    uint16_t Read_2byte(SPI_Value *spi_value, uint8_t reg1, uint8_t reg2, uint16_t size, uint32_t timeout);
/* USER CODE END Prototypes */

#ifdef __cplusplus
}
#endif

#endif /* __SPI_H__ */

