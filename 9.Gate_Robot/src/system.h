#ifndef __SYSTEM__
#define __SYSTEM__

#include <Arduino.h>
#include <ssd1306.h>
#include <timmer.h>
#include <lib_http.h>

#define BUTTON_RST 5
#define LAZER 12

#define DOOR    "door1"
#define START   "start"
#define STOP    "stop"

extern int count_stt;

extern uint8_t flag_http_rst;
extern uint8_t flag_http_start;
extern uint8_t flag_http_stop;

void Run_System ();
void Setup_System ();

#endif
