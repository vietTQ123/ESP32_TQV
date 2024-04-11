#ifndef __WIFI_SCAN__
#define __WIFI_SCAN__

#include <WiFi.h>
#include <WiFiUdp.h>
#include <Arduino.h>

extern char ssid[30];
extern char password[30];


void Scan_wifi();
void Connect_wifi();




#endif