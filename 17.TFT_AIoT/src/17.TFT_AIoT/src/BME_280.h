#ifndef __BME_280__
#define __BME_280__

#include "Wire.h"
#include "Adafruit_Sensor.h"
#include "Adafruit_BME280.h"

#define SEALEVELPRESSURE_HPA (1013.25)

void BME_280_setup(void);
int BME_Temp(void);
int BME_Humi(void);

#endif