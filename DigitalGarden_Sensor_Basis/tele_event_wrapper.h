/*
 * tele_event_wrapper.h
 *
 * Created: 06.01.2019 14:54:00
 *  Author: Johannes
 */ 


#ifndef TELE_EVENT_WRAPPER_H_
#define TELE_EVENT_WRAPPER_H_

#include "main.h"
#include "Lib/COMM/telegram.h"
#include "Lib/COMM/kennungen.h"

void tele_check_event(eTele_hanlder_event tele_event);
void tele_comm_event(uint8_t tele_event, tele_fixed *tele_out);

#endif /* TELE_EVENT_WRAPPER_H_ */