void frame_draw () {
	home();
	set_display_atrib(B_BLUE);
//            123456789012345678901
	puts(	"┌─────────┐┌─────────┐\n" //0
			"│         ││         │\n" //1
			"│         ││         │\n" //2
			"│         ││         │\n" //3
			"│         │├─────────┤\n" //4
			"│         ││         │\n" //5
			"│         ││         │\n" //6
			"│         ││         │\n" //7
			"│         ││         │\n" //8
			"└─────────┘└─────────┘\n" //9
			"┌────────────────────┐\n" //10
			"│                    │\n" //11
			"└────────────────────┘");  //12
	resetcolor();
}