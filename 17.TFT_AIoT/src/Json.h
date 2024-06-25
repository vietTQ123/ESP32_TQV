#ifndef __JSON__
#define __JSON__

#include "ArduinoJson.h"
extern String data_weekday;
extern String data_date;
extern String data_month;
extern String data_year;
extern String data_seconds;
extern String data_minutes;
extern String data_hour;
extern int data_button;
extern int data_signal;

void Send_Data(int temperature, int humidity);
void Receive_Data();

#endif