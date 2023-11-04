void print_port_bits(unsigned char port)
{
    int i;
	unsigned char maxPow = 1<<(8-1);
	set_display_atrib(B_BLUE);
	set_display_atrib(BRIGHT);
	for(i=0;i<8;++i){
		// print last bit and shift left.
		gotoxy(2,2 + i);
		if (port & maxPow) {
			set_display_atrib(F_GREEN);
			printf("pin%d= on ",i);
		} else {
			set_display_atrib(F_RED);
			printf("pin%d= off",i);			
		}
		port = port<<1;
	}
	resetcolor();
}