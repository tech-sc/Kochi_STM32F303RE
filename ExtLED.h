/************************************************************************************//**
 * @file ExtLED.h
 * @brief 外部回路基板LED制御API
 *
 * @author  Teru
 * @date    2019/06/19
 * @version Rev0.10
 * @par 変更履歴:
 * - Rev0.10: 2019/06/19: 新規作成.
 *
 * @copyright 2018 Emb-se.com. All rights reserved.
 */
#ifndef _ExtLED_H_
#define _ExtLED_H_

#include "stm32f3xx.h"
#include "stm32f3xx_hal.h"

/**
 * @page PAGE_ExtLED 外部回路基板LED制御.
 *
 * @section SEC1_ExtLED 外部回路基板LED制御API.
 * |APIs     |機能名称|
 * |:--------|:------ |
 * |ExtLED_init() | 外部LEDの初期設定 |
 * |ExtLED1_turnON() | 外部LED1の点灯 |
 * |ExtLED1_turnOFF() | 外部LED1の消灯 |
 * |ExtLED1_toggle() | 外部LED1のトグル出力 |
 * |ExtLED2_turnON() | 外部LED2の点灯 |
 * |ExtLED2_turnOFF() | 外部LED2の消灯 |
 * |ExtLED2_toggle() | 外部LED2のトグル出力 |
 */
/**
 * @addtogroup GROUP_ExtLED 外部回路基板LED制御.
 * @brief 外部回路基板LED制御APIを提供する.<br>
 * @details LEDはプルアップ接続される.<br>
 * @{
 */

#define ExtLED1_POPT		GPIOC
#define ExtLED1_PIN			GPIO_PIN_0
#define ExtLED2_POPT		GPIOC
#define ExtLED2_PIN			GPIO_PIN_1
#define ExtLED3_POPT		GPIOC
#define ExtLED3_PIN			GPIO_PIN_2
#define ExtLED4_POPT		GPIOC
#define ExtLED4_PIN			GPIO_PIN_3

/**
 * @brief 外部LEDの初期設定.
 *
 */
extern void ExtLED_init(void);

/**
 * @brief 外部LED1の点灯.
 *
 * LED1を点灯する.
 * @param なし.
 * @return なし.
 */
#define ExtLED1_turnON()	HAL_GPIO_WritePin( ExtLED1_POPT, ExtLED1_PIN, 0 )

/**
 * @brief 外部LED2の点灯.
 *
 * LED2を点灯する.
 * @param なし.
 * @return なし.
 */
#define ExtLED2_turnON()	HAL_GPIO_WritePin( ExtLED2_POPT, ExtLED2_PIN, 0 )

/**
 * @brief 外部LED3の点灯.
 *
 * LED3を点灯する.
 * @param なし.
 * @return なし.
 */
#define ExtLED3_turnON()	HAL_GPIO_WritePin( ExtLED3_POPT, ExtLED3_PIN, 0 )

/**
 * @brief 外部LED4の点灯.
 *
 * LED4を点灯する.
 * @param なし.
 * @return なし.
 */
#define ExtLED4_turnON()	HAL_GPIO_WritePin( ExtLED4_POPT, ExtLED4_PIN, 0 )

/**
 * @brief 外部LED1の消灯.
 *
 * LED1を消灯する.
 * @param なし.
 * @return なし.
 */
#define ExtLED1_turnOFF()	HAL_GPIO_WritePin( ExtLED1_POPT, ExtLED1_PIN, 1 )

/**
 * @brief 外部LED2の消灯.
 *
 * LED2を消灯する.
 * @param なし.
 * @return なし.
 */
#define ExtLED2_turnOFF()	HAL_GPIO_WritePin( ExtLED2_POPT, ExtLED2_PIN, 1 )

/**
 * @brief 外部LED3の消灯.
 *
 * LED3を消灯する.
 * @param なし.
 * @return なし.
 */
#define ExtLED3_turnOFF()	HAL_GPIO_WritePin( ExtLED3_POPT, ExtLED3_PIN, 1 )

/**
 * @brief 外部LED4の消灯.
 *
 * LED4を消灯する.
 * @param なし.
 * @return なし.
 */
#define ExtLED4_turnOFF()	HAL_GPIO_WritePin( ExtLED4_POPT, ExtLED4_PIN, 1 )

/**
 * @brief 外部LED1のトグル出力.
 *
 * LED1を点灯または消灯にトグルする.
 * @param なし.
 * @return なし.
 */
#define ExtLED1_toggle()	HAL_GPIO_TogglePin( ExtLED1_POPT, ExtLED1_PIN )

/**
 * @brief 外部LED2のトグル出力.
 *
 * LED2を点灯または消灯にトグルする.
 * @param なし.
 * @return なし.
 */
#define ExtLED2_toggle()	HAL_GPIO_TogglePin( ExtLED2_POPT, ExtLED2_PIN )

/**
 * @brief 外部LED3のトグル出力.
 *
 * LED3を点灯または消灯にトグルする.
 * @param なし.
 * @return なし.
 */
#define ExtLED3_toggle()	HAL_GPIO_TogglePin( ExtLED3_POPT, ExtLED3_PIN )

/**
 * @brief 外部LED4のトグル出力.
 *
 * LED4を点灯または消灯にトグルする.
 * @param なし.
 * @return なし.
 */
#define ExtLED4_toggle()	HAL_GPIO_TogglePin( ExtLED4_POPT, ExtLED4_PIN )

/**
 * @brief 外部LEDの点灯・消灯.
 */
#define ExtLED_turnON(port, pin) {						\
	if( pin == ExtLED1_PIN || pin == ExtLED2_PIN )	{	\
		HAL_GPIO_WritePin( port, pin, GPIO_PIN_RESET );	\
	}													\
}
#define ExtLED_turnOFF(port, pin) {						\
	if( pin == ExtLED1_PIN || pin == ExtLED2_PIN )	{	\
		HAL_GPIO_WritePin( port, pin, GPIO_PIN_SET );	\
	}													\
}

/**
 * @} end of addtogroup
 */
#endif // _ExtLED_H_
