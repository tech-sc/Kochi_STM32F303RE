/************************************************************************************//**
 * @file ExtSW.c
 * @brief �O����H���(External Print Circuit Board)SW����API
 *
 * @author  Teru
 * @date    2019/06/19
 * @version Rev0.10
 * @par �ύX����:
 * - Rev0.10: 2019/06/19: �V�K�쐬.
 *
 * @copyright 2018 Emb-se.com. All rights reserved.
 */
/**
 * @addtogroup GROUP_ExtSW �O����H���LED����.
 * @{
 */
#include "ExtLED.h"
#include "ExtSW.h"

/**
 * @brief �O��SW�̏����ݒ�.
 *
 * SW�̓v���A�b�v�ŏ����ݒ肷��.
 * @param �Ȃ�.
 * @return �Ȃ�.
 */
void ExtSW_init(void)
{
	GPIO_InitTypeDef GPIO_InitStruct = {0};

	/* GPIO Ports Clock Enable */
	if( __HAL_RCC_GPIOA_IS_CLK_DISABLED() ) {
		__HAL_RCC_GPIOA_CLK_ENABLE();
	}

	/** @li ExtSW1�����ݒ� */
	/* Configure GPIO pin */
	GPIO_InitStruct.Pin   = ExtSW1_PIN;
	GPIO_InitStruct.Mode  = GPIO_MODE_IT_RISING_FALLING;
	GPIO_InitStruct.Pull  = GPIO_PULLUP;
	HAL_GPIO_Init( ExtSW1_POPT, &GPIO_InitStruct );

	/** @li EXTI[9:5]�����݂̐ݒ� */
	/* EXTI line[9:5] interrupt init */
	HAL_NVIC_SetPriority( EXTI9_5_IRQn, EXTI9_5_PRIORITY, 0 );
	HAL_NVIC_EnableIRQ( EXTI9_5_IRQn );
}

/**
 * @brief SW��ԏ��������݃n���h��.
 *
 * ������(active)�G�b�W�����ݎ��ɃR�[�������.
 * @param[in] sw_no Active��Ԃɕω������X�C�b�`�ԍ�.
 * @return �Ȃ�.
 */
__weak void ExtSW_activeHandler( ExtSW sw_no )
{
}

/**
 * @brief SW��ԏ��������݃n���h��.
 *
 * ���オ��(inactive)�G�b�W�����ݎ��ɃR�[�������.
 * @param[in] sw_no Inactive��Ԃɕω������X�C�b�`�ԍ�.
 * @return �Ȃ�.
 */
__weak void ExtSW_inactiveHandler( ExtSW sw_no )
{
}

/**
 * @brief SW�����ݏ���.
 *
 * ������(active)�܂��͗��オ��(inactive)�G�b�W�����݂���������.
 * @param �Ȃ�.
 * @return �Ȃ�.
 */
inline void ExtSW_Handler(void)
{
	/* EXTI line interrupt detected */
	if( __HAL_GPIO_EXTI_GET_IT(ExtSW1_PIN) ) {
		__HAL_GPIO_EXTI_CLEAR_IT( ExtSW1_PIN );
		if( HAL_GPIO_ReadPin( ExtSW1_POPT, ExtSW1_PIN ) == GPIO_PIN_SET ) {
			ExtSW_inactiveHandler( ExtSW1 );
		} else {
			ExtSW_activeHandler( ExtSW1 );
		}
	}
}

/**
 * @} end of addtogroup
 */
