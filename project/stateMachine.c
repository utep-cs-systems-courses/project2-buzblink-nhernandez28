#include <msp430.h>
#include "stateMachine.h"
#include "switches.h"
#include "buzzer.h"
#include "led.h"

// this method is used as a state machine for our project
// each case is dictated by which button is pressed from our switches.c file

void state_advance(){
  switch(state){
  case 0:
    beep();
    break;

  case 1:
    marioSong();
    greenLight();
    state = 0;
    break;

  case 2:
    randomSong();
    dimAndBlinking();
    state = 0;
    break;

  case 3:
    nokiaSong();
    redLight();
    greenLight();
    state = 0;
    break;

  case 4:
    spongebobSong();
    redThenGreen();
    state = 0;
    break;

  default:
    break;
  }
}
