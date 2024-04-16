#ifndef __SSD1306__
#define __SSD1306__

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <SPI.h>
#include "timmer.h"

#include <Fonts/FreeSansBold9pt7b.h>
// #include <Fonts/DSEG7_Classic_Bold_22.h>
#include <Fonts/DSEG7_Classic_Bold_16.h>

#define SCREEN_I2C_ADDR 0x3C 
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

void Setup_SSD_1306 (void);
void Waiting_SSD_1306 (void);
void Start_SSD_1306 (void);
void Reset_SSD_1306 (void);
void Stop_SSD_1306 (void);
void Connecting_SSD_1306 (void);
void Connected_SSD_1306(void);

#endif