/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
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
#include "stm32l4xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include <stdio.h>

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */
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
#define MCO_Pin GPIO_PIN_0
#define MCO_GPIO_Port GPIOA
#define Setting_Button_1_Pin GPIO_PIN_1
#define Setting_Button_1_GPIO_Port GPIOA
#define Setting_Button_2_Pin GPIO_PIN_2
#define Setting_Button_2_GPIO_Port GPIOA
#define L1___Pin GPIO_PIN_3
#define L1___GPIO_Port GPIOA
#define L1__A4_Pin GPIO_PIN_4
#define L1__A4_GPIO_Port GPIOA
#define Zero_Crossing_Pin GPIO_PIN_5
#define Zero_Crossing_GPIO_Port GPIOA
#define Phase_Reached_Pin GPIO_PIN_6
#define Phase_Reached_GPIO_Port GPIOA
#define Start_Button_Pin GPIO_PIN_7
#define Start_Button_GPIO_Port GPIOA
#define Encoder_CLK_Pin GPIO_PIN_8
#define Encoder_CLK_GPIO_Port GPIOA
#define Encoder_DT_Pin GPIO_PIN_9
#define Encoder_DT_GPIO_Port GPIOA
#define OLED_SDA_Pin GPIO_PIN_10
#define OLED_SDA_GPIO_Port GPIOA
#define GateUnit_Pin GPIO_PIN_11
#define GateUnit_GPIO_Port GPIOA
#define SWDIO_Pin GPIO_PIN_13
#define SWDIO_GPIO_Port GPIOA
#define SWCLK_Pin GPIO_PIN_14
#define SWCLK_GPIO_Port GPIOA
#define LD3_Pin GPIO_PIN_3
#define LD3_GPIO_Port GPIOB
#define Encoder_SW_Pin GPIO_PIN_4
#define Encoder_SW_GPIO_Port GPIOB
#define OLED_SCK_Pin GPIO_PIN_6
#define OLED_SCK_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
