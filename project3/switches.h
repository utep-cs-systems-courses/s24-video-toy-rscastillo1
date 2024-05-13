#ifndef switches_included
#define switches_included

#define SW0 BIT3
#define SW1 1
#define SW2 2
#define SW3 4
#define SW4 8

#define SWITCHES 15

char switch_update_interrupt_sense();
char p1_update_interrupt_sense();
char p2_update_interrupt_sense();
void switch_init();
void switch_interrupt_handler();

#endif
