#include <msp430.h>

#include <libTimer.h>

#include "state_machine.h"


void wdt_c_handler(){

  switch (current_state){

  case STARTING:
    state_starting();
    break;

  case WAITING:
    state_waiting();
    break;

  case CLEANING:
    state_cleaning();
    break;

  case DRAWUP:
    state_draw_up();
    break;
    
  case DRAWDOWN:
    state_draw_down();
    break;

  case DRAWLEFT:
    state_draw_left();
    break;

  case DRAWRIGHT:
    state_draw_right();
    break;
  }
}
