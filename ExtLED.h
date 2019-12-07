/************************************************************************************//**
 * @file ExtLED.h
 * @brief �O����H���LED����API
 *
 * @author  Teru
 * @date    2019/06/19
 * @version Rev0.10
 * @par �ύX����:
 * - Rev0.10: 2019/06/19: �V�K�쐬.
 *
 * @copyright 2018 Emb-se.com. All rights reserved.
 */
#ifndef _ExtLED_H_
#define _ExtLED_H_

#include "stm32f3xx.h"
#include "stm32f3xx_hal.h"

/**
 * @page PAGE_ExtLED �O����H���LED����.
 *
 * @section SEC1_ExtLED �O����H���LED����API.
 * |APIs     |�@�\����|
 * |:--------|:------ |
 * |ExtLED_init() | �O��LED�̏����ݒ� |
 * |ExtLED1_turnON() | �O��LED1�̓_�� |
 * |ExtLED1_turnOFF() | �O��LED1�̏��� |
 * |ExtLED1_toggle() | �O��LED1�̃g�O���o�� |
 * |ExtLED2_turnON() | �O��LED2�̓_�� |
 * |ExtLED2_turnOFF() | �O��LED2�̏��� |
 * |ExtLED2_toggle() | �O��LED2�̃g�O���o�� |
 */
/**
 * @addtogroup GROUP_ExtLED �O����H���LED����.
 * @brief �O����H���LED����API��񋟂���.<br>
 * @details LED�̓v���A�b�v�ڑ������.<br>
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
 * @brief �O��LED�̏����ݒ�.
 *
 */
extern void ExtLED_init(void);

/**
 * @brief �O��LED1�̓_��.
 *
 * LED1��_������.
 * @param �Ȃ�.
 * @return �Ȃ�.
 */
#define ExtLED1_turnON()	HAL_GPIO_WritePin( ExtLED1_POPT, ExtLED1_PIN, 0 )

/**
 * @brief �O��LED2�̓_��.
 *
 * LED2��_������.
 * @param �Ȃ�.
 * @return �Ȃ�.
 */
#define ExtLED2_turnON()	HAL_GPIO_WritePin( ExtLED2_POPT, ExtLED2_PIN, 0 )

/**
 * @brief �O��LED3�̓_��.
 *
 * LED3��_������.
 * @param �Ȃ�.
 * @return �Ȃ�.
 */
#define ExtLED3_turnON()	HAL_GPIO_WritePin( ExtLED3_POPT, ExtLED3_PIN, 0 )

/**
 * @brief �O��LED4�̓_��.
 *
 * LED4��_������.
 * @param �Ȃ�.
 * @return �Ȃ�.
 */
#define ExtLED4_turnON()	HAL_GPIO_WritePin( ExtLED4_POPT, ExtLED4_PIN, 0 )

/**
 * @brief �O��LED1�̏���.
 *
 * LED1����������.
 * @param �Ȃ�.
 * @return �Ȃ�.
 */
#define ExtLED1_turnOFF()	HAL_GPIO_WritePin( ExtLED1_POPT, ExtLED1_PIN, 1 )

/**
 * @brief �O��LED2�̏���.
 *
 * LED2����������.
 * @param �Ȃ�.
 * @return �Ȃ�.
 */
#define ExtLED2_turnOFF()	HAL_GPIO_WritePin( ExtLED2_POPT, ExtLED2_PIN, 1 )

/**
 * @brief �O��LED3�̏���.
 *
 * LED3����������.
 * @param �Ȃ�.
 * @return �Ȃ�.
 */
#define ExtLED3_turnOFF()	HAL_GPIO_WritePin( ExtLED3_POPT, ExtLED3_PIN, 1 )

/**
 * @brief �O��LED4�̏���.
 *
 * LED4����������.
 * @param �Ȃ�.
 * @return �Ȃ�.
 */
#define ExtLED4_turnOFF()	HAL_GPIO_WritePin( ExtLED4_POPT, ExtLED4_PIN, 1 )

/**
 * @brief �O��LED1�̃g�O���o��.
 *
 * LED1��_���܂��͏����Ƀg�O������.
 * @param �Ȃ�.
 * @return �Ȃ�.
 */
#define ExtLED1_toggle()	HAL_GPIO_TogglePin( ExtLED1_POPT, ExtLED1_PIN )

/**
 * @brief �O��LED2�̃g�O���o��.
 *
 * LED2��_���܂��͏����Ƀg�O������.
 * @param �Ȃ�.
 * @return �Ȃ�.
 */
#define ExtLED2_toggle()	HAL_GPIO_TogglePin( ExtLED2_POPT, ExtLED2_PIN )

/**
 * @brief �O��LED3�̃g�O���o��.
 *
 * LED3��_���܂��͏����Ƀg�O������.
 * @param �Ȃ�.
 * @return �Ȃ�.
 */
#define ExtLED3_toggle()	HAL_GPIO_TogglePin( ExtLED3_POPT, ExtLED3_PIN )

/**
 * @brief �O��LED4�̃g�O���o��.
 *
 * LED4��_���܂��͏����Ƀg�O������.
 * @param �Ȃ�.
 * @return �Ȃ�.
 */
#define ExtLED4_toggle()	HAL_GPIO_TogglePin( ExtLED4_POPT, ExtLED4_PIN )

/**
 * @brief �O��LED�̓_���E����.
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
