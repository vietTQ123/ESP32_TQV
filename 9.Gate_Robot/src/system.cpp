#include "system.h"

int stt_button_new=1;
int stt_button_old;
int stt_lazer_new=0;
int stt_lazer_old;
int count=0;
int flag_save=0;
int count_reset=0;

uint32_t delay_state_timer = 0;
uint8_t flag_state = 0;

uint8_t flag_mqtt_rst=1;
uint8_t flag_mqtt_waiting=1;
uint8_t flag_mqtt_start=1;
uint8_t flag_mqtt_stop=1;

void Setup_System ()
{
  Serial.begin(9600);

  pinMode(BUTTON_RST,INPUT); 
  pinMode(LAZER,INPUT);

  Setup_Timer();
  Setup_SSD_1306();
  Setup_Mqtt();
}

void Run_System ()
{
  if(flag_pause==1)
  {
    client.loop();
    if (!client.connected())
    {
      connect_to_broker();
    }
    client.subscribe(topic_sub);

    stt_lazer_old = stt_lazer_new;
    stt_lazer_new = digitalRead(LAZER);
    if((stt_lazer_old == 0) && (stt_lazer_new == 1) && (flag_state == 0))
    {
      count++;
      flag_state = 1;
      delay_state_timer = millis();
    }

    if(((delay_state_timer + 5000) < millis()) && (flag_state == 1))
    {
      flag_state = 0;
    }

    stt_button_old = stt_button_new;
    stt_button_new = digitalRead(BUTTON_RST);
    if((stt_button_new == 0) && (stt_button_old == 1))
    {
      flag_save = 1;
      flag_mqtt_rst = 1;
      flag_mqtt_waiting = 1;
      flag_mqtt_start = 1;
      flag_mqtt_stop = 1;

      racing_time = 0;
      count = 0;
    }

    if((strcmp(buffer,"Reset")==0) && (flag_mqtt_pubish==1))
    {
      flag_save = 1;
      flag_mqtt_rst = 1;
      flag_mqtt_waiting = 1;
      flag_mqtt_start = 1;
      flag_mqtt_stop = 1;
      flag_mqtt_pubish = 0;

      racing_time=0;
      count = 0;
    
      buffer[1000]={};
    }

    if(flag_save == 1)
    {
      count_reset++;
      Reset_SSD_1306();
      if((flag_mqtt_rst==1) && (flag_save==1))
      {
        client.publish(topic_pub, Rst);
        flag_mqtt_rst=0;
      }
      if(count_reset==100)
      {
        count_reset=0;
        flag_save=0;
      }
    }
    else
    {
      if(count==0)
      { 
        Waiting_SSD_1306();
        if((count==0) && (flag_mqtt_waiting==1))
        {
          client.publish(topic_pub, Wait);
          flag_mqtt_waiting = 0;
        }
      }
      if(count==1)
      {
        Start_SSD_1306();
        if((count == 1) && (flag_mqtt_start ==1))
        {
          client.publish(topic_pub, Start);
          flag_mqtt_start = 0;
        }
      }
      if(count==2)
      {
        Stop_SSD_1306();
        if((count==2) && (flag_mqtt_stop==1))
        {
          client.publish(topic_pub, Stop);
          flag_mqtt_stop = 0;
        }
      }
    }
    flag_pause = 0;
  }
}