/*
 * hwinit.c
 *
 * Created: 24.10.2018 11:25:00
 *  Author: Johannes
 */ 

#include "main.h"
#include "hwinit.h"

void hw_init(void)
{
	port_init();
	timer1_init();
}

void port_init(void)
{
	DDRB = (1 << PB0) | (1 << PB1) | (1 << PB2) | (1 << PB3);		//LED for LED-Module
	PORTB &= ~(1 << PB0) & ~(1 << PB1) & ~(1 << PB2) & ~(1 << PB3);
	PORTA &= ~(1 << PIN_RS485_RE);		//Startup in reciever mode
	DDRA |= (1 << PIN_RS485_RE);		//RE/!DE as output
	
}

void timer1_init(void)
{
	TIMSK1 |= (1 << TOIE1);
	TCCR1B |= (1 << CS11) | (1 << CS10);
}

