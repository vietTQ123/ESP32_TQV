#ifndef  __DATE_AND_TIME__
#define  __DATE_AND_TIME__

#include <time.h>
#include <Arduino.h>

extern const char* ntpServer;
extern const long gmtOffset_sec;
extern const int daylightOffset_sec;

void Print_local_time();
void Time_setup();

#endif