#ifndef _Screen_TFT_
#define _Screen_TFT_

#include <Arduino.h>
#include <TFT_eSPI.h>
#include <SPI.h>
#include <img.h>
#include <Fonts/GFXFF/Oswald_Regular35pt7b.h>
#include <Fonts/GFXFF/Oswald_Regular16pt7b.h>
#include <Fonts/GFXFF/Oswald_Regular12pt7b.h>
#include <Fonts/GFXFF/Oswald_Regular24pt7b.h>
#include <Fonts/GFXFF/Roboto_Bold35pt7b.h>
#include <Fonts/GFXFF/Roboto_Bold12pt7b.h>
#include <BME_280.h>

void TFT_Setup(void);
void TFT_Screen_Temperature(int temperature, int humidity);
void TFT_Screen_Clock(/*String day, String date, String month, int hour, int minute*/);
void TFT_Clear_Temperature(void);
void TFT_Clear_Clock(void);

#endif