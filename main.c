#include "header.h"


int main(void) {
	
	setup();
	//struct blink b1;
	b1.blink_delay = 100;
	b1.direction = forward;
	
	while (1) {
		leds_blink(&b1);	
	}
	
	return 0;
}

