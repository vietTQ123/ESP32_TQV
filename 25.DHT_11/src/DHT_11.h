#ifndef __DHT_11__
#define __DHT_11__

#include "Arduino.h"
#include "DHT.h"
#include "Adafruit_Sensor.h"

#define PIN_DHT_11 26
#define TYPE_DHT_11 DHT11

void DHT11_Setup(void);
int DHT11_Temperature(void);
int DHT11_Humidity(void);

#endif