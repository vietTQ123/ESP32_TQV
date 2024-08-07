#include "system.h"

int stt_button_new = 1;
int stt_button_old;

int stt_lazer_new = 0;
int stt_lazer_old;

int count_stt = 0;

int count_reset = 0;
static int flag_save = 0;
static long time_run_total = 0;

uint32_t delay_state_timer = 0;
uint8_t flag_state = 0;

uint8_t flag_http_rst = 1;
uint8_t flag_http_start = 1;
uint8_t flag_http_stop = 1;

void Setup_System ()
{
  Serial.begin(9600);

  pinMode(BUTTON_RST,INPUT); 
  pinMode(LAZER,INPUT);

  Setup_Timer();
  Setup_SSD_1306();
  Wifi_Connect();
}

void Run_System ()
{
  if(flag_pause == 1)
  {
    /* Doc trang thai cua Lazer */
    stt_lazer_old = stt_lazer_new;
    stt_lazer_new = digitalRead(LAZER);
    if((stt_lazer_old == 0) && (stt_lazer_new == 1) && (flag_state == 0))
    {
      count_stt++;
      flag_state = 1;
      delay_state_timer = millis();
    }

    /* Doc trang thai cua nut nhan */
    stt_button_old = stt_button_new;
    stt_button_new = digitalRead(BUTTON_RST);
    if((stt_button_new == 0) && (stt_button_old == 1))
    {
      flag_save = 1;

      racing_time_ms = 0;
      racing_time_second = 0;
      racing_time_minute = 0;

      count_stt = 0;
    }
    
    /* Sau 5s moi nhan lai trang thai cua Lazer */
    if(((delay_state_timer + 5000) < millis()) && (flag_state == 1))
    {
      flag_state = 0;
    }

    if(flag_save == 1)
    {
      count_reset++;

      Reset_SSD_1306();
      if((flag_http_rst == 1) && (flag_save == 1))
      {
        HTTP_GETRequest(DOOR, STOP, 0);
        flag_http_rst = 0;
      }
      
      if(count_reset == 100)
      {
        count_reset = 0;
        
        flag_http_rst = 1;
        flag_http_start = 1;

        racing_time_ms = 0;
        racing_time_second = 0;
        racing_time_minute = 0;

        flag_save = 0;
      }
    }
    else
    {
      if(count_stt == 0)
      { 
        Waiting_SSD_1306();
      }
      if(count_stt == 1)
      {
        Start_SSD_1306();
        if((count_stt == 1) && (flag_http_start ==1))
        {
          HTTP_GETRequest(DOOR, START, 0);
          flag_http_start = 0;
        }
      }
      if(count_stt == 2)
      {
        time_run_total = racing_time_minute*60000 + racing_time_second*1000 + racing_time_ms;
        
        Stop_SSD_1306();
        if((count_stt == 2) && (flag_http_stop == 1))
        {
          HTTP_GETRequest(DOOR, STOP, time_run_total);
          flag_http_stop = 0;
        }
      }
    }
    flag_pause = 0;
  }
}
