#include <msp430.h>

typedef enum {
  STARTING,
  CLEANING,
  WAITING,
  DRAWUP,
  DRAWDOWN,
  DRAWLEFT,
  DRAWRIGHT
} State;


void starting();
void cleaning();
void waiting();
void draw_up();
void draw_down();
void draw_left();
void draw_right();
void transition(State next_state);

extern State current_state;
