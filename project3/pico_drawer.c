#include <msp430.h>
#include <libTimer.h>
#include <stdio.h>
#include "lcddraw.h"
#include "lcdutils.h"
#include "switches.h"
#include "buzzer.h"

char redrawScreen = 1;

void main(){
  P1DIR |= 64;
  P1OUT |= 64;
  configureClocks();
  lcd_init();
  switch_init();
  buzzer_init();
  enableWDTInterrupts();
  or_sr(0x8);
  
  while(1) {
    if (redrawScreen) {
      update_shapes();
      redrawScreen = 0;
    }
    P1OUT &= ~64;   // led off
    or_sr(0x10);    // cpu off
    P1OUT |= 64;    // led on
  }
}
  

