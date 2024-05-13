#include <msp430.h>
#include <libTimer.h>
#include "lcddraw.h"
#include "lcdutils.h"
#include "switches.h"
#include "buzzer.h"
#include "lcd_draw_functions.h"

void main()
{

  configureClocks();
  switch_init();
  lcd_init();
  init_buzzer();
  or_sr(0x8); //enable interrupts
  lcd_starting();
}

