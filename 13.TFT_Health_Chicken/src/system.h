#ifndef __SYSTEM__
#define __SYSTEM__


#include <Arduino.h>
#include <TFT_eSPI.h>
#include <SPI.h>
#include <FS.h>
#include <SPIFFS.h>
#include <img.h>


void TFT_Setup (void);
void TFT_Healthy_Chicken (void);
void TFT_Unhealthy_Chicken (void);

#endif