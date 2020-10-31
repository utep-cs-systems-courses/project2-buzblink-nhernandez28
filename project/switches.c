#include <msp430.h>
#include "switches.h"
#include "led.h"

chat state, switch_state_down, switch_state_changed;

static char switch_update_interrupt_sense()
{
  P2IES |= (p2val & SWITCHES);
  P2IES &= (p2val | ~SWITCHES);
  return p2val;
}

void switch_init()
{
  P2REN |= SWITCHES;
  P2IE |= SWITCHES;
  P2OUT |= SWITCHES;
  P2DIR &= ~SWITCHES;

  switch_update_interrupt_sense();
  switch_interrupt_handler();
}

void switch_interrupt_handler()
{
  char p2val = switch_update_interrupt_sense();
  if(p2val & SW1 ? 0 : 1){
    state = 1;
  }
  else if(p2val & SW2 ? 0 : 1){
    state = 2;
  }
  else if(p2val & SW3 ? 0 : 1){
    state = 3;
  }
  else if(p2val & SW4 ? 0 : 1){
    state = 4;
  }

  state_advance();
}
