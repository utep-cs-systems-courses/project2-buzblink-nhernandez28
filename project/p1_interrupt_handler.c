#include <msp430.h>
#include "switches.h"

void __interrupt_vec(PORT2_VECTOR) Port_2(){
  if(P2IFG & SWITCHES){         //if button cause interrupt
    P2IFG &= ~SWITCHES;         //will clear sw interrupt
    switch_interrupt_handler();      //handler for all switches
  }
}
