#ifndef __SYSTEM__
#define __SYSTEM__


#include <Arduino.h>
#include <TFT_eSPI.h>
#include <SPI.h>
#include <FS.h>
#include <SPIFFS.h>
#include <img.h>


void setup_tft();
void run_tft();
void on();
void off();
void tapping();
void mount_fault();
void flow_blocked();
void blade_fault();

#endif