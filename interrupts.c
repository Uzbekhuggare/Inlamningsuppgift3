#include "header.h"

ISR (PCINT0_vect) {		//	Vad som h�nder vid interrupt.

	if ((!BUTTON1_PRESSED) && (b1.blink_round != 5)) {
		blink_round_changer(&b1, true, false);
	}
	
	if ((!BUTTON1_PRESSED) && (b1.blink_round == 5)) {
				
		
		switch (b1.direction) {		//	anv�nder mig av en switch case d� jag inte tyckte att else if k�ndes b�st
			
			case forward: {
				b1.direction = backward;	//	s�tter direction till motsatsen precis innan leds_blink f�r att byta h�ll.
				leds_blink(&b1);
				blink_round_changer(&b1, false, true);
				break;
			}
			
			case backward: {
				b1.direction = forward;		//	samma som ovanst�ende
				leds_blink(&b1);
				blink_round_changer(&b1, false, true);
				break;
			}
		}
		
	}
	
	return;		//	jag fick dock problemet att n�r jag h�ller ner knappen s� blinkar ledsen fram och tillbaka tills jag
}				//	sl�pper knappen och den byter h�ll. Vet dock inte om det �r fel p� min interrupt eller blinkfunktionen
				
				//	sedan �r den v�ldigt inconsistent med hur m�nga knappuppsl�ppningar man beh�ver g�ra innan den byter
				//	ibland kr�vs det 3, ibland 5, och ibland 7. S� felmarginalen verkar vara +-2 eller �tminstone
				//	n�got i de sv�ngarna
				//	Jag gjorde funktionen blink_round_changer med pekare till b1 f�r att kanske �tg�rda n�gon
				//	genv�g som kompilator kanske gjorde men nope. Testade �ven att g�ra struktpekare till
				//	volatile men det fungerade fortfarande inte som det ska, allts� l�r det vara n�gon annan
				//	miss jag gjort.