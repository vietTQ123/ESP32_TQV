// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.4.1
// LVGL version: 8.3.11
// Project name: Srceen_AIoT_PTIT

#ifndef _SRCEEN_AIOT_PTIT_UI_H
#define _SRCEEN_AIOT_PTIT_UI_H

#ifdef __cplusplus
extern "C" {
#endif

#include "lvgl.h"

#include "ui_helpers.h"
#include "ui_events.h"

// SCREEN: ui_Screen2
void ui_Screen2_screen_init(void);
extern lv_obj_t * ui_Screen2;
extern lv_obj_t * ui_Image1;
extern lv_obj_t * ui_ImageArmHour;
extern lv_obj_t * ui_ImageArmMinute;
extern lv_obj_t * ui_ImageArmSecond;
// SCREEN: ui_Screen3
void ui_Screen3_screen_init(void);
extern lv_obj_t * ui_Screen3;
extern lv_obj_t * ui_Label2;
extern lv_obj_t * ui_TEMP;
extern lv_obj_t * ui_Label4;
extern lv_obj_t * ui_Label5;
extern lv_obj_t * ui_Label6;
extern lv_obj_t * ui_HUMI;
extern lv_obj_t * ui_Label8;
extern lv_obj_t * ui_Label12;
extern lv_obj_t * ui_Label13;
// SCREEN: ui_Screen4
void ui_Screen4_screen_init(void);
extern lv_obj_t * ui_Screen4;
extern lv_obj_t * ui_Day;
extern lv_obj_t * ui_Date;
extern lv_obj_t * ui_month;
extern lv_obj_t * ui_hour_1;
extern lv_obj_t * ui_hour_2;
extern lv_obj_t * ui_Label16;
extern lv_obj_t * ui_minute_1;
extern lv_obj_t * ui_minute_2;
// SCREEN: ui_Screen5
void ui_Screen5_screen_init(void);
extern lv_obj_t * ui_Screen5;
extern lv_obj_t * ui_Image2;
extern lv_obj_t * ui_Image3;
extern lv_obj_t * ui____initial_actions0;


LV_IMG_DECLARE(ui_img_bg_png);    // assets/bg.png
LV_IMG_DECLARE(ui_img_armhour_png);    // assets/armHour.png
LV_IMG_DECLARE(ui_img_armminute_png);    // assets/armMinute.png
LV_IMG_DECLARE(ui_img_armsecond_png);    // assets/armSecond.png
LV_IMG_DECLARE(ui_img_screen_temp_png);    // assets/Screen_Temp.png
LV_IMG_DECLARE(ui_img_screen_clock_png);    // assets/Screen_Clock.png
LV_IMG_DECLARE(ui_img_srceen_qr_png);    // assets/Srceen_QR.png



LV_FONT_DECLARE(ui_font_Oswald_Regular_24);
LV_FONT_DECLARE(ui_font_Oswald_Regular_46);
LV_FONT_DECLARE(ui_font_Roboto_Bold_80);
LV_FONT_DECLARE(ui_font_Saira_Stencil_One_Regular_30);
LV_FONT_DECLARE(ui_font_SFMono_Bold_30);



void ui_init(void);

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif
