#include <msp430.h>
#include "libTimer.h"
#include "buzzer.h"

// notes
#define B3 2025
#define G3 2551
#define E3 3033
#define D4 1703
#define G4 1276
#define A4 1136
#define B4 1012
#define D5 1587

void buzzer_init()
{
  timerAUpmode();
  P2SEL2 &= ~(BIT6 | BIT7);
  P2SEL &= ~BIT7;
  P2SEL |= BIT6;
  P2DIR = BIT6;
}

void buzzer_set_period(short cycles)
{
  CCR0 = cycles;
  CCR1 = cycles >> 1;
}

void beep()
{
  int notes[] = {E3, 0, E3, 0};

  for(int i = 0; i < sizeof(notes) / sizeof(*notes); i++) {
    buzzer_set_period(notes[i]);
    __delay_cycles(1000000);
  }
}

void beep1()
{
  int notes[] = {E3, 0, A4, 0, E3, 0, A4, 0};

  for(int i = 0; i < sizeof(notes) / sizeof(*notes); i++) {
    buzzer_set_period(notes[i]);
    __delay_cycles(1000000);
  }
}

void beep2()
{
  int notes[] = {G4, 0, G3, 0, G4, 0, G3, 0};

  for(int i = 0; i < sizeof(notes)/sizeof(*notes); i++) {
    buzzer_set_period(notes[i]);
    __delay_cycles(1000000);
  }
}

void beep3()
{
  int notes[] = {B3, 0, D4, 0 , B3, 0, B4, 0};

  for(int i = 0; i < sizeof(notes)/sizeof(*notes); i++) {
    buzzer_set_period(notes[i]);
    __delay_cycles(2000000);
  }
}

void beep4()
{
  int notes[] = {D5, 0, D4, 0, D5, 0, D4, 0};
  
  for(int i=0; i < sizeof(notes)/sizeof(*notes); i++){
    buzzer_set_period(notes[i]);
    __delay_cycles(2000000);
  }
}
