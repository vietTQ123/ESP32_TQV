#ifndef _Screen_TFT_
#define _Screen_TFT_

#include <Arduino.h>
#include <TFT_eSPI.h>
#include <SPI.h>
#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <img.h>
#include <Fonts/GFXFF/Oswald_Regular35pt7b.h>
#include <Fonts/GFXFF/Oswald_Regular16pt7b.h>
#include <Fonts/GFXFF/Oswald_Regular12pt7b.h>
#include <Fonts/GFXFF/Oswald_Regular24pt7b.h>

#define DHTPIN 16
#define DHTTYPE DHT11

void TFT_Setup(void);
void TFT_Screen(void);

#endif