#ifndef _Screen_TFT_
#define _Screen_TFT_

#include <Arduino.h>
#include <TFT_eSPI.h>
#include <SPI.h>
#include <img.h>
#include <Fonts/GFXFF/nulshock_bd9pt7b.h>
#include <Fonts/GFXFF/nulshock_bd12pt7b.h>

void TFT_Setup(void);
void TFT_Screen(void);

#endif