#include "BSP_SW.h"
#include "ExtLED.h"

// �{�^���������񐔃J�E���^
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
  // �J�E���^��1����
  counter += 1;
  
  // �J�E���^��16�Ȃ�0�ɖ߂�
  if ( counter & 0x10 )
  {
   counter = 0x00;
  }
  
  // �J�E���^�̒l��AND���Z�q�Ŕ�r(1)
  if ( counter & 0x01 ) 
  {
   // on
   ExtLED1_turnON();
  } else
  {
   // off
   ExtLED1_turnOFF();
  }
    
  // �J�E���^�̒l��AND���Z�q�Ŕ�r(2)
  if ( counter & 0x02 ) 
  {
   // on
   ExtLED2_turnON();
  } else
  {
   // off
   ExtLED2_turnOFF();
  }
  
  // �J�E���^�̒l��AND���Z�q�Ŕ�r(3)
  if ( counter & 0x04 ) 
  {
   // on
   ExtLED3_turnON();
  } else
  {
   // off
   ExtLED3_turnOFF();
  }
  
  // �J�E���^�̒l��AND���Z�q�Ŕ�r(4)
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