#include "timmer.h"

hw_timer_t *Timer0_Cfg = NULL;

int flag_pause = 0;

int racing_time_ms = 0;
int racing_time_second = 0;
int racing_time_minute = 0;

int next_screen = 0;

void IRAM_ATTR check_status()
{
  flag_pause = 1;
  if(count == 1)
  {
    racing_time_ms++;
    if(racing_time_ms == 999)
    {
      racing_time_second ++;
      racing_time_ms = 0;
    }
    if(racing_time_second == 59)
    {
      racing_time_minute ++;
      racing_time_second = 0;
    }
    if(racing_time_minute == 59)
    {
      racing_time_minute = 0;
      racing_time_second = 0;
      racing_time_ms = 0;
    }
  }
  if(count == 2)
  {
    next_screen++;
    {
      if(next_screen == 5000)
      {
        next_screen  = 0;

        count = 0;
        racing_time_ms = 0;
        racing_time_second = 0;
        racing_time_minute = 0;

        flag_http_rst = 1;
        flag_http_start = 1;
        flag_http_stop = 1;
      }
    }
  }
}

void Setup_Timer()
{
  Timer0_Cfg = timerBegin(0, 8000, true);
  timerAttachInterrupt(Timer0_Cfg, &check_status, true);
  timerAlarmWrite(Timer0_Cfg, 10, true); //1ms
  timerAlarmEnable(Timer0_Cfg);
}
