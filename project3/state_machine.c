#include <msp430.h>
#include "state_machine.h"
#include "led.h"
#include "buzzer.h"

State current_state = STARTING;

void starting()
{
  buzzer_startup();
  lcd_startup();
}

void cleaning()
{
  buzzer_cleaning();
  lcd_cleaning();
}

void waiting()
{
  buzzer_waiting();
  lcd_waiting();
}

void draw_up()
{
  buzzer_draw_up();
  lcd_draw_up();//i hope this doesnt have a weird effect in lcd utils
}

void draw_down()
{
  buzzer_draw_down();
  lcd_draw_down();//i hope this doesnt have a weird effect in lcd utils
}

void draw_left()
{
  buzzer_draw_left();
  lcd_draw_left();//i hope this doesnt have a weird effect in lcd utils
}

void draw_right()
{
  buzzer_draw_right();
  lcd_draw_right();//i hope this doesnt have a weird effect in lcd utils
}


void transition(State next_state)
{
  current_state = next_state;
}

