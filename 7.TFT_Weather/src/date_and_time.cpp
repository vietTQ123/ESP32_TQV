#include <date_and_time.h>


const char* ntpServer = "pool.ntp.org";
const long  gmtOffset_sec = 21600;
const int   daylightOffset_sec = 3600;


void Time_setup(){
    configTime(gmtOffset_sec, daylightOffset_sec, ntpServer);
    Print_local_time();
}


void Print_local_time(){
  struct tm timeinfo;
  if(!getLocalTime(&timeinfo)){
    Serial.println("Failed to obtain time");
    return;
  }
  Serial.println(&timeinfo, "%A, %B %d %Y %H:%M:%S");
}
