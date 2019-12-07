/************************************************************************************//**
 * @file ExtLED.c
 * @brief �O����H���(External Print Circuit Board)LED����API
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
 * @addtogroup GROUP_ExtLED
 * @{
 */
#include "ExtLED.h"

/**
 * @brief �O��LED�̏����ݒ�.
 *
 * LED1,LED2�̓v���A�b�v�ݒ��Ainactive(1)�ŏ���������.
 * @param �Ȃ�.
 * @return �Ȃ�.
 */
void ExtLED_init(void)
{
	GPIO_InitTypeDef GPIO_InitStruct = {0};

	/* GPIO Ports Clock Enable */
	if( __HAL_RCC_GPIOB_IS_CLK_DISABLED() ) {
		__HAL_RCC_GPIOB_CLK_ENABLE();
	}

	/** @li ExtLED1�����ݒ� */
	ExtLED1_turnOFF();

	/* Configure GPIO pin */
	GPIO_InitStruct.Pin   = ExtLED1_PIN;
	GPIO_InitStruct.Mode  = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull  = GPIO_PULLUP;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init( ExtLED1_POPT, &GPIO_InitStruct );

	/** @li ExtLED2�����ݒ� */
	ExtLED2_turnOFF();

	/* Configure GPIO pin */
	GPIO_InitStruct.Pin   = ExtLED2_PIN;
	GPIO_InitStruct.Mode  = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull  = GPIO_PULLUP;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init( ExtLED2_POPT, &GPIO_InitStruct );
        
        /** @li ExtLED3�����ݒ� */
	ExtLED3_turnOFF();

	/* Configure GPIO pin */
	GPIO_InitStruct.Pin   = ExtLED3_PIN;
	GPIO_InitStruct.Mode  = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull  = GPIO_PULLUP;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init( ExtLED3_POPT, &GPIO_InitStruct );
        
        /** @li ExtLED4�����ݒ� */
	ExtLED4_turnOFF();

	/* Configure GPIO pin */
	GPIO_InitStruct.Pin   = ExtLED4_PIN;
	GPIO_InitStruct.Mode  = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull  = GPIO_PULLUP;
	GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init( ExtLED4_POPT, &GPIO_InitStruct );
}

/**
 * @} end of addtogroup
 */
