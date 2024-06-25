#include "Json.h"

String data_weekday;
String data_date;
String data_month;
String data_year;
String data_seconds;
String data_minutes;
String data_hour;
int data_button;
int data_signal;

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

        DynamicJsonDocument doc (1024) ; 

        DeserializationError error = deserializeJson(doc, jsonMessage); 

        if (error) 
        {
            Serial.print("deserializeJson() failed: ");
            Serial.println(error.f_str());
            return;
        }

        // data_weekday = doc["Weekday"];
        // data_date = doc["Date"];
        // data_month = doc["Month"];
        // data_year = doc["Year"];
        // data_seconds = doc["Seconds"];
        // data_minutes = doc["Minutes"];
        // data_hour = doc["Hour"];
        data_button = doc["Button"];
        data_signal = doc["Signal"];
    }

}