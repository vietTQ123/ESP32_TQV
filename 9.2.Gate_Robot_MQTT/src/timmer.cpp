#include "timmer.h"

hw_timer_t *Timer0_Cfg = NULL;
uint32_t Freq = 0;
int flag_pause = 0;
int count_timer = 0;
int racing_time = 0;

void IRAM_ATTR check_status()
{
  flag_pause = 1;
  if(count == 1)
  {
    count_timer++;
    if(count_timer == 20)
    {
      racing_time++;
      count_timer=0;
    }
  }
}

void Setup_Timer()
{
  Timer0_Cfg = timerBegin(0, 8000, true);
  timerAttachInterrupt(Timer0_Cfg, &check_status, true);
  timerAlarmWrite(Timer0_Cfg, 500, true); //50ms
  timerAlarmEnable(Timer0_Cfg);
}

