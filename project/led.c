include <msp430.h>
#include "led.h"

void led_init()
{
  P1DIR |= LEDS;
  switch_state_changed = 1; 
}

//makes red led blink
void redLight()
{
  for(int i = 0; i < 10; i++){
    P1OUT = LED_RED;           //turns red led ON
    __delay_cycles(800000);    //delays program
    
    P1OUT = !LED_RED;          //turns red led OFF
    __delay_cycles(800000);
  }
}

//makes green led blink
void greenLight()
{
  for(int i = 0; i < 10; i++){
    P1OUT = LED_GREEN;         //turns green led ON
    __delay_cycles(800000);    //delays program
    
    P1OUT = !LED_GREEN;        //turns green led OFF
    __delay_cycles(800000);
  }
}

//makes red and green leds take turns blinking
void redThenGreen()
{
  for(int i = 0; i < 10; i++){
    P1OUT = LED_RED;
    __delay_cycles(800000);
    
    P1OUT = LED_GREEN;
    __delay_cycles(800000);
    
    P1OUT = !LED_RED;
    __delay_cycles(800000);
    
    P1OUT = !LED_GREEN;
    __delay_cycles(800000);
  }
}

//dims non-blinking leds
void dimNotBlinking()
{
  //this for loop will turn leds on and off
  for(int i = 0; i < 10000; i++){
    P1OUT = LED_RED;
    P1OUT = LED_GREEN;
    
    P1OUT = !LED_RED;
    P1OUT = !LED_GREEN;
  }
}

//dims bliking leds
void dimAndBlinking()
{
  for(int i = 0; i < 20; i++){
    dimNotBlinking();
    __delay_cycles(2000000);
    
    P1OUT = !RED_LED;
    P1OUT = !GREEN_LED;
  }
}

void updateLed()
{
  if(switch_state_changed){
    char ledFlags = 0;
    
    ledFlags |= switch_state_down ? LED_RED : 0;
    ledFlags |= switch_state_down ? 0 : LED_GREEN;

    P1OUT &= (0xff - LEDS) | ledFlags;
    P1OUT |= ledFlags;
  }

  switch_state_changed =  0;
}
