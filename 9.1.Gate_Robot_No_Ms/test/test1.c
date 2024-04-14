#include <Arduino.h>
#include <mqtt.h>
#include <ssd1306.h>
#include <timmer.h>

#define BUTTON_RST 5
#define LAZER 12

int stt_button_new=1;
int stt_button_old;
int stt_lazer_new=0;
int stt_lazer_old;
int count=0;
int flag_save=0;
int count_reset=0;
uint32_t delay_state_timer = 0;
int8_t flag_state = 0;

void setup()
{
  Serial.begin(9600);
  Set_up();
  Setup_Timer();
  Setup_SSD_1306();

  pinMode(BUTTON_RST,INPUT); 
  pinMode(LAZER,INPUT);
}

void loop() 
{
  if(flag_pause==1)
  {
    client.loop();
    client.subscribe(topic_sub);

    stt_lazer_old=stt_lazer_new;
    stt_lazer_new=digitalRead(LAZER);
    if(stt_lazer_old==1 && stt_lazer_new==0 && flag_state == 0)
    {
      count++;
      flag_state = 1;
      delay_state_timer = millis();
    }

    if(delay_state_timer + 5000 < millis() && flag_state == 1)
    {
      flag_state = 0;
    }

    stt_button_old=stt_button_new;
    stt_button_new=digitalRead(BUTTON_RST);
    if(stt_button_new == 0 && stt_button_old == 1)
    {
      flag_save=1;
      count=0;
    }
    if(flag_save==1)
    {
      count_reset++;
      Reset_SSD_1306();
      client.publish(topic_pub, Rst);
      if(count_reset==60)
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
        client.publish(topic_pub, Wait);
      }
      if(count==1)
      {
        Start_SSD_1306();
        client.publish(topic_pub, Start);
      }
      if(count==2)
      {
        Stop_SSD_1306();
        client.publish(topic_pub, Stop);
      }
    }
    flag_pause=0;
  }
}