#include "BME_280.h"

Adafruit_BME280 bme;

void BME_280_setup()
{
  bool status;

  status = bme.begin(0x76);  
  if (!status) {
    Serial.println("Could not find a valid BME280 sensor, check wiring!");
    while (1);
  }
}

int BME_Temp()
{
  int temp = bme.readTemperature();
  return temp;
}

int BME_Humi()
{
  int humi = bme.readHumidity();
  return humi;
}