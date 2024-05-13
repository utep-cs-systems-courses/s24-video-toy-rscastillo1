#include <msp430.h>
#include <libTimer.h>
#include "lcdutils.h"
#include "lcddraw.h"
#include "buzzer.h"

//variables for storing current position
extern unsigned char pico_row = 30;
extern unsigned char pico_col = 80;
  
void lcd_starting(){
  clearScreen(COLOR_BLUE);
  drawString5x7(screenWidth/4, screenHeight/2, "Pico Drawer!",COLOR_PURPLE, COLOR_PINK);
  buzzer_starting();
}

void lcd_cleaning(){
  clearScreen(COLOR_BLUE);
  buzzer_cleaning();
}

void lcd_waiting(){
  fillRectangle(pico_col, pico_row, 1,1, COLOR_BLACK);
  fillRectangle(pico_col, pico_row, 1,1, COLOR_BLUE);
  buzzer_waiting();
}

void lcd_draw_up(){
  fillRectangle(pico_col, pico_row--, 1,1, COLOR_BLACK);
  buzzer_drawing();
}

void lcd_draw_down(){
  fillRectangle(pico_col, pico_row++, 1,1, COLOR_BLACK);
  buzzer_drawing();
}

void lcd_draw_left(){
  fillRectangle(pico_col--, pico_row, 1,1, COLOR_BLACK);
  buzzer_drawing();
}

void lcd_draw_right(){
  fillRectangle(pico_col++, pico_row, 1,1, COLOR_BLACK);
  buzzer_drawing();
}
