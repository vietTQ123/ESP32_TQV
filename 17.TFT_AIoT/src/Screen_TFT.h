#ifndef _Screen_TFT_
#define _Screen_TFT_

#include <Arduino.h>
#include <TFT_eSPI.h>
#include <SPI.h>
#include <img.h>
#include <Fonts/GFXFF/DSEG7_Classic_Mini_Bold_30.h>
#include <Fonts/GFXFF/DSEG7_Classic_Mini_Bold_25.h>
#include <Fonts/GFXFF/Oswald_Regular35pt7b.h>
#include <Fonts/GFXFF/Oswald_Regular16pt7b.h>
#include <Fonts/GFXFF/Oswald_Regular12pt7b.h>
#include <Fonts/GFXFF/Oswald_Regular24pt7b.h>


void TFT_Setup(void);
void TFT_Screen(void);

#endif