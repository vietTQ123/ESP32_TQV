#include "Json.h"

void Send_Data(int temperature, int humidity)
{
    StaticJsonDocument<200> doc;

    doc["Temperature"] = temperature;
    doc["Humidity"] = humidity;

    serializeJson(doc, Serial);
  
    Serial.println(); 
}

void Receive_Data()
{
    if (Serial.available()) 
    {
        String jsonMessage = Serial.readStringUntil('\n'); 

        StaticJsonDocument<200> doc; 

        DeserializationError error = deserializeJson(doc, jsonMessage); 

        if (error) 
        {
            Serial.print("deserializeJson() failed: ");
            Serial.println(error.f_str());
            return;
        }
    }
}