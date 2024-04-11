#ifndef __SYSTEM__
#define __SYSTEM__

#include <wifi_scan.h>
#include <SPI.h>
#include <FS.h>
#include <SPIFFS.h>
#include <date_and_time.h>
#include <weather.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ILI9341.h>
#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <EEPROM.h>
#include <img.h>

#include "Fonts/DSEG7_Classic_Mini_Bold_40.h"
#include "Fonts/Dialog_plain_18.h"
#include "Fonts/Dialog_plain_20.h"
#include "Fonts/Dialog_plain_12.h"
#include "Fonts/Dialog_Bold_25.h"
#include "Fonts/SFProText_Semibold10pt7b.h"
#include "Fonts/SFProText_Semibold12pt7b.h"
#include "Fonts/VarsityTeam_Bold10pt7b.h"
#include "Fonts/Notably_Absent_DEMO12pt7b.h"

#define TFT_cs 15
#define TFT_dc 2
#define TFT_mosi 23
#define TFT_sclk 18
#define TFT_rst 4
#define TFT_miso 19

#define touch_cs 21

#define RED2RED 0
#define GREEN2GREEN 1
#define BLUE2BLUE 2
#define BLUE2RED 3
#define GREEN2RED 4
#define RED2GREEN 5
#define LBLUE2DBLUE 6

#define LOAD_FONT2 // Font 2. Small 16 pixel high font, needs ~3534 bytes in FLASH, 96 characters
#define LOAD_FONT4 // Font 4. Medium 26 pixel high font, needs ~5848 bytes in FLASH, 96 characters
#define LOAD_FONT6 // Font 6. Large 48 pixel font, needs ~2666 bytes in FLASH, only characters 1234567890:-.apm
#define LOAD_FONT7 // Font 7. 7 segment 48 pixel font, needs ~2438 bytes in FLASH, only characters 1234567890:-.
#define LOAD_FONT8

#define EEPROM_SIZE 32


void Setup_weather();
void Run_weather();

void Load_credentials();
void Save_credentials();

#endif