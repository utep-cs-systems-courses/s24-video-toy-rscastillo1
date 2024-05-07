#ifndef buzzer_included
#define buzzer_included

/*functions for buzzer initialization
each function will play set frequency to 
each note*/

void init_buzzer();
void set_buzzer_period(unsigned int period);

void buzzer_starting();
void buzzer_cleaning();
void buzzer_waiting();
void buzzer_drawing();

extern int buzz_speed;

#endif
