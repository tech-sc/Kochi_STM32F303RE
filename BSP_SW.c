#include "BSP_SW.h"
#include "ExtLED.h"

// ボタン押した回数カウンタ
int counter = 0;

void BSPSW_init(void)
{
 // GPIO_InitTypeDef GPIO_InitStruct = {0};

 /* GPIO Ports Clock Enable */
__HAL_RCC_GPIOA_CLK_ENABLE();
__HAL_RCC_GPIOC_CLK_ENABLE();
 
} 

void BSPSW_countLED(void)
{
  // カウンタに1足す
  counter += 1;
  
  // カウンタが16なら0に戻す
  if ( counter & 0x10 )
  {
   counter = 0x00;
  }
  
  // カウンタの値をAND演算子で比較(1)
  if ( counter & 0x01 ) 
  {
   // on
   ExtLED1_turnON();
  } else
  {
   // off
   ExtLED1_turnOFF();
  }
    
  // カウンタの値をAND演算子で比較(2)
  if ( counter & 0x02 ) 
  {
   // on
   ExtLED2_turnON();
  } else
  {
   // off
   ExtLED2_turnOFF();
  }
  
  // カウンタの値をAND演算子で比較(3)
  if ( counter & 0x04 ) 
  {
   // on
   ExtLED3_turnON();
  } else
  {
   // off
   ExtLED3_turnOFF();
  }
  
  // カウンタの値をAND演算子で比較(4)
  if ( counter & 0x08 ) 
  {
   // off
   ExtLED4_turnON();
  } else
  {
   // on
   ExtLED4_turnOFF();
  }
}