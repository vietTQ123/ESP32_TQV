#ifndef __SYSTEM__
#define __SYSTEM__

#include <Arduino.h>
#include <mqtt.h>
#include <ssd1306.h>
#include <timmer.h>
// #include <http.h>

#define BUTTON_RST 5
#define LAZER 12

extern uint8_t flag_mqtt_rst;
extern uint8_t flag_mqtt_waiting;
extern uint8_t flag_mqtt_start;
extern uint8_t flag_mqtt_stop;

extern int count;
extern int flag_save;

void Run_System ();
void Setup_System ();

#endif