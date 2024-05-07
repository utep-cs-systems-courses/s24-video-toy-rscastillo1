#include <msp430.h>
#include "buzzer.h"
#include "libTimer.h"

void init_buzzer(){
  timerAUpmode();/* used to drive speaker */
  P2SEL2 &= ~(BIT6 | BIT7);
  P2SEL &= ~BIT7;
  P2SEL |= BIT6;
  P2DIR = BIT6;        /* enable output to speaker (P2.6) */
}

void set_buzzer_period(unsigned int period) {
  TA0CCR0 = period;
  TA0CCR1 = period >> 1;
}

void buzzer_starting() {
  int i = 5000;
  while(i > 0){
    i -= 20;
    set_buzzer_period((i/i + (500/i)) % i);
  }
}

void buzzer_cleaning()
{
  int i = 1;
  while(i < 5000){
    i += 10;
    set_buzzer_period((i * i - (500*i)) % i );//lets see what this sounds like 
  }
}

void buzzer_waiting()
{
  set_buzzer_period(0);
}
void buzzer_drawing()
{
  set_buzzer_period(3000);
}

