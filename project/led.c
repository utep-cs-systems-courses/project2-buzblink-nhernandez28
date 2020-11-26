#include <msp430.h>
#include "led.h"
#include "switches.h"
#include "stateMachine.h"

unsigned char red_on = 0;
unsigned char green_on = 0;
unsigned char led_changed = 0;

static char redVal[] = {0, LED_RED};
static char greenVal[] = {0, LED_GREEN};

void led_init()
{
  P1DIR |= LEDS;
  led_changed = 1;
  led_update();
}

void led_update()
{
  if(led_changed){
    char ledFlags = redVal[red_on] | greenVal[green_on];

    P1OUT &= (0xff - LEDS) | ledFlags;
    P1OUT |= ledFlags;
    led_changed = 0;
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
