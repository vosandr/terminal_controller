#include <stdio.h>
#define home() 			printf(ESC "[H") //Move cursor to the indicated row, column (origin at 1,1)
#define clrscr()		printf(ESC "[2J") //lear the screen, move to (1,1)
#define gotoxy(x,y)		printf(ESC "[%d;%dH", y, x);
#define visible_cursor() printf(ESC "[?251");
/* 
Set Display Attribute Mode	<ESC>[{attr1};...;{attrn}m
*/
#define resetcolor() printf(ESC "[0m")
#define set_display_atrib(color) 	printf(ESC "[%dm",color)