#ifndef __TIMER__
#define __TIMER__

#include "Arduino.h"
#include "Json.h"

extern hw_timer_t *Timer0_Cfg ;

void IRAM_ATTR check_status();
void Setup_Timer();

#endif