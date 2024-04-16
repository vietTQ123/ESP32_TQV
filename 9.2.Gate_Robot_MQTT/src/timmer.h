#ifndef __TIMMER_H__
#define __TIMMER_H__

#include "Arduino.h"
#include "system.h"

void IRAM_ATTR check_status();
void Setup_Timer();

extern hw_timer_t *Timer0_Cfg ;
extern uint32_t Freq ;
extern int flag_pause ;
extern int count_timer ;
extern int racing_time ;

#endif