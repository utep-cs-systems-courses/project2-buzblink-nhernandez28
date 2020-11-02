#include <msp430.h>
#include "led.h"
#include "switches.h"
#include "buzzer.h"
#include "stateMachine.h"

void led_init()
{
  P1DIR |= LEDS;
 switch_state_changed = 1;
}

//makes green led blink
void greenLight(){
  for(int i = 0; i < 10; i++){
    P1OUT = LED_GREEN;         // will turn green led on
    __delay_cycles(700000);    // delays program

    P1OUT = !LED_GREEN;        // will turn green led off
    __delay_cycles(700000);
  }
}

//makes red led blink
void redLight(){
   for(int i = 0; i < 10; i++){
    P1OUT = LED_RED;           // will turn re led on
    __delay_cycles(850000);    // delays program

    P1OUT = !LED_RED;          // will turn red led off
    __delay_cycles(850000);
  }
}

// red and green take turns blinking
void redThenDrink()
{
  for(int i = 0; i < 10; i++){
    P1OUT = LED_RED;
    __delay_cycles(850000);

    P1OUT = LED_GREEN;
    __delay_cycles(850000);

    P1OUT = !LED_RED;
    __delay_cycles(850000);

    P1OUT = !LED_GREEN;
    __delay_cycles(850000);
  }
}

// dims lights by making them blink fast
void dimNotBlinking()
{
  for(int i = 0; i <10000; i++){ // turns led off and on
    P1OUT = LED_RED;
    P1OUT = LED_GREEN;

    P1OUT = !LED_RED;
    P1OUT = !LED_GREEN;
  }
}

// dims leds while they are blinking
void dimAndBlinking()
{
  for(int i = 0; i < 20; i++){
    dimNotBlinking();
    __delay_cycles(2500000);

    P1OUT = !LED_RED;
    P1OUT = !LED_GREEN;
  }
}

void led_update(){
  if (switch_state_changed) {
    char ledFlags = 0;
    ledFlags |= switch_state_down ? LED_RED : 0;
    ledFlags |= switch_state_down ? 0 : LED_GREEN;
    
    P1OUT &= (0xff - LEDS) | ledFlags;
    P1OUT |= ledFlags;
  }
  switch_state_changed = 0;
}
