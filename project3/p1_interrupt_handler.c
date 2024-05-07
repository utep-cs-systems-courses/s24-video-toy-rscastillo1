#include <msp430.h>

#include "switches.h"



// Switch on Port 1

void __interrupt_vec(PORT1_VECTOR) Port_1(){

  if (P1IFG & SW0) {             // did a button cause this interrupt?
    P1IFG &= ~SW0;               // clear pending sw interrupts
    switch_interrupt_handler(); // single handler for all switches
  }
}

