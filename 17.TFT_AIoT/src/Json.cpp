#include "Json.h"

void Send_Data(int temperature, int humidity)
{
    StaticJsonDocument<200> doc;

    doc["Temperature"] = temperature;
    doc["Humidity"] = humidity;

    serializeJson(doc, Serial);
  
    Serial.println(); // Kết thúc dòng
}