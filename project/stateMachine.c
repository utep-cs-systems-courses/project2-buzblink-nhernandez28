#include <msp430.h>
#include "stateMachine.h"
#include "led.h"
#include "buzzer.h"
#include "switches.h"

static char state_dim = 0;

char toggle_red()
{
  static char state = 0;
  switch(state){
  case 0:
    red_on = 1;
    state = 1;
    break;
  case 1:
    red_on = 0;
    state = 0;
    break;
  }

  return 1;
}

char toggle_green()
{
  char changed = 0;
  
  if(red_on){
    green_on ^= 1;
    changed = 1;
  }

  return changed;
}

char state_two()
{
  static char state = 0;
  switch(state){

  case 0:
    green_on = 1;
    state = 1;
    break;
  case 1:
    green_on = 0;
    state = 0;
    break;
  }

  return 1;
}

char state_three()
{
  char changed = 0;
  static enum {R = 0, G = 1} color = G;
  
  switch(color){
  case R:
    changed = toggle_red();
    color = G;
    break;
  case G:
    changed = toggle_green();
    color = R;
    break;
  }

  led_changed = changed;
  led_update();
}

void dimAt25()
{
  switch(state_dim){
  case 0:
    red_on = 1;
    break;
  case 1:
  case 2:
  case 3:
    red_on = 0;
    break;
  default:
    state_dim = 0;
    break;
  }

  led_changed = 1;
  led_update();
}

void dimAt50()
{
  switch(state_dim){
  case 0:
  case 1:
    red_on = 1;
    break;
  case 2:
  case 3:
    red_on = 0;
    break;
  default:
    state_dim = 0;
    break;
  }

  led_changed = 1;
  led_update();
}


void dimAt75()
{
  switch(state_dim){
  case 0:
    red_on = 0;
    break;
  case 1:
  case 2:
  case 3:
    red_on = 1;
    break;
  default:
    state_dim = 0;
    break;
  }

  led_changed = 1;
  led_update();
}

char state_four()
{
  static char dim = 0;

  switch(dim){
  case 0:
    dimAt25();
    dim = 1;
    break;
  case 1:
    dimAt50();
    dim = 2;
    break;
  case 2:
    dimAt75();
    dim = 0;
    break;
  default:
    red_on = 0;
    green_on = 0;
    dim = 0;
    break;
  }
  
  return 1;
}

void state_advance()
{
  char changed = 0;
  switch(switch_state_changed){

  case 1:
    changed = toggle_red();
    break;
  case 2:
    changed = state_two();
    break;
  case 3:
    changed = state_three();
    break;
  case 4:
    changed = state_four();
    break;
  }

  led_changed = changed;
  led_update();
}
 

/*void state_advance()
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
*/
 
