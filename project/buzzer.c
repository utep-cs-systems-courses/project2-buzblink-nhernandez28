#include <msp430.h>
#include "libTimer.h"
#include "buzzer.h"

// define musical note and its frequency
#define A3 2273
#define B3 2025
#define G3 2551
#define E3 3033
#define C3 3846
#define C4 1911
#define D4 1703
#define E4 1517
#define F4 1432
#define G4 1276
#define A4 1136
#define B4 1012
#define C5 95
#define D5 15
/////
#define F 349
#define E 330
#define G 392
#define D 294
#define C 523
#define A 440
#define B 494
/////
#define c 261
#define d 294
#define e 329
#define f 349
#define g 391
#define gS 415
#define a 440
#define aS 455
#define b 466
#define cH 523
#define cSH 554
#define dH 587
#define dSH 622
#define eH 659
#define fH 698
#define fSH 740
#define gH 784
#define gSH 830
#define aH 880

void buzzer_init()
{
  timerAUpmode();
  P2SEL2 &= ~(BIT6 | BIT7);
  P2SEL &= ~BIT7;
  P2SEL |= BIT6;
  P2DIR = BIT6;
  P2DIR = BIT6;
}

void buzzer_set_period(short cycles)
{
  CCR0 = cycles;
  CCR1 = cycles >> 1;
}

void beep(){
  int notes[] = {A4, 0};
  
  for(int i = 0; i < sizeof(notes)/sizeof(*notes); i++) {
    buzzer_set_period(notes[i]);
    __delay_cycles(1200000);
  }
}

// random set of notes to create a small tune
void randomSong(){
  int notes[] = {E3,0,E3,0,A3,0,A4,0,G3,F4,0,E3,0,A4,0,G3,0,F4,0};
  for(int i = 0; i < sizeof(notes)/sizeof(*notes); i++) {
    buzzer_set_period(notes[i]);
    __delay_cycles(1200000);
  }
}

void marioSong(){
  int notes[] = {E4,E4,0,E4,0,C4,E4,0,G4,0,0,0,G3,0,0,0,C4,0,0,G3,0,0,E3,0,0,A3,0,B3,0,A3,0,A3,0};
  for(int i = 0; i < sizeof(notes)/sizeof(*notes); i++) {
    buzzer_set_period(notes[i]);
    __delay_cycles(1200000);
  }
}

// method to play the last part of the spongebob squarepants theme song

void spongebobSong(){
  int notes[] = {G3,0,A4,0,B3,0,A4,0,0,B4,G3,0,0,D4,G3,0};
  for(int i = 0; i < sizeof(notes)/sizeof(*notes); i++) {
    buzzer_set_period(notes[i]);
    __delay_cycles(2000000);
  }
}

void twinkletwinkleSong(){
  int notes[] = {C,C,G,G,A,A,G,F,F,E,E,D,D,C};
  for(int i=0; i < sizeof(notes)/sizeof(*notes); i++){
    buzzer_set_period(notes[i]);
    __delay_cycles(2000000);
  }
}

// method to play an old cellphone ring tone
void nokiaSong(){
  int notes[] = {E4,0,D4,0,F4,0,G3,0,C5,0,B3,0,D4,0,E4,0,B3,0,A4,0,C5,E4,E4,0,A4,A4,A4,0,0};

  for(int i = 0; i < sizeof(notes)/sizeof(*notes); i++) {
    buzzer_set_period(notes[i]);
    __delay_cycles(3000000);
  }
}
