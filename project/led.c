#include <msp430.h>
#include "led.h"
#include "switches.h"
#include "stateMachine.h"

//red and green led are off
unsigned char r_on, g_on;

//change in led status will be 1
unsigned char changed_led = 0;

static char redVal[] = {0, LED_RED};
static char greenVal[] = {0, LED_GREEN};

void led_init()
{
  //bits attached to the OUTPUT
  P1DIR |= LEDS;
  changed_led = 1;
  led_update();
}

//removes the old to get new info
void led_update()
{
  //this is if it equals to one
  if(changed_led){
    char ledFlags = redVal[r_on] | greenVal[g_on];

    //this is going to CLEAR bits
    P1OUT &= (0xff - LEDS) | ledFlags;
    //this is going to SET the bits
    P1OUT |= ledFlags;
    changed_led = 0;
  }
}

//makes red led blink
/*void redLight()
{
  for(int i = 0; i < 10; i++){
    P1OUT = LED_RED;           // will turn re led on
    __delay_cycles(850000);    // delays program

    P1OUT = !LED_RED;          // will turn red led off
    __delay_cycles(850000);
  }
}

//makes green led blink
void greenLight()
{
    for(int i = 0; i < 10; i++){
    P1OUT = LED_GREEN;         // will turn green led on
    __delay_cycles(700000);    // delays program

    P1OUT = !LED_GREEN;        // will turn green led off
    __delay_cycles(700000);
  }
}
 
// red and green take turns blinking

void bothLights()
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

void redThenGreen()
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
}*/
