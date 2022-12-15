#include "header.h"

static inline void init_ports();
static inline void init_interrupts();

void setup() {		//	self explanatory
	init_ports();
	init_interrupts();
	b1.blink_round = 0;		//	s�tts till 0 och ska sedan r�knas upp till 5 f�r att h�lla reda p� hur m�nga 
	return;					//	knapptryckningar som gjorts innan man byter h�ll.
}

static inline void init_ports() {		//	initierar portar f�r leds och knapp.
	DDRB = (1 << LED1) | (1 << LED2) | (1 << LED3);
	PORTB = (1 << BUTTON1);
	return;
}

static inline void init_interrupts() {		//	initierar avbrott
	sei();
	PCICR |= (1 << PCIE0);					
	PCMSK0 |= (1 << PCINT5);				
	return;
}

void delay_ms(const volatile uint16_t speed_ms) {		//	delayfunktion
	for (int i = 0; i <= speed_ms; i++) {
		_delay_ms(1);
	}
	
	return;
}

void leds_blink(struct blink* self) {		//	blinkfunktion med structpekare som ing�ende argument
	switch (self->direction) {
		case forward: {				//	jag gillar typ switch case, k�nns b�ttre �n if else
			LED1_ON;
			delay_ms(self->blink_delay);
			LED1_OFF;
			LED2_ON;
			delay_ms(self->blink_delay);
			LED2_OFF;
			LED3_ON;
			delay_ms(self->blink_delay);
			LED3_OFF;
			break;
		}
		
		case backward: {
			LED3_ON;
			delay_ms(self->blink_delay);
			LED3_OFF;
			LED2_ON;
			delay_ms(self->blink_delay);
			LED2_OFF;
			LED1_ON;
			delay_ms(self->blink_delay);
			LED1_OFF;
			break;
		}
		
		default: { break; }
	}
	
	return;
}

void blink_round_changer(volatile struct blink* self, bool adder, bool reset) {
	if (reset == true) {		//	om reset = true (allts� att man vill �terst�lla vilket varv man �r p�), s�tt varv till 0
		self->blink_round = 0;		
		return;					//	returnera f�r att inte g�ra det som kommer efter denna if-sats.
	}
	
	if (self->blink_round > 5) {		//	om p� n�got s�tt blink_round �r st�rre �n 5, s�tt den till 5 och returna
		self->blink_round = 5;
		return;
	}
	
	if (adder) {						//	om man vill addera 1 till blink_round, addera 1 p� blink_round
		self->blink_round++;			//	och sedan returnera, beh�ver ingen if f�r false d� den enbart ska 
		return;							//	returna d� vilket den g�r utan n�gon extra if
	}
	
	return;
}
