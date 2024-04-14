#ifndef __TIMMER_H__
#define __TIMMER_H__

#include "Arduino.h"
#include "system.h"

void IRAM_ATTR check_status();
void Setup_Timer();

extern hw_timer_t *Timer0_Cfg ;

extern int flag_pause ;

extern int racing_time_ms;
extern int racing_time_second ;
extern int racing_time_minute ;

extern int next_screen ;

#endif