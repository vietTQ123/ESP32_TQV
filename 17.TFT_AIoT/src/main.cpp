#include "Screen_TFT.h"
#include "Json.h"
#include "BME_280.h"

int temperature_new;
int temperature_old;
int humidity_new;
int humidity_old;
int button_new;
int button_old;
int count_srceen = 0;
int flag_srceen_1 = 0;
int flag_srceen_2 = 0;
int button = 16;

void setup()
{
  pinMode(button, INPUT);
  TFT_Setup();
  BME_280_setup();
}

void loop()
{
  button_old = button_new;
  button_new = digitalRead(button);

  Send_Data(BME_Temp(), BME_Humi());

  temperature_new = BME_Temp();
  humidity_new = BME_Humi();

  if (button_new == 0 && button_old == 1)
  {
    count_srceen++;
    flag_srceen_1 = 1;
    flag_srceen_2 = 1;
    if(count_srceen == 2)
    {
      count_srceen = 0;
    }
  }

  if (count_srceen % 2 == 0)
  {
    if (flag_srceen_1 == 1)
    {
      TFT_Clear_Temperature();
      flag_srceen_1 = 0;
    }

    if (temperature_new != temperature_old)
    {

      TFT_Clear_Temperature();

      temperature_old = temperature_new;
    }

    if (humidity_new != humidity_old)
    {

      TFT_Clear_Temperature();

      humidity_old = humidity_new;
    }

    TFT_Screen_Temperature(BME_Temp(), BME_Humi());
  }
  else
  {
    if (flag_srceen_2 == 1)
    {
      TFT_Clear_Clock();
      flag_srceen_2 = 0;
    }

    TFT_Screen_Clock();
  }

}