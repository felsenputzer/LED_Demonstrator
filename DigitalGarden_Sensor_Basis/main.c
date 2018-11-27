/*
 * DigitalGarden_Sensor_Basis.c
 *
 * Created: 24.10.2018 11:23:15
 * Author : Johannes
 */ 

#include "main.h"
#include "hwinit.h"
#include <COMM/uart_attiny87.h>
#include <COMM/telegram.h>
#include <avr/interrupt.h>
#include <util/delay.h>

volatile uint8_t count = 0;
volatile uint8_t cooldown = 1;

tele_fixed Telegram;

int main(void)
{
	hw_init();
	uart_init();
	sei();
	
    while (1) 
    {

    }
}

ISR(TIMER1_OVF_vect)
{

}

ISR(LIN_TC_vect)
{
	cli();
	if(LINSIR & (1 << LIDOK))
	{
			
	}
	if(LINSIR & (1 << LTXOK))
	{
		tele_handler(uart_event_tx_ready);
	}
	if(LINSIR & (1 << LRXOK))
	{
		tele_handler(uart_event_rx_ready);
	}
	sei();
}