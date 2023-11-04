

void print_accelerometer(float * a) {
	int i;
	const char * coordinate = "XYZ";
	set_display_atrib(B_BLUE);
	set_display_atrib(BRIGHT);
	int display_atrib = F_RED;
	set_display_atrib(display_atrib);
	for (i = 0; i < 3; i++) {
		set_display_atrib(display_atrib + i);
		gotoxy(13,2+i);
		printf("A%c=%+1.3f", coordinate[i], a[i]);
	}
	

	resetcolor();
}