#include "header.h"

static inline void init_ports();
static inline void init_interrupts();

void setup() {		//	self explanatory
	init_ports();
	init_interrupts();
	return;
}

static inline void init_ports() {		//	initierar portar för leds och knapp.
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

void leds_blink(struct blink* self) {		//	blinkfunktion med structpekare som ingående argument
	switch (self->direction) {				
		case forward: {				//	jag gillar typ switch case, känns bättre än if else
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
