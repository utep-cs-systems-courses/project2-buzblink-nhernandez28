#include <msp430.h>
#include "stateMachine.h"
#include "switches.h"
#include "buzzer.h"
#include "led.h"

void state_advance()
{
  switch(state){
  case 0:
    beep();
    break;

  case 1:
    beep1();
    redLight();
    state = 0;
    break;

  case 2:
    beep2();
    dimAndBlinking();
    state = 0;

  case 3:
    beep3();
    redLight();
    greenLight();
    state = 0;
    break;

  case 4:
    beep4();
    redThenGreen();
    state = 0;
    break;

  default:
    break;
  }
}
