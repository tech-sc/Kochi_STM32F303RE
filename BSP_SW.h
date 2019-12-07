#ifndef _BSP_SW_H_
#define _BSP_SW_H_
#include "stm32f3xx_hal.h"

#define B1_Pin GPIO_PIN_13
#define B1_GPIO_Port GPIOC

#define LED00_Port GPIOC
#define LED00_Pin GPIO_PIN_0
#define LED01_Port GPIOC
#define LED01_Pin GPIO_PIN_1
#define LED02_Port GPIOC
#define LED02_Pin GPIO_PIN_2
#define LED03_Port GPIOC
#define LED03_Pin GPIO_PIN_3

#define SW_Pin GPIO_PIN_4
#define SW_GPIO_Port GPIOA
#define LD2_Pin GPIO_PIN_5
#define LD2_GPIO_Port GPIOC

#define LED00_toggle()        HAL_GPIO_TogglePin( LED00_Port, LED00_Pin )
#define LED01_toggle()        HAL_GPIO_TogglePin( LED01_Port, LED01_Pin )
#define LED02_toggle()        HAL_GPIO_TogglePin( LED02_Port, LED02_Pin )
#define LED03_toggle()        HAL_GPIO_TogglePin( LED03_Port, LED03_Pin )

extern void BSPSW_init(void);

typedef enum SW_STATE {
 SW_OFF = 0,
 SW_ON,
} SW_STATE;

inline static SW_STATE BSPSW_read(void)
{
return HAL_GPIO_ReadPin(B1_GPIO_Port, B1_Pin) == 0 ? SW_ON : SW_OFF;
} 
#endif //_BSP_SW_H_ 