#ifndef _MQTT_H_
#define _MQTT_H_

#include <ArduinoJson.h>
#include <Arduino.h>
#include <Wire.h>
#include <WiFiUdp.h>
#include <WiFiClient.h>
#include <PubSubClient.h>
#include <WiFi.h>
#include <system.h>

extern WiFiClient espClient;
extern PubSubClient client;

extern char Wait[1000];
extern char Rst[1000];
extern char Start[1000];
extern char Stop[1000];
extern char buffer[1000];

extern uint8_t flag_mqtt_pubish;

extern const char *mqtt_broker;
extern const char *topic_pub;
extern const char *topic_sub;
extern const char *mqtt_username;
extern const char *mqtt_password;
extern const int mqtt_port;

extern const char *ssid;
extern const char *password;

void callback(char *topic, byte *payload, unsigned int length);
void MQTT_Connect();
void Set_up();
void run();
void connect_to_broker();

#endif
