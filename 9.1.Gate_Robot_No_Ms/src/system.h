#ifndef __SYSTEM__
#define __SYSTEM__

#include <Arduino.h>
#include <mqtt.h>
#include <ssd1306.h>
#include <timmer.h>
#include <lib_http.h>

#define DOOR "door2"
#define START "start"
#define STOP "stop"

#define BUTTON_RST 5
#define LAZER 12

extern int count;
extern int flag_save;

extern uint8_t flag_http_rst;
extern uint8_t flag_http_start;
extern uint8_t flag_http_stop;

void Run_System ();
void Setup_System ();

#endif