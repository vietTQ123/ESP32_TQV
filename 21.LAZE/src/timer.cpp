#include "timer.h"

hw_timer_t *Timer0_Cfg = NULL;

int flag_time = 0;
int flag_end = 0;

void IRAM_ATTR check_status()
{
  flag_time++;
  if (flag_time == 60)
  {
    flag_end = 1;
    flag_time = 0;
    // delay(500);
  }
}

void Setup_Timer()
{
  Timer0_Cfg = timerBegin(0, 8000, true);
  timerAttachInterrupt(Timer0_Cfg, &check_status, true);
  timerAlarmWrite(Timer0_Cfg, 10000, true); // 1s
  timerAlarmEnable(Timer0_Cfg);
}
