#include "Screen_TFT.h"
#include "Module_DHT.h"
#include "Json.h"

int temperature_new;
int temperature_old;
int humidity_new;
int humidity_old;

void setup()
{

  TFT_Setup();
  Dht_setup();

}

void loop()
{
  Send_Data(Current_temp(),Current_humi());

  temperature_new = Current_temp();
  humidity_new = Current_humi();

  if (temperature_new != temperature_old)
  {

    TFT_Clear();

    temperature_old = temperature_new;

  }

  if (humidity_new != humidity_old)
  {

    TFT_Clear();

    humidity_old = humidity_new;

  }
  
  TFT_Screen(Current_temp(), Current_humi());
}