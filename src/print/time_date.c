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