#include "h/includes.h"


extern void print_alarm (int alarm_error);
extern void print_accelerometer(float * a);
extern void print_port_bits (unsigned char port);
extern void print_time_date (struct tm* tm_info);


extern void controller_emulator () {
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