#ifndef __JSON__
#define __JSON__

#include "ArduinoJson.h"

extern uint8_t data_signal;
extern String data_weekday;
extern String data_date;
extern String data_month;
extern String data_year;
extern int data_seconds;
extern int data_minutes;
extern int data_hour;
extern int data_button;

void Send_Data(int temperature, int humidity);
uint8_t Receive_Data();

#endif