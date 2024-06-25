#include "Json.h"

String data_weekday;
String data_date;
String data_month;
String data_year;
int data_seconds;
int data_minutes;
int data_hour;
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

        DynamicJsonDocument doc(1024);

        DeserializationError error = deserializeJson(doc, jsonMessage);

        if (error)
        {
            Serial.print("deserializeJson() failed: ");
            Serial.println(error.f_str());
            return;
        }

        data_weekday = doc["Weekday"].as<String>();
        data_date = doc["Date"].as<String>();
        data_month = doc["Month"].as<String>();
        data_year = doc["Year"].as<String>();
        data_seconds = doc["Seconds"].as<int>();
        data_minutes = doc["Minutes"].as<int>();
        data_hour = doc["Hour"].as<int>();
        data_button = doc["Button"].as<int>();
        data_signal = doc["Signal"].as<int>();
    }
}