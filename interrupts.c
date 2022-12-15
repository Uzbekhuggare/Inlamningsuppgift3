#include "header.h"

ISR (PCINT0_vect) {		//	Vad som händer vid interrupt.

	if ((!BUTTON1_PRESSED) && (b1.blink_round != 5)) {
		blink_round_changer(&b1, true, false);
	}
	
	if ((!BUTTON1_PRESSED) && (b1.blink_round == 5)) {
				
		
		switch (b1.direction) {		//	använder mig av en switch case då jag inte tyckte att else if kändes bäst
			
			case forward: {
				b1.direction = backward;	//	sätter direction till motsatsen precis innan leds_blink för att byta håll.
				leds_blink(&b1);
				blink_round_changer(&b1, false, true);
				break;
			}
			
			case backward: {
				b1.direction = forward;		//	samma som ovanstående
				leds_blink(&b1);
				blink_round_changer(&b1, false, true);
				break;
			}
		}
		
	}
	
	return;		//	jag fick dock problemet att när jag håller ner knappen så blinkar ledsen fram och tillbaka tills jag
}				//	släpper knappen och den byter håll. Vet dock inte om det är fel på min interrupt eller blinkfunktionen
				
				//	sedan är den väldigt inconsistent med hur många knappuppsläppningar man behöver göra innan den byter
				//	ibland krävs det 3, ibland 5, och ibland 7. Så felmarginalen verkar vara +-2 eller åtminstone
				//	något i de svängarna
				//	Jag gjorde funktionen blink_round_changer med pekare till b1 för att kanske åtgärda någon
				//	genväg som kompilator kanske gjorde men nope. Testade även att göra struktpekare till
				//	volatile men det fungerade fortfarande inte som det ska, alltså lär det vara någon annan
				//	miss jag gjort.