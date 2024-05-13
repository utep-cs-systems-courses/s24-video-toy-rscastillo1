#include <msp430.h>
#include "switches.h"
#include "lcd_draw_functions.h"

extern int redrawScreen;

void switch_init(){
  //buttons on green board
  P2REN |= SWITCHES;
  P2IE |= SWITCHES;
  P2OUT |= SWITCHES;
  P2DIR &= ~SWITCHES;

  //button on red board
  P1REN |= SW0;
  P1IE |= SW0;
  P1OUT |= SW0;
  P1DIR &= ~SW0;
}

char p1_update_interrupt_sense()
{
  char p1_val = P1IN; // if switch up/down , sense down/ up

  P1IES |= (p1_val & SW0);
  P1IES &= (p1_val | ~SW0);
  return p1_val;
}

void __interrupt_vec(PORT1_VECTOR) Port_1(){

  if (P1IFG & SW0) {             // did a button cause this interrupt?
    P1IFG &= ~SW0;               // clear pending sw interrupts
    switch_interrupt_handler(); // single handler for all switches
  }
}

char p2_update_interrupt_sense(){

  char p2_val = P2IN;
  // if switch up/down , sense down/ up
  P2IES |= (p2_val & SWITCHES);
  P2IES &= (p2_val | ~SWITCHES);
  return p2_val;
}


void __interrupt_vec(PORT2_VECTOR) Port_2()
{
  if (P2IFG & SWITCHES){
    P2IFG &= ~SWITCHES;
    switch_interrupt_handler();
  }
}

static int side_button_press_count = 0;

void switch_interrupt_handler(){

  char p1_val = p1_update_interrupt_sense();

  char p2_val = p2_update_interrupt_sense();

  char button0 = (p1_val & SW0) ? 0 : SW0;

  char button1 = (p2_val & SW1) ? 0 : SW1;

  char button2 = (p2_val & SW2) ? 0 : SW2;

  char button3 = (p2_val & SW3) ? 0 : SW3;

  char button4 = (p2_val & SW4) ? 0 : SW4;

  if (button0){
    side_button_press_count++;
    if(side_button_press_count==2){
      side_button_press_count = 0;
      lcd_cleaning();
      return;
    }
  }else if (button1)
    lcd_draw_up();
  else if (button2)
    lcd_draw_down();
  else if (button3)
    lcd_draw_left();
  else if(button4)
    lcd_draw_right();
  
  lcd_waiting();
}
  

