#include "timer.h"

hw_timer_t *Timer0_Cfg = NULL;

void IRAM_ATTR check_status()
{
    data_seconds ++;

    if (data_seconds > 59)
    {
        data_minutes ++;
        data_seconds = 0;
    }
    if (data_minutes > 59)
    {
        data_hour++;
        data_minutes = 0;
    }
    if(data_hour > 23)
    {
        data_hour = 0;
    }

}

void Setup_Timer()
{
    Timer0_Cfg = timerBegin(0, 8000, true);
    timerAttachInterrupt(Timer0_Cfg, &check_status, true);
    timerAlarmWrite(Timer0_Cfg, 10000, true); // 1s
    timerAlarmEnable(Timer0_Cfg);
}