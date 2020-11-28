#include <msp430.h>
#include "stateMachine.h"
#include "led.h"
#include "buzzer.h"
#include "switches.h"

static char state_dim = 0;
static char select_dim = 0;

//red led will be only led blinking
char toggle_red()
{
  static char state = 0;
  switch(state){
  case 0:
    g_on = 1;
    state = 1;
    break;
  case 1:
    g_on = 0;
    state = 0;
    break;
  }
  return 1;
}

//green led will be only one blinking
char toggle_green()
{
  static char state = 0;
  switch(state){
  case 0:
    r_on = 1;
    state = 1;
    break;
  case 1:
    r_on = 0;
    state = 0;
    break;
  }
  return 1;
}

//red led blinks
char blink_red()
{
  static char state = 0;
  switch(state){
  case 0:
    g_on = 1;
    state = 1;
    break;
  case 1:
    g_on = 0;
    state = 0;
    break;
  }

  return 1;
}

//green led blinks
char blink_green()
{
 static char state = 0;
 switch(state){
 case 0:
   r_on = 1;
   state = 1;
   break;
 case 1:
   r_on = 0;
   state = 0;
   break;
 }
 
 return 1;
}

// 1/4
void dimAt25()
{
  static char state_dim = 0;
  switch(state_dim){
  case 0:
    r_on = 0;
    state_dim = 1;
    break;
  case 1:
    r_on = 0;
    state_dim = 2;
    break;
  case 2:
    r_on = 0;
    state_dim = 3;
  case 3:
    r_on = 1;
    state_dim = 0;
    break;
  }

  changed_led = 1;
  led_update();
}

// 1/2
void dimAt50()
{
  static char state_dim = 0;
  switch(state_dim){
  case 0:
    r_on = 1;
    state_dim = 1;
    break;
  case 1:
    r_on = 0;
    state_dim = 2;
    break;
  case 2:
    r_on = 1;
    state_dim = 3;
    break;
  case 3:
    r_on = 0;
    state_dim = 0;
    break;
  }

  changed_led = 1;
  led_update();
}

// 3/4
void dimAt75()
{
  static char state_dim = 0;
  switch(state_dim){
  case 0:
    r_on = 1;
    state_dim = 1;
    break;
  case 1:
    r_on = 1;
    state_dim = 2;
    break;
  case 2:
    r_on = 1;
    state_dim = 3;
    break;
  case 3:
    r_on = 0;
    state_dim = 0;
    break;
  }

  changed_led = 1;
  led_update();
}

//blinks red then green
char lights_alternate()
{
  char changed = 0;
  
  static enum {R = 0, G = 1} color = G;
  switch(color){
  case R:
    changed = blink_red();
    color = G;
    break;
  case G:
    changed = toggle_green();
    color = R;
    break;
  }

  changed_led = changed;
  led_update();
}

//dims led
char dim_lights()
{
  switch(select_dim){
  case 0:
    g_on = 0;
    changed_led = 1;
    led_update();
    select_dim = 1;
    break;
  case 1:
    dimAt25();
    dimAt25();
    dimAt25();
    dimAt25();
    select_dim = 2;
    break;
  case 2:
    dimAt50();
    dimAt50();
    select_dim = 3;
    break;
  case 3:
    dimAt75();
    dimAt75();
    dimAt75();
    dimAt75();
    select_dim = 0;
    break;
  }
  return 1;
}

//method that dictates what each button does
void state_advance()
{
  char changed = 0;
  switch(switch_state_changed){
  case 1:
    changed = blink_red();          //button1 blinks green
    break;
  case 2:
    changed = lights_alternate();   //button2 blinks red then green
    break;
  case 3:
    changed = toggle_red();         //button3 blinks red and green at same time
    changed = toggle_green();
    break;
  case 4:
    changed = dim_lights();         //button4 blinks dim red light
    break;
  }

  changed_led = changed;
  led_update();
}
