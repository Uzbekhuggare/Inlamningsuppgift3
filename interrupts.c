#include "header.h"

ISR (PCINT0_vect) {		//	Vad som h�nder vid interrupt.
	
	if (!BUTTON1_PRESSED) {
		
		switch (b1.direction) {		//	anv�nder mig av en switch case d� jag inte tyckte att else if k�ndes b�st
			
			case forward: {
				b1.direction = backward;	//	s�tter direction till motsatsen precis innan leds_blink f�r att byta h�ll.
				leds_blink(&b1);
				break;
			}
			
			case backward: {
				b1.direction = forward;		//	samma som ovanst�ende
				leds_blink(&b1);
				break;
			}
		}
		
	}

	return;
}