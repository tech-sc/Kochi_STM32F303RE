/************************************************************************************//**
 * @file ExtSW.h
 * @brief �O����H���SW����API
 *
 * @author  Teru
 * @date    2019/06/19
 * @version Rev0.10
 * @par �ύX����:
 * - Rev0.10: 2019/06/19: �V�K�쐬.
 *
 * @copyright 2018 Emb-se.com. All rights reserved.
 */
#ifndef _ExtSW_H_
#define _ExtSW_H_

#include "stm32f3xx.h"
#include "stm32f3xx_hal.h"

/**
 * @page PAGE_ExtSW �O����H���SW����.
 *
 * @section SEC1_ExtSW �O����H���SW����API.
 * |APIs     |�@�\����|
 * |:--------|:------ |
 * |ExtSW_init() | �O��SW�̏����ݒ� |
 */
/**
 * @addtogroup GROUP_ExtSW �O����H���SW����.
 * @brief �O����H���SW����API��񋟂���.<br>
 * @details ExtSW�̓v���A�b�v�ڑ������.<br>
 * @{
 */

// TODO �������C��
#define ExtSW1_POPT			GPIOA
#define ExtSW1_PIN			GPIO_PIN_4
#define EXTI9_5_PRIORITY	5

typedef enum ExtSW {
	ExtSW1 = 0x0101,
	ExtSW2,
	MAX_ExtSW
}ExtSW;

/**
 * @brief �O���X�C�b�`�̏����ݒ�.
 */
extern void ExtSW_init(void);

/**
 * @brief SW�����ݏ���.
 */
extern void ExtSW_Handler(void);
/**
 * @} end of addtogroup
 */
#endif // _ExtSW_H_
