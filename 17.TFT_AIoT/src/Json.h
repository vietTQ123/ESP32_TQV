#ifndef __JSON__
#define __JSON__

#include "ArduinoJson.h"

#define LED_STATUS 25

extern String data_weekday;
extern String data_date;
extern String data_month;
extern String data_year;
extern int data_seconds;
extern int data_minutes;
extern int data_hour;
extern int data_button;
extern int data_signal;

void Send_Data(int temperature, int humidity);
void Receive_Data();

#endif