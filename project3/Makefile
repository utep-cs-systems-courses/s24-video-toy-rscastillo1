# makefile configuration

CPU             	= msp430g2553

CFLAGS          	= -mmcu=${CPU} -Os -I../h

LDFLAGS		= -L../lib -L/opt/ti/msp430_gcc/include/

#switch the compiler (for the internal make rules)
CC              = msp430-elf-gcc
AS              = msp430-elf-gcc -mmcu=${CPU} -c


all:pico_draw.elf

#additional rules for files

pico_draw.elf: ${COMMON_OBJECTS} pico_drawer.o buzzer.o switches.o lcd_draw_functions.o

	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^ -lTimer -lLcd

load: pico_draw.elf
	msp430loader.sh $^

clean:
	rm -f *.o *.elf *~
