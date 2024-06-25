#include "Screen_TFT.h"
#include "Json.h"
#include "BME_280.h"
#include "timer.h"

int temperature_new;
int temperature_old;

int humidity_new;
int humidity_old;

int hour_new;
int hour_old;

int minutes_old;
int minutes_new;

String day_new;
String day_old;

String date_new;
String date_old;

String month_new;
String month_old;

int flag_srceen_1 = 1;
int flag_srceen_2 = 1;
int flag_send_data = 0;

int delay_send_data = 0;

void IRAM_ATTR check_status();

void setup()
{
  TFT_Setup();
  BME_280_setup();
  Setup_Timer();
}

void loop()
{
  Receive_Data();

  temperature_new = BME_Temp();
  humidity_new = BME_Humi();

  hour_new = data_hour;
  minutes_new = data_minutes;

  day_new = data_weekday;
  date_new = data_date;
  month_new = data_month;

  if (((delay_send_data + 5000) < millis()) && (flag_send_data == 1))
  {
    flag_send_data = 0;
  }

  if (flag_send_data == 0)
  {
    Send_Data(BME_Temp(), BME_Humi());
    flag_send_data = 1;
    delay_send_data = millis();
  }

  if (data_button == 0)
  {
    flag_srceen_2 = 1;

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
    flag_srceen_1 = 1;

    if (flag_srceen_2 == 1)
    {
      TFT_Clear_Clock();
      flag_srceen_2 = 0;
    }

    if (hour_new != hour_old)
    {
      TFT_Clear_Clock();

      hour_old = hour_new;
    }

    if (minutes_new != minutes_old)
    {
      TFT_Clear_Clock();

      minutes_old = minutes_new;
    }

    if (day_new != day_old)
    {
      TFT_Clear_Clock();

      day_old = day_new;
    }

    if (date_new != date_old)
    {
      TFT_Clear_Clock();

      date_old = date_new;
    }

    if (month_new != month_old)
    {
      TFT_Clear_Clock();

      month_old = month_new;
    }

    TFT_Screen_Clock(data_weekday, data_date, data_month, data_hour, data_minutes);
  }
}