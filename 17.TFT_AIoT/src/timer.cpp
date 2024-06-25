#include "timer.h"

hw_timer_t *Timer0_Cfg = NULL;


int time_second = 0;
int time_minute = 0;
int time_hour = 0;

void IRAM_ATTR check_status()
{
    time_second ++;
    if (time_second > 59)
    {
        time_minute++;
        time_second = 0;
    }
    if (time_minute > 59)
    {
        time_hour++;
        time_minute = 0;
    }
    if(time_hour > 23)
    {
        time_hour = 0;
    }
}

void Setup_Timer()
{
    Timer0_Cfg = timerBegin(0, 8000, true);
    timerAttachInterrupt(Timer0_Cfg, &check_status, true);
    timerAlarmWrite(Timer0_Cfg, 1000, true); // 1s
    timerAlarmEnable(Timer0_Cfg);
}