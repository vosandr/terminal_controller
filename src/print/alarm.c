#include "../h/term.h"
extern void print_alarm (int alarm_error) {
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