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
};

struct blink b1;	//	skapar b1 inne i headern f�r att kunna anv�nda den i alla filer utan n�gra problem.

void setup();
void delay_ms(uint16_t speed_ms);
void leds_blink(struct blink* self);		//	denna funktion blev �ven mycket kortare pga anv�ndningen av strukt
											//	annars hade det typ blivit:
#endif										//	"void leds_blink(enum blink_direction direction, uint16_t* blink_speed);" eller n�got s�nt