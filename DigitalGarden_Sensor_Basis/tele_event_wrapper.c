/*
 * tele_event_wrapper.c
 *
 * Created: 06.01.2019 14:53:31
 *  Author: Johannes
 */

#include "tele_event_wrapper.h"

void wrapper_init()
{
	tele_handler_init();
}

void wrapper_check_event(eTele_hanlder_event tele_event)
{
	switch(tele_event)
	{
		case eTele_check_event_group:
			//PORTB |= (1 << PB0);
			break;
		case eTele_check_event_id:
			//PORTB |= (1 << PB1);
			break;
		case eTele_check_event_checksum:
			//PORTB |= (1 << PB2);
			break;
		case eTele_check_event_unknown_req:
			//PORTB |= (1 << PB3);
			break;
		default:
			break;
	}
}

uint8_t wrapper_comm_event(eTeleType tele_event,tele_fixed *tele_in, tele_fixed *tele_out)
{
	uint8_t send = 0;
	switch(tele_event)
	{
		case TEL_HEARTBEAT_REQ:
			send = 1;
			build_telegram(tele_out, TEL_TYPE_FIXED_LEN, tele_in->sTele.origin_group_ID, tele_in->sTele.origin_device_ID, TEL_HEARTBEAT_RESP);
			tele_out->sTele.checksum = tele_checksum(tele_out);
			break;
			
		case TEL_SET_OUTPUT:
			send = 1;
			build_telegram(tele_out, TEL_TYPE_FIXED_LEN, tele_in->sTele.origin_group_ID, tele_in->sTele.origin_device_ID, TEL_ACK);
			for (uint8_t i = 0; i < 4; i++) {
				switch (tele_in->sTele.payload[2*i]) {
					case eTestAction_Set_LED:
						PORTB = (PORTB & 0xF0) | (tele_in->sTele.payload[2*i + 1] & 0x0F);
						break;
					default:
						break;
				}
			}
			tele_out->sTele.checksum = tele_checksum(tele_out);
			break;
			
		default:
			wrapper_check_event(eTele_check_event_unknown_req);
			send = 0;
			break;
	}
	return send;
}
