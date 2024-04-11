#ifndef  __WEATHER__
#define  __WEATHER__

#include <HTTPClient.h>
// #include <Arduino_JSON.h>
#include <Arduino.h>
#include <WiFi.h>
#include <WiFiUdp.h>

void       Dht_setup();
int       Current_temp();
int       Current_humi();

#include <DHT.h>

#define DHTPIN 33
#define DHTTYPE DHT11

extern String Apikey;
extern String city;
extern String countryCode;
extern unsigned long lastTime;
extern unsigned long timerDelay;
extern String jsonBuffer;

void Weather_Infor();
String httpGETRequest(const char* serverName);

#endif