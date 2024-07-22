#ifndef __TIMER_H__
#define __TIMER_H__

#include "Arduino.h"

extern hw_timer_t *Timer0_Cfg ;
extern int flag_time;
extern int flag_end;

void IRAM_ATTR check_status();
void Setup_Timer();

#endif