#ifndef __Module_DHT__
#define __Module_DHT__

#include "Adafruit_Sensor.h"
#include "DHT.h"

#define DHTPIN 19
#define DHTTYPE DHT11

void Dht_setup(void);
int Current_temp(void);
int Current_humi(void);

#endif
