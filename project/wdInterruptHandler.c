#include <msp430.h>
#include "stateMachine.h"
#include "switches.c"
#include "led.h"
#include "buzzer.h"

char switch_state_changed();

void __interrupt_vecc(WDT_VECTOR) WDT()
{
  //250 interrupts/sec
  static char count_blink = 0;
  
  if(switch_state_changed == 4){
    switch(switch_state_changed){
    case 4:
      if(++count_blink < 62){
	dimAt25();
      }else if(++count_blink < 125){
	dimAt50();
      }else if(++count_blink == 250){
	dimAt75();
	dim_light();
      }
      
      break;
    }
    
    if(++count_blink == 125){
      state_advance();
      count_blink = 0;
    }
  }
}
