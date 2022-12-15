#ifndef HEADER_H_
#define HEADER_H_

#define F_CPU 16000000UL

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <stdbool.h>

//	makron f�r alla leds + en knapp

#define LED1 PORTB0
#define LED2 PORTB1
#define LED3 PORTB2

#define LED_TEST PORTB3
#define LED_TEST_ON PORTB |= (1 << LED_TEST)
#define LED_TEST_OFF PORTB &= ~(1 << LED_TEST)

#define LED1_ON PORTB |= (1 << LED1)
#define LED2_ON PORTB |= (1 << LED2)
#define LED3_ON PORTB |= (1 << LED3)
#define LED1_OFF PORTB &= ~(1 << LED1)
#define LED2_OFF PORTB &= ~(1 << LED2)
#define LED3_OFF PORTB &= ~(1 << LED3)

#define BUTTON1 PORTB5
#define BUTTON1_PRESSED (PINB & (1 << BUTTON1))

enum blink_direction{		//	enumerator f�r att g�ra koden enklare och tydligare, k�nns b�ttre att skriva n�r man har
	forward,				//	som en dedikerad datatyp f�r denna sorts grejer
	backward
};

struct blink {							//	K�nde att en struct passade d� det gjorde att jag l�ttare kunde "transferra"
	enum blink_direction direction;		//	v�rden mellan filer och jag k�nde att jag beh�vde mer �vning g�llande struktar
	uint16_t blink_delay;
	uint8_t blink_round;
};

struct blink b1;	//	skapar b1 inne i headern f�r att kunna anv�nda den i alla filer utan n�gra problem.



void setup();
void delay_ms(const volatile uint16_t speed_ms);
void leds_blink(struct blink* self);		//	denna funktion blev �ven mycket kortare pga anv�ndningen av strukt
											//	annars hade det typ blivit:
											//	"void leds_blink(enum blink_direction direction, uint16_t* blink_speed);" eller n�got s�nt
//	blink_round_changer: �ndrar vilket varv tryckknappen �r p�.
//	self:  pekare till strukt f�r att komma �t varvnummer
//	adder: anv�nds f�r att l�gga till ett varv, true f�r att l�gga till ett varv, annars false
//	reset: skicka in true f�r att s�tta varvet till 0, false f�r ingenting.

void blink_round_changer(volatile struct blink* self, bool adder, bool reset);	

#endif