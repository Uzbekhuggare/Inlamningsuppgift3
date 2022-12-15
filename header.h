#ifndef HEADER_H_
#define HEADER_H_

#define F_CPU 16000000UL

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <stdbool.h>

//	makron för alla leds + en knapp

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

enum blink_direction{		//	enumerator för att göra koden enklare och tydligare, känns bättre att skriva när man har
	forward,				//	som en dedikerad datatyp för denna sorts grejer
	backward
};

struct blink {							//	Kände att en struct passade då det gjorde att jag lättare kunde "transferra"
	enum blink_direction direction;		//	värden mellan filer och jag kände att jag behövde mer övning gällande struktar
	uint16_t blink_delay;
	uint8_t blink_round;
};

struct blink b1;	//	skapar b1 inne i headern för att kunna använda den i alla filer utan några problem.



void setup();
void delay_ms(const volatile uint16_t speed_ms);
void leds_blink(struct blink* self);		//	denna funktion blev även mycket kortare pga användningen av strukt
											//	annars hade det typ blivit:
											//	"void leds_blink(enum blink_direction direction, uint16_t* blink_speed);" eller något sånt
//	blink_round_changer: ändrar vilket varv tryckknappen är på.
//	self:  pekare till strukt för att komma åt varvnummer
//	adder: används för att lägga till ett varv, true för att lägga till ett varv, annars false
//	reset: skicka in true för att sätta varvet till 0, false för ingenting.

void blink_round_changer(volatile struct blink* self, bool adder, bool reset);	

#endif