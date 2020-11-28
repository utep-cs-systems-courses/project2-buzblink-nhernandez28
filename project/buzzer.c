#include <msp430.h>
#include "libTimer.h"
#include "buzzer.h"

//MUSIC NOTES
#define A3 2273
#define B3 2025
#define C3 3846
#define D4 1703
#define E3 3033
#define F4 1432
#define G4 1276

//initiates sound
void buzzer_init()
{
  timerAUpmode();             //msp430 speaker
  P2SEL2 &= ~(BIT6 | BIT7);
  //sets function of the pins to I/O mode
  P2SEL &= ~BIT7;
  P2SEL |= BIT6;
  //pin2 direction stored here
  P2DIR = BIT6;               //SPEAKER OUTPUT
}

void buzzer_set_period(short cycles)
{
  // BUZZER CLOCK = 2MHZ. (PERIOD OF 1K RESULTS IN 2KHZ TONE)
  CCR0 = cycles;
  CCR1 = cycles >> 1; // ONE HALF CYCLE
}

//song for button1
void tune1()
{
  int i = 0;
  int notes[] = {A3, B3, C3, D4};

  //while loop will traverse through notes[]
  while(i < sizeof(notes)){
    int t1 = 0;
    
    while (t1 < 15){
      int t2 = 0;
      
      while(t2 < 20000){
	t2++;
      }
      t1++;
    }
    
    buzzer_set_period(notes[i]);
    state_advance();
    i++;

    /*
  for(int i = 0; i < sizeof(song) / sizeof(*song); i++){
    buzzer_set_period(song[i]);
    __delay_cycles(850000);
  }
  */
    
  }
}

//song for button2
void tune2()
{
  int i = 0;
  int notes[] = {G4, F4, E3, D4};

  while(i < sizeof(notes)){
    int t1 = 0;
    
    while(t1 < 15){
      int t2 = 0;
      
      while(t2 < 20000){
	t2++;
      }
      
      t1++;
    }

    buzzer_set_period(notes[i]);
    state_advance();
    i++;

    /*
  for(int i = 0; i < sizeof(song) / sizeof(*song); i++){
    buzzer_set_period(song[i]);
    __delay_cycles(850000);
  }
  */
    
  }
}

void tune3()
{
  int i = 0;
  int notes[] = {C3, B3, A3, C3};
  
  while(i < sizeof(notes)){
    int t1 = 0;
    
    while(t1 < 15){
      int t2 = 0;
      
      while(t2 < 20000){
	t2++;
      }
      
      t1++;
    }
    
    buzzer_set_period(notes[i]);
    state_advance();
    i++;

    /*
  for(int i = 0; i < sizeof(song) / sizeof(*song); i++){
    buzzer_set_period(song[i]);
    __delay_cycles(850000);
  }
  */
    
  }
}

void tune4()
{
  int i = 0;
  int notes[] = {F4, D4, G4, B3};

  while(i < sizeof(notes)){
    int t1 = 0;
    
    while(t1 < 15){
      int t2 = 0;
      
      while(t2 < 20000){
	t2++;
      }
      
      t1++;
    }

    buzzer_set_period(notes[i]);
    state_advance();
    i++;

    /*
  for(int i = 0; i < sizeof(song) / sizeof(*song); i++){
    buzzer_set_period(song[i]);
    __delay_cycles(850000);
  }
  */
    
  }
}
