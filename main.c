/************************************************************************************//**
 * @file    main.c
 * @brief   STM32F303RE STM32Nucleo
 *
 * @mainpage STM32Nucleo STM32F303RE 向けプロジェクト
 * @brief   組込みシステム技術会合用プロジェクトである.<br>
 *
 * @details STM32CubeF3ライブラリを使用して実装する.<br>
 *
 * @par 変更履歴:
 *	Rev0.01　2019/06/02　テンプレート作成<br>
 * @par Copyright
 *	2014-19 Emb-se.com All rights reserved.
 */
#include <stdio.h>
#include "stm32f3xx.h"
#include "BSP_SW.h"
#include "task.h"


/************************************************************************************//**
 * @brief   プログラムメイン
 * @param   None
 * @retval  None
 */
   
// プロトタイプ宣言
static void MX_GPIO_Init(void);
   
void main( void )
{
        /* Initialize all configured peripherals */
        MX_GPIO_Init();
        
	vTaskStartScheduler();
        while(1);
}

static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  
  /*Configure GPIO pin : B1_Pin */
  GPIO_InitStruct.Pin = B1_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_FALLING;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(B1_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : LED00_Pin LED01_Pin LED02_Pin LED03_Pin */
  GPIO_InitStruct.Pin = LED00_Pin|LED01_Pin|LED02_Pin|LED03_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pin : SW_Pin */
  GPIO_InitStruct.Pin = SW_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_FALLING;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  HAL_GPIO_Init(SW_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : LD2_Pin */
  GPIO_InitStruct.Pin = LD2_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(LD2_GPIO_Port, &GPIO_InitStruct);

  // 割り込みの許可
  /* EXTI4_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(EXTI4_IRQn, 0, 0); // 割込み優先度設定（省略可能）
  HAL_NVIC_EnableIRQ(EXTI4_IRQn); // 割込み許可設定 

}

  // 割り込みの中身
  void EXTI4_IRQHandler(void)
{
 if(__HAL_GPIO_EXTI_GET_IT(B1_Pin) != 0) // 対象ポート判定
 {
 __HAL_GPIO_EXTI_CLEAR_IT(B1_Pin); // 割込み要因クリア
 
  //TODO LED点灯、消灯のトグル処理
  /**
    * @brief SW割込み処理.
    *
    * 立下り(active)または立上がり(inactive)エッジ割込みを処理する.
    * @param なし.
    * @return なし.
    */
    inline void ExtSW_Handler(void)
    {
	/* EXTI line interrupt detected */
	if( __HAL_GPIO_EXTI_GET_IT(SW_Pin) ) {
		__HAL_GPIO_EXTI_CLEAR_IT( SW_Pin );
		if( HAL_GPIO_ReadPin( SW_Port, SW_Pin ) == GPIO_PIN_SET ) {
                        //TODO inactive時の処理
			//ExtSW_inactiveHandler( ExtSW1 );
		} else {
                        //TODO active時の処理
			//ExtSW_activeHandler( ExtSW1 );
		}
	}
}
 
 }
}