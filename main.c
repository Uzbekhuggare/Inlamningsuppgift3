#include "header.h"


int main(void) {
	
	setup();		//	self explanatory
	b1.blink_delay = 100;		// s�tter b1's blinkningshastighet till 100ms.
	b1.direction = forward;		//	s�tter b1's bas direction till forward.
	
    while (1) {
		leds_blink(&b1);		//	startar blinkning.
    }
	
	return 0;
}

