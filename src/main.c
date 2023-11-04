#include "h/term.h"

/*ANSI/VT100 Terminal using example */
#include "h/defines.h"

extern void frame_draw ();
extern void controller_emulator ();
unsigned char rol(unsigned char  a)
{
	return (a << 1) | (a >> 7);
}

int main (void) {
	home();
	clrscr();
	frame_draw ();
	controller_emulator	();
	return 0;
}
