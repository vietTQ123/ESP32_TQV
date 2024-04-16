#ifndef _LIB_HTTP_H_
#define _LIB_HTTP_H_

#include <WiFi.h>
#include <Arduino.h>
#include <ESP32Ping.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>
#include <system.h>

#define DEGUB_CONNECT_WIFI 1

extern const char *ssid;
extern const char *password;

void Wifi_Connect(void);
String HTTP_GETRequest(String id, String stt);

#endif
