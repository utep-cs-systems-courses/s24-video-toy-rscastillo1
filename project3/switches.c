#include <msp430.h>
#include "switches.h"
#include "led.h"
#include "state_machine.h"

extern int redrawScreen;

void switch_init(){
  //buttons on green board
  P2REN |= SWITCHES;
  P2IE |= SWITCHES;
  P2OUT |= SWITCHES;
  P2DIR &= ~SWITCHES;

  //button on red board
  P1REN |= S0;
  P1IE |= S0;
  P1OUT |= S0;
  P1DIR &= ~S0;
}

char p1_update_interrupt_sense()
{
  char p1_val = P1IN; // if switch up/down , sense down/ up

  P1IES |= (p1_val & S0);
  P1IES &= (p1_val | ~S0);
  return p1_val;
}

char p2_update_interrupt_sense(){

  char p2_val = P2IN;
  // if switch up/down , sense down/ up

  P2IES |= (p2_val & SWITCHES);
  P2IES &= (p2_val | ~SWITCHES);
  return p2_val;
}
static int side_button_press_count = 0;

void sw_interrupt_handler(){

  char p1_val = p1_update_interrupt_sense();

  char p2_val = p2_update_interrupt_sense();

  char button0 = (p1_val & S0) ? 0 : S0;

  char button1 = (p2_val & S1) ? 0 : S1;

  char button2 = (p2_val & S2) ? 0 : S2;

  char button3 = (p2_val & S3) ? 0 : S3;

  char button4 = (p2_val & S4) ? 0 : S4;

  if (button0)
    side_button_press_count++;
  else if (button1)
    next_state(1);
  else if (button2)
    next_state(2);
  else if (button3)
    next_state(3);
  else if(button4)
    next_state(4);
}

