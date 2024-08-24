#include <LM393.h>

void setup()
{
  Serial.begin(9600);
  LM393_Setup();
}

void loop()
{
  LM393_Soil_Moisture();
  delay(500);
}
