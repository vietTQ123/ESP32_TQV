#include "LM393.h"

void LM393_Setup()
{
    pinMode(PIN_ANALOG_LM393, INPUT);
    pinMode(PIN_DIGITAL_LM393, INPUT);
}

int LM393_Soil_Moisture()
{
    int value = analogRead(PIN_ANALOG_LM393);
    int percent_dry = map(value, 0, 4095, 0, 100);
    int percent_water = 100 - percent_dry;

    Serial.print(value);
    Serial.print("  ");
    Serial.print(percent_dry);
    Serial.print("  ");
    Serial.println(percent_water);

    return percent_water;
}

int LM393_Check_Soil_Moisture()
{
    if(digitalRead(PIN_DIGITAL_LM393) == 0)
    {
        Serial.println(0);
        return 0;
    }
    else
    {
        Serial.println(1);
        return 1;
    }
}