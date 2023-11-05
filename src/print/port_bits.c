#include "../h/term.h"
extern void print_port_bits(unsigned char port)
{
	
    int i=0;
	unsigned char maxPow = 1<<(8-1);
	set_display_atrib(B_BLUE);
	set_display_atrib(BRIGHT);
	print_and_shift(port, maxPow, i);
	resetcolor();
}

int print_and_shift(int port, int maxPow, int i){
	int n = 8;
	gotoxy(2,2 + i);
	if (port & maxPow) {
		set_display_atrib(F_GREEN);
		printf("pin%d= on ", i);
	} else {
		set_display_atrib(F_RED);
		printf("pin%d= off",i);			
	}
	port = port<<1;
	if(i<n){
		print_and_shift(port, maxPow, i++);
	}
	return 0;
}

