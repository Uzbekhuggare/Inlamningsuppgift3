#include "header.h"

ISR (PCINT0_vect) {		//	Vad som händer vid interrupt.
	
	if (!BUTTON1_PRESSED) {
		
		switch (b1.direction) {		//	använder mig av en switch case då jag inte tyckte att else if kändes bäst
			
			case forward: {
				b1.direction = backward;	//	sätter direction till motsatsen precis innan leds_blink för att byta håll.
				leds_blink(&b1);
				break;
			}
			
			case backward: {
				b1.direction = forward;		//	samma som ovanstående
				leds_blink(&b1);
				break;
			}
		}
		
	}

	return;
}