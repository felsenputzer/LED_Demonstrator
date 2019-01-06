/*
 * tele_event_wrapper.c
 *
 * Created: 06.01.2019 14:53:31
 *  Author: Johannes
 */ 

#include "tele_event_wrapper.h"

void tele_check_event(eTele_hanlder_event tele_event)
{
	switch(tele_event)
	{
		case tele_check_event_group:
			PORTB ^= (1 << PB0);
			break;
		case tele_check_event_id:
			PORTB ^= (1 << PB0);
			break;
		case tele_check_event_checksum:
			PORTB ^= (1 << PB0);
			break;
		case tele_check_event_unknown_req:
			PORTB ^= (1 << PB0);
			break;
	}
}

void tele_comm_event(uint8_t tele_event, tele_fixed *tele_out)
{
	
	switch(tele_event)
	{
		case TEL_HEARTBEAT_REQ:
				build_telegram(tele_out, TEL_TYPE_FIXED_LEN, BROADCAST_GROUP_ID, BROADCAST_DEVICE_ID, TEL_HEARTBEAT_RESP);
				tele_out->sTele.payload[0] = my_device.group_ID;
				tele_out->sTele.payload[1] = my_device.device_ID;
				tele_out->sTele.checksum = tele_checksum(tele_out);
				break;
	}
	return;
}