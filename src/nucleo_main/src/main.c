/* USER CODE BEGIN Header */
/**
    ******************************************************************************
    * @file           : main.c
    * @brief          : Main program body
    ******************************************************************************
    * @attention
    *
    * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
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
#include <stdio.h>
#include <stdlib.h>

#include "consts.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

uint8_t ascii[128][8] = {
  {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},   // U+0000 (nul)
  {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},   // U+0001
  {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},   // U+0002
  {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},   // U+0003
  {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},   // U+0004
  {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},   // U+0005
  {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},   // U+0006
  {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},   // U+0007
  {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},   // U+0008
  {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},   // U+0009
  {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},   // U+000A
  {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},   // U+000B
  {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},   // U+000C
  {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},   // U+000D
  {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},   // U+000E
  {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},   // U+000F
  {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},   // U+0010
  {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},   // U+0011
  {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},   // U+0012
  {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},   // U+0013
  {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},   // U+0014
  {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},   // U+0015
  {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},   // U+0016
  {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},   // U+0017
  {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},   // U+0018
  {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},   // U+0019
  {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},   // U+001A
  {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},   // U+001B
  {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},   // U+001C
  {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},   // U+001D
  {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},   // U+001E
  {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},   // U+001F
  {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00},   // U+0020 (space)
  {0x00, 0x00, 0x60, 0xfa, 0xfa, 0x60, 0x00, 0x00},   // U+0021 (!)
  {0x00, 0xc0, 0xc0, 0x00, 0xc0, 0xc0, 0x00, 0x00},   // U+0022 (")
  {0x28, 0xfe, 0xfe, 0x28, 0xfe, 0xfe, 0x28, 0x00},   // U+0023 (#)
  {0x24, 0x74, 0xd6, 0xd6, 0x5c, 0x48, 0x00, 0x00},   // U+0024 ($)
  {0x62, 0x66, 0x0c, 0x18, 0x30, 0x66, 0x46, 0x00},   // U+0025 (%)
  {0x0c, 0x5e, 0xf2, 0xba, 0xec, 0x5e, 0x12, 0x00},   // U+0026 (&)
  {0x20, 0xe0, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00},   // U+0027 (')
  {0x00, 0x38, 0x7c, 0xc6, 0x82, 0x00, 0x00, 0x00},   // U+0028 (()
  {0x00, 0x82, 0xc6, 0x7c, 0x38, 0x00, 0x00, 0x00},   // U+0029 ())
  {0x10, 0x54, 0x7c, 0x38, 0x38, 0x7c, 0x54, 0x10},   // U+002A (*)
  {0x10, 0x10, 0x7c, 0x7c, 0x10, 0x10, 0x00, 0x00},   // U+002B (+)
  {0x00, 0x01, 0x07, 0x06, 0x00, 0x00, 0x00, 0x00},   // U+002C (,)
  {0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x00, 0x00},   // U+002D (-)
  {0x00, 0x00, 0x06, 0x06, 0x00, 0x00, 0x00, 0x00},   // U+002E (.)
  {0x06, 0x0c, 0x18, 0x30, 0x60, 0xc0, 0x80, 0x00},   // U+002F (/)
  {0x7c, 0xfe, 0x8e, 0x9a, 0xb2, 0xfe, 0x7c, 0x00},   // U+0030 (0)
  {0x02, 0x42, 0xfe, 0xfe, 0x02, 0x02, 0x00, 0x00},   // U+0031 (1)
  {0x46, 0xce, 0x9a, 0x92, 0xf6, 0x66, 0x00, 0x00},   // U+0032 (2)
  {0x44, 0xc6, 0x92, 0x92, 0xfe, 0x6c, 0x00, 0x00},   // U+0033 (3)
  {0x18, 0x38, 0x68, 0xca, 0xfe, 0xfe, 0x0a, 0x00},   // U+0034 (4)
  {0xe4, 0xe6, 0xa2, 0xa2, 0xbe, 0x9c, 0x00, 0x00},   // U+0035 (5)
  {0x3c, 0x7e, 0xd2, 0x92, 0x9e, 0x0c, 0x00, 0x00},   // U+0036 (6)
  {0xc0, 0xc0, 0x8e, 0x9e, 0xf0, 0xe0, 0x00, 0x00},   // U+0037 (7)
  {0x6c, 0xfe, 0x92, 0x92, 0xfe, 0x6c, 0x00, 0x00},   // U+0038 (8)
  {0x60, 0xf2, 0x92, 0x96, 0xfc, 0x78, 0x00, 0x00},   // U+0039 (9)
  {0x00, 0x00, 0x66, 0x66, 0x00, 0x00, 0x00, 0x00},   // U+003A (:)
  {0x00, 0x01, 0x67, 0x66, 0x00, 0x00, 0x00, 0x00},   // U+003B (;)
  {0x10, 0x38, 0x6c, 0xc6, 0x82, 0x00, 0x00, 0x00},   // U+003C (<)
  {0x24, 0x24, 0x24, 0x24, 0x24, 0x24, 0x00, 0x00},   // U+003D (=)
  {0x00, 0x82, 0xc6, 0x6c, 0x38, 0x10, 0x00, 0x00},   // U+003E (>)
  {0x40, 0xc0, 0x8a, 0x9a, 0xf0, 0x60, 0x00, 0x00},   // U+003F (?)
  {0x7c, 0xfe, 0x82, 0xba, 0xba, 0xf8, 0x78, 0x00},   // U+0040 (@)
  {0x3e, 0x7e, 0xc8, 0xc8, 0x7e, 0x3e, 0x00, 0x00},   // U+0041 (A)
  {0x82, 0xfe, 0xfe, 0x92, 0x92, 0xfe, 0x6c, 0x00},   // U+0042 (B)
  {0x38, 0x7c, 0xc6, 0x82, 0x82, 0xc6, 0x44, 0x00},   // U+0043 (C)
  {0x82, 0xfe, 0xfe, 0x82, 0xc6, 0x7c, 0x38, 0x00},   // U+0044 (D)
  {0x82, 0xfe, 0xfe, 0x92, 0xba, 0x82, 0xc6, 0x00},   // U+0045 (E)
  {0x82, 0xfe, 0xfe, 0x92, 0xb8, 0x80, 0xc0, 0x00},   // U+0046 (F)
  {0x38, 0x7c, 0xc6, 0x82, 0x8a, 0xce, 0x4e, 0x00},   // U+0047 (G)
  {0xfe, 0xfe, 0x10, 0x10, 0xfe, 0xfe, 0x00, 0x00},   // U+0048 (H)
  {0x00, 0x82, 0xfe, 0xfe, 0x82, 0x00, 0x00, 0x00},   // U+0049 (I)
  {0x0c, 0x0e, 0x02, 0x82, 0xfe, 0xfc, 0x80, 0x00},   // U+004A (J)
  {0x82, 0xfe, 0xfe, 0x10, 0x38, 0xee, 0xc6, 0x00},   // U+004B (K)
  {0x82, 0xfe, 0xfe, 0x82, 0x02, 0x06, 0x0e, 0x00},   // U+004C (L)
  {0xfe, 0xfe, 0x70, 0x38, 0x70, 0xfe, 0xfe, 0x00},   // U+004D (M)
  {0xfe, 0xfe, 0x60, 0x30, 0x18, 0xfe, 0xfe, 0x00},   // U+004E (N)
  {0x38, 0x7c, 0xc6, 0x82, 0xc6, 0x7c, 0x38, 0x00},   // U+004F (O)
  {0x82, 0xfe, 0xfe, 0x92, 0x90, 0xf0, 0x60, 0x00},   // U+0050 (P)
  {0x78, 0xfc, 0x84, 0x8e, 0xfe, 0x7a, 0x00, 0x00},   // U+0051 (Q)
  {0x82, 0xfe, 0xfe, 0x90, 0x98, 0xfe, 0x66, 0x00},   // U+0052 (R)
  {0x64, 0xf6, 0xb2, 0x9a, 0xce, 0x4c, 0x00, 0x00},   // U+0053 (S)
  {0xc0, 0x82, 0xfe, 0xfe, 0x82, 0xc0, 0x00, 0x00},   // U+0054 (T)
  {0xfe, 0xfe, 0x02, 0x02, 0xfe, 0xfe, 0x00, 0x00},   // U+0055 (U)
  {0xf8, 0xfc, 0x06, 0x06, 0xfc, 0xf8, 0x00, 0x00},   // U+0056 (V)
  {0xfe, 0xfe, 0x0c, 0x18, 0x0c, 0xfe, 0xfe, 0x00},   // U+0057 (W)
  {0xc2, 0xe6, 0x3c, 0x18, 0x3c, 0xe6, 0xc2, 0x00},   // U+0058 (X)
  {0xe0, 0xf2, 0x1e, 0x1e, 0xf2, 0xe0, 0x00, 0x00},   // U+0059 (Y)
  {0xe2, 0xc6, 0x8e, 0x9a, 0xb2, 0xe6, 0xce, 0x00},   // U+005A (Z)
  {0x00, 0xfe, 0xfe, 0x82, 0x82, 0x00, 0x00, 0x00},   // U+005B ([)
  {0x80, 0xc0, 0x60, 0x30, 0x18, 0x0c, 0x06, 0x00},   // U+005C (\)
  {0x00, 0x82, 0x82, 0xfe, 0xfe, 0x00, 0x00, 0x00},   // U+005D (])
  {0x10, 0x30, 0x60, 0xc0, 0x60, 0x30, 0x10, 0x00},   // U+005E (^)
  {0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01},   // U+005F (_)
  {0x00, 0x00, 0xc0, 0xe0, 0x20, 0x00, 0x00, 0x00},   // U+0060 (`)
  {0x04, 0x2e, 0x2a, 0x2a, 0x3c, 0x1e, 0x02, 0x00},   // U+0061 (a)
  {0x82, 0xfe, 0xfc, 0x12, 0x12, 0x1e, 0x0c, 0x00},   // U+0062 (b)
  {0x1c, 0x3e, 0x22, 0x22, 0x36, 0x14, 0x00, 0x00},   // U+0063 (c)
  {0x0c, 0x1e, 0x12, 0x92, 0xfc, 0xfe, 0x02, 0x00},   // U+0064 (d)
  {0x1c, 0x3e, 0x2a, 0x2a, 0x3a, 0x18, 0x00, 0x00},   // U+0065 (e)
  {0x12, 0x7e, 0xfe, 0x92, 0xc0, 0x40, 0x00, 0x00},   // U+0066 (f)
  {0x19, 0x3d, 0x25, 0x25, 0x1f, 0x3e, 0x20, 0x00},   // U+0067 (g)
  {0x82, 0xfe, 0xfe, 0x10, 0x20, 0x3e, 0x1e, 0x00},   // U+0068 (h)
  {0x00, 0x22, 0xbe, 0xbe, 0x02, 0x00, 0x00, 0x00},   // U+0069 (i)
  {0x06, 0x07, 0x01, 0x01, 0xbf, 0xbe, 0x00, 0x00},   // U+006A (j)
  {0x82, 0xfe, 0xfe, 0x08, 0x1c, 0x36, 0x22, 0x00},   // U+006B (k)
  {0x00, 0x82, 0xfe, 0xfe, 0x02, 0x00, 0x00, 0x00},   // U+006C (l)
  {0x3e, 0x3e, 0x18, 0x1c, 0x38, 0x3e, 0x1e, 0x00},   // U+006D (m)
  {0x3e, 0x3e, 0x20, 0x20, 0x3e, 0x1e, 0x00, 0x00},   // U+006E (n)
  {0x1c, 0x3e, 0x22, 0x22, 0x3e, 0x1c, 0x00, 0x00},   // U+006F (o)
  {0x21, 0x3f, 0x1f, 0x25, 0x24, 0x3c, 0x18, 0x00},   // U+0070 (p)
  {0x18, 0x3c, 0x24, 0x25, 0x1f, 0x3f, 0x21, 0x00},   // U+0071 (q)
  {0x22, 0x3e, 0x1e, 0x32, 0x20, 0x38, 0x18, 0x00},   // U+0072 (r)
  {0x12, 0x3a, 0x2a, 0x2a, 0x2e, 0x24, 0x00, 0x00},   // U+0073 (s)
  {0x00, 0x20, 0x7c, 0xfe, 0x22, 0x24, 0x00, 0x00},   // U+0074 (t)
  {0x3c, 0x3e, 0x02, 0x02, 0x3c, 0x3e, 0x02, 0x00},   // U+0075 (u)
  {0x38, 0x3c, 0x06, 0x06, 0x3c, 0x38, 0x00, 0x00},   // U+0076 (v)
  {0x3c, 0x3e, 0x0e, 0x1c, 0x0e, 0x3e, 0x3c, 0x00},   // U+0077 (w)
  {0x22, 0x36, 0x1c, 0x08, 0x1c, 0x36, 0x22, 0x00},   // U+0078 (x)
  {0x39, 0x3d, 0x05, 0x05, 0x3f, 0x3e, 0x00, 0x00},   // U+0079 (y)
  {0x32, 0x26, 0x2e, 0x3a, 0x32, 0x26, 0x00, 0x00},   // U+007A (z)
  {0x10, 0x10, 0x7c, 0xee, 0x82, 0x82, 0x00, 0x00},   // U+007B ({)
  {0x00, 0x00, 0x00, 0xee, 0xee, 0x00, 0x00, 0x00},   // U+007C (|)
  {0x82, 0x82, 0xee, 0x7c, 0x10, 0x10, 0x00, 0x00},   // U+007D (})
  {0x40, 0xc0, 0x80, 0xc0, 0x40, 0xc0, 0x80, 0x00},   // U+007E (~)
  {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}    // U+007F
};
/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
GPIO_TypeDef *led_port[] = {GPIOA, GPIOB, GPIOB, GPIOB, GPIOB, GPIOA, GPIOA, GPIOB};
uint16_t led_pin[] = {GPIO_PIN_12, GPIO_PIN_0, GPIO_PIN_7, GPIO_PIN_6, GPIO_PIN_1, GPIO_PIN_8, GPIO_PIN_11, GPIO_PIN_5};


/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
I2C_HandleTypeDef hi2c1;

TIM_HandleTypeDef htim1;
TIM_HandleTypeDef htim2;

UART_HandleTypeDef huart2;

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_TIM1_Init(void);
static void MX_USART2_UART_Init(void);
static void MX_TIM2_Init(void);
static void MX_I2C1_Init(void);
/* USER CODE BEGIN PFP */
/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
uint8_t *screen, *i2c_buff;
uint8_t buff1[N_SECTOR];
uint8_t buff2[N_SECTOR];
uint8_t i2c_str[25];
int cur_sector;
long ir_new, ir_prev, ir_time;
char flip;

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim) {
  if (htim == &htim1) {
    int i;
    for (i = 0; i < N_LED; i++) {
      HAL_GPIO_WritePin(led_port[i], led_pin[i], (screen[cur_sector] >> i) & 1 ? GPIO_PIN_SET : GPIO_PIN_RESET);
    }
    cur_sector++;
    if (cur_sector == N_SECTOR - 1) {
      HAL_TIM_Base_Stop_IT(&htim1);
    }
  }
}

void HAL_TIM_IC_CaptureCallback(TIM_HandleTypeDef *htim) {
  if (htim == &htim2) {
    ir_new = HAL_TIM_ReadCapturedValue(&htim2, TIM_CHANNEL_1);
    // debounce HAL sensor
    if (abs(ir_new - ir_prev) > DEBOUNCE) {
      if (ir_prev < ir_new) { // in case counter overflows between captures
        ir_time = (__HAL_TIM_GET_AUTORELOAD(&htim2) - ir_prev) + ir_new;
      } else {
        ir_time = ir_new - ir_prev;
      }
      ir_prev = ir_new;
      __HAL_TIM_SET_AUTORELOAD(&htim1, ir_time/N_SECTOR);
      HAL_TIM_Base_Start_IT(&htim1);
      __HAL_TIM_SET_COUNTER(&htim1, 0);
      cur_sector = 0;
      if (flip) {
        uint8_t *tmp = screen;
        screen = i2c_buff;
        i2c_buff = tmp;
        flip = 0;
      }
    }
  }
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
  MX_TIM1_Init();
  MX_USART2_UART_Init();
  MX_TIM2_Init();
  MX_I2C1_Init();
  /* USER CODE BEGIN 2 */
  ir_new = 0;
  ir_prev = 0;
  ir_time = 0;
  cur_sector = 0;
  flip = 0;
  screen = buff1;
  i2c_buff = buff2;
  HAL_TIM_Base_Start_IT(&htim1);
  HAL_TIM_IC_Start_IT(&htim2, TIM_CHANNEL_1);
  __HAL_TIM_SET_CAPTUREPOLARITY(&htim2, TIM_CHANNEL_1, TIM_INPUTCHANNELPOLARITY_FALLING);
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  char txt[] = "Go Visit the WebPage!";

	int i;
  int j;
  int cnt = 0;
  for (i = 0; i < sizeof(txt); i++)
  {
    for(j = 0; j < CHAR_W; j++)
    {
      screen[cnt++] = ascii[(uint8_t)txt[i]][j];
    }
  }

  while (1)
  {
    if (HAL_I2C_Slave_Receive(&hi2c1, i2c_str, 25, HAL_MAX_DELAY) == HAL_OK) {
      HAL_UART_Transmit(&huart2, i2c_str, sizeof(i2c_str), HAL_MAX_DELAY);
      cnt = 0;
      for (i = 0; i < 25; i++)
      {
        for(j = 0; j < CHAR_W; j++)
        {
          i2c_buff[cnt++] = ascii[(uint8_t)i2c_str[i]][j];
        }
      }
      flip = 0xFF;
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
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_MSI;
  RCC_OscInitStruct.MSIState = RCC_MSI_ON;
  RCC_OscInitStruct.MSICalibrationValue = 0;
  RCC_OscInitStruct.MSIClockRange = RCC_MSIRANGE_6;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_MSI;
  RCC_OscInitStruct.PLL.PLLM = 1;
  RCC_OscInitStruct.PLL.PLLN = 40;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV7;
  RCC_OscInitStruct.PLL.PLLQ = RCC_PLLQ_DIV2;
  RCC_OscInitStruct.PLL.PLLR = RCC_PLLR_DIV2;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_4) != HAL_OK)
  {
    Error_Handler();
  }
  PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_USART2|RCC_PERIPHCLK_I2C1;
  PeriphClkInit.Usart2ClockSelection = RCC_USART2CLKSOURCE_PCLK1;
  PeriphClkInit.I2c1ClockSelection = RCC_I2C1CLKSOURCE_PCLK1;
  if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit) != HAL_OK)
  {
    Error_Handler();
  }
  /** Configure the main internal regulator output voltage
  */
  if (HAL_PWREx_ControlVoltageScaling(PWR_REGULATOR_VOLTAGE_SCALE1) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief I2C1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_I2C1_Init(void)
{

  /* USER CODE BEGIN I2C1_Init 0 */

  /* USER CODE END I2C1_Init 0 */

  /* USER CODE BEGIN I2C1_Init 1 */

  /* USER CODE END I2C1_Init 1 */
  hi2c1.Instance = I2C1;
  hi2c1.Init.Timing = 0x10909CEC;
  hi2c1.Init.OwnAddress1 = 148;
  hi2c1.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
  hi2c1.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
  hi2c1.Init.OwnAddress2 = 0;
  hi2c1.Init.OwnAddress2Masks = I2C_OA2_NOMASK;
  hi2c1.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
  hi2c1.Init.NoStretchMode = I2C_NOSTRETCH_DISABLE;
  if (HAL_I2C_Init(&hi2c1) != HAL_OK)
  {
    Error_Handler();
  }
  /** Configure Analogue filter
  */
  if (HAL_I2CEx_ConfigAnalogFilter(&hi2c1, I2C_ANALOGFILTER_ENABLE) != HAL_OK)
  {
    Error_Handler();
  }
  /** Configure Digital filter
  */
  if (HAL_I2CEx_ConfigDigitalFilter(&hi2c1, 0) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN I2C1_Init 2 */

  /* USER CODE END I2C1_Init 2 */

}

/**
  * @brief TIM1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM1_Init(void)
{

  /* USER CODE BEGIN TIM1_Init 0 */

  /* USER CODE END TIM1_Init 0 */

  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};

  /* USER CODE BEGIN TIM1_Init 1 */

  /* USER CODE END TIM1_Init 1 */
  htim1.Instance = TIM1;
  htim1.Init.Prescaler = 79;
  htim1.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim1.Init.Period = 65535;
  htim1.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim1.Init.RepetitionCounter = 0;
  htim1.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim1) != HAL_OK)
  {
    Error_Handler();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim1, &sClockSourceConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterOutputTrigger2 = TIM_TRGO2_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim1, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM1_Init 2 */

  /* USER CODE END TIM1_Init 2 */

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
  TIM_IC_InitTypeDef sConfigIC = {0};

  /* USER CODE BEGIN TIM2_Init 1 */

  /* USER CODE END TIM2_Init 1 */
  htim2.Instance = TIM2;
  htim2.Init.Prescaler = 79;
  htim2.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim2.Init.Period = 4294967295;
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
  if (HAL_TIM_IC_Init(&htim2) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim2, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sConfigIC.ICPolarity = TIM_INPUTCHANNELPOLARITY_RISING;
  sConfigIC.ICSelection = TIM_ICSELECTION_DIRECTTI;
  sConfigIC.ICPrescaler = TIM_ICPSC_DIV1;
  sConfigIC.ICFilter = 0;
  if (HAL_TIM_IC_ConfigChannel(&htim2, &sConfigIC, TIM_CHANNEL_1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM2_Init 2 */

  /* USER CODE END TIM2_Init 2 */

}

/**
  * @brief USART2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_USART2_UART_Init(void)
{

  /* USER CODE BEGIN USART2_Init 0 */

  /* USER CODE END USART2_Init 0 */

  /* USER CODE BEGIN USART2_Init 1 */

  /* USER CODE END USART2_Init 1 */
  huart2.Instance = USART2;
  huart2.Init.BaudRate = 115200;
  huart2.Init.WordLength = UART_WORDLENGTH_8B;
  huart2.Init.StopBits = UART_STOPBITS_1;
  huart2.Init.Parity = UART_PARITY_NONE;
  huart2.Init.Mode = UART_MODE_TX_RX;
  huart2.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart2.Init.OverSampling = UART_OVERSAMPLING_16;
  huart2.Init.OneBitSampling = UART_ONE_BIT_SAMPLE_DISABLE;
  huart2.AdvancedInit.AdvFeatureInit = UART_ADVFEATURE_NO_INIT;
  if (HAL_UART_Init(&huart2) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART2_Init 2 */

  /* USER CODE END USART2_Init 2 */

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
  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_5|GPIO_PIN_6
                          |GPIO_PIN_7, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8|GPIO_PIN_11|GPIO_PIN_12, GPIO_PIN_RESET);

  /*Configure GPIO pins : PB0 PB1 PB5 PB6
                           PB7 */
  GPIO_InitStruct.Pin = GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_5|GPIO_PIN_6
                          |GPIO_PIN_7;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pins : PA8 PA11 PA12 */
  GPIO_InitStruct.Pin = GPIO_PIN_8|GPIO_PIN_11|GPIO_PIN_12;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

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
