/************************************************************************************//**
 * @file BSP_LED.h
 * @brief BluePill�I���{�[�hLED����API
 *
 * @author  Teru
 * @date    2018/12/24
 * @version Rev0.10
 * @par �ύX����:
 * - Rev0.10: 2018/12/24: �V�K�쐬
 *
 * @copyright 2018 Emb-se.com. All rights reserved.
 */
#ifndef _BSP_LED_H_
#define _BSP_LED_H_

#include "stm32f3xx.h"
#include "stm32f3xx_hal.h"

/**
 * @page PAGE_BSP_LED BluePill�I���{�[�h
 *
 * @section SEC1_BluePill_LED BluePill�I���{�[�hLED����API
 * |APIs     |�@�\����|
 * |:--------|:------ |
 * |BSP_LED_init() | �I���{�[�hLED�̏����ݒ� |
 * |BSP_LED_turnON() | �I���{�[�hLED�̓_�� |
 * |BSP_LED_turnOFF() | �I���{�[�hLED�̏��� |
 * |BSP_LED_toggle() | �I���{�[�hLED�̃g�O���o�� |
 */
/**
 * @addtogroup GROUP_BSP_LED BluePill�I���{�[�hLED����
 * @brief BluePill�I���{�[�hLED����API��񋟂���B<br>
 * @details LED�́APC13�Ƀv���A�b�v�ڑ������B<br>
 * @{
 */

#define LED_POPT		GPIOC
#define LED_PIN			GPIO_PIN_13

/**
 * @brief �I���{�[�hLED�̏����ݒ�.
 */
extern void BSP_LED_init(void);

/**
 * @brief �I���{�[�hLED�̓_��.
 *
 * LED��_������.
 * @param �Ȃ�.
 * @return �Ȃ�.
 */
#define BSP_LED_turnON()		HAL_GPIO_WritePin( LED_POPT, LED_PIN, GPIO_PIN_RESET )

/**
 * @brief �I���{�[�hLED�̏���.
 *
 * LED����������.
 * @param �Ȃ�.
 * @return �Ȃ�.
 */
#define BSP_LED_turnOFF()		HAL_GPIO_WritePin( LED_POPT, LED_PIN, GPIO_PIN_SET )

/**
 * @brief �I���{�[�hLED�̃g�O���o��.
 *
 * LED��_���܂��͏����Ƀg�O������.
 * @param �Ȃ�.
 * @return �Ȃ�.
 */
#define BSP_LED_toggle()		HAL_GPIO_TogglePin( LED_POPT, LED_PIN )

/**
 * @} end of addtogroup
 */

#endif //_BSP_LED_H_
