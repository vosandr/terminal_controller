#include "includes.h"
#include "term.h"

/*ANSI/VT100 Terminal using example */
#include "defines.h"



void print_port_bits (unsigned char port) {
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

void print_alarm (int alarm_error) {
	gotoxy(2,12);
	if (alarm_error) {
		set_display_atrib(BRIGHT);
		set_display_atrib(B_RED);
		printf("        ERROR       ");
	} else {
		set_display_atrib(BRIGHT);
		set_display_atrib(B_GREEN);
		printf("         OK         ");
	}
}

void print_time_date (struct tm* tm_info) {
	char buffer[12];
	set_display_atrib(BRIGHT);
	set_display_atrib(B_BLUE);
	strftime(buffer, 12, "%d.%m.%y", tm_info);
	gotoxy(13,7)
	puts(buffer);
	strftime(buffer, 10, "%H:%M:%S", tm_info);
	gotoxy(13,8)
	puts(buffer);
	resetcolor();
}

unsigned char rol(unsigned char  a)
{
	return (a << 1) | (a >> 7);
}

void controller_emulator () {
	unsigned char  port = 0x01;
	int alarm_counter = 0;
	time_t timer;
	struct tm* tm_info;
	srand(time(NULL));  
	while (1) {
		float a[3] = {0.0, 0.0, 0.0};
		int i;
		for (i=0; i<3; i++) {
			int r = rand() % 101 + (-50);
			a[i] += (float)r / 1000;
		}
		if (alarm_counter < 30) {
			print_alarm(0);
		}
		if ((alarm_counter < 60) && (alarm_counter >= 30)) {
			print_alarm(1);
		}
		if (alarm_counter > 60) {
			alarm_counter = 0;
		}
		alarm_counter++;
		time(&timer);
		tm_info = localtime(&timer);
//********************************//
		print_accelerometer(a);
		print_port_bits(port);
		print_time_date(tm_info);
//********************************//
		port = rol(port);
		gotoxy(1,18);
		fflush(stdout);
		usleep(100000);
	}
}

int main (void) {
	home();
	clrscr();
	frame_draw ();
	controller_emulator	();
	return 0;
}
