#ifndef __SYSTEM__
#define __SYSTEM__

#include <wifi_scan.h>
#include <SPI.h>
#include <FS.h>
#include <SPIFFS.h>
#include <date_and_time.h>
#include <weather.h>
#include <TFT_eSPI.h>
#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <EEPROM.h>
#include <img.h>
#include <lvgl.h>

#include "Fonts/GFXFF/DSEG7_Classic_Mini_Bold_40.h"
#include "Fonts/GFXFF/SFProText_Semibold10pt7b.h"  
#include "Fonts/GFXFF/SFProText_Semibold12pt7b.h"
#include "Fonts/GFXFF/Notably_Absent_DEMO12pt7b.h"

#define RED2RED 0
#define GREEN2GREEN 1
#define BLUE2BLUE 2
#define BLUE2RED 3
#define GREEN2RED 4
#define RED2GREEN 5
#define LBLUE2DBLUE 6

#define EEPROM_SIZE 32


void Setup_weather();
void Run_weather();

void Load_credentials();
void Save_credentials();

#endif