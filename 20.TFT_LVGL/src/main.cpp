#include <Arduino.h>
#include <lvgl.h>
#include <TFT_eSPI.h>
#include <Json.h>
#include <timer.h>
#include <BME_280.h>
#include "ui.h"
#include <ezButton.h>

#define BUTTON_CHANGE 2

int flag_send_data = 0;
int delay_send_data = 0;

uint8_t is_device_connected = false;

typedef enum
{
    SCREEN_1,
    SCREEN_2,
    SCREEN_3,
    SCREEN_4,
    SCREEN_5,
} display_t;

display_t Screen_next = SCREEN_1;

// Nut nhan
ezButton button(BUTTON_CHANGE);

// Dong ho kim
#define ONE_MINUTE_MS (60 * 1000)
#define ONE_HOUR_MS (60 * 60 * 1000)
#define TWELVE_HOUR_MS (12 * 60 * 60 * 1000)

static unsigned long ms_offset;

unsigned long ms = millis();

// LVGL
static const uint16_t screenWidth = 240;
static const uint16_t screenHeight = 240;

static lv_disp_draw_buf_t draw_buf;
static lv_color_t buf[screenWidth * screenHeight / 10];

TFT_eSPI tft = TFT_eSPI(screenWidth, screenHeight); /* TFT instance */

/* Display flushing */
void my_disp_flush(lv_disp_drv_t *disp_drv, const lv_area_t *area, lv_color_t *color_p);

void IRAM_ATTR check_status();

void setup()
{
    Serial.begin(115200); /* prepare for possible serial debug */
    Serial2.begin(115200, SERIAL_8N1, 16, 17);

    String LVGL_Arduino = "Hello Arduino! ";
    LVGL_Arduino += String('V') + lv_version_major() + "." + lv_version_minor() + "." + lv_version_patch();

    Serial.println(LVGL_Arduino);
    Serial.println("I am LVGL_Arduino");

    lv_init();

    tft.begin();        /* TFT init */
    tft.setRotation(3); /* Landscape orientation, flipped */

    lv_disp_draw_buf_init(&draw_buf, buf, NULL, screenWidth * screenHeight / 10);

    /*Initialize the display*/
    static lv_disp_drv_t disp_drv;
    lv_disp_drv_init(&disp_drv);

    /*Change the following line to your display resolution*/
    disp_drv.hor_res = screenWidth;
    disp_drv.ver_res = screenHeight;
    disp_drv.flush_cb = my_disp_flush;
    disp_drv.draw_buf = &draw_buf;
    lv_disp_drv_register(&disp_drv);

    /*Initialize the (dummy) input device driver*/
    static lv_indev_drv_t indev_drv;
    lv_indev_drv_init(&indev_drv);
    indev_drv.type = LV_INDEV_TYPE_POINTER;
    lv_indev_drv_register(&indev_drv);

    /* Create simple label */
    lv_obj_t *label = lv_label_create(lv_scr_act());
    lv_label_set_text(label, "Hello Ardino and LVGL!");
    lv_obj_align(label, LV_ALIGN_CENTER, 0, 0);

    ui_init();

    lv_disp_load_scr(ui_Screen2);

    BME_280_setup();

    Setup_Timer();

    ms = millis();
}

void loop()
{

    if (Receive_Data())
    {
        uint8_t hh = data_hour;
        uint8_t mm = data_minutes;
        uint8_t ss = data_seconds;
        ms_offset = ((60 * 60 * hh) + (60 * mm) + ss) * 1000 - ms;

        is_device_connected = data_signal;

        if(is_device_connected == 0){
            lv_disp_load_scr(ui_Screen5);
        }
        else{
            lv_disp_load_scr(ui_Screen2);
            Screen_next = SCREEN_2;
        }
    }

    lv_timer_handler(); /* let the GUI do its work */

    if(is_device_connected == 0){
        return;
    }

    if (((delay_send_data + 5000) < millis()) && (flag_send_data == 1))
    {
        flag_send_data = 0;
    }

    if (flag_send_data == 0)
    {
        Send_Data(BME_Temp(), BME_Humi());

        flag_send_data = 1;
        delay_send_data = millis();
    }

    button.loop();

    if (button.isPressed())
    {
        switch (Screen_next)
        {
        case SCREEN_1:
            lv_disp_load_scr(ui_Screen2);
            Screen_next = SCREEN_2;
            break;
        case SCREEN_2:

            lv_disp_load_scr(ui_Screen3);
            Screen_next = SCREEN_3;
            break;
        case SCREEN_3:
            lv_disp_load_scr(ui_Screen4);
            Screen_next = SCREEN_1;
            break;
        default:
            break;
        }
    }

    ms = millis();
    unsigned long clock_ms = (ms_offset + ms) % TWELVE_HOUR_MS;

    uint8_t hour = clock_ms / ONE_HOUR_MS;
    uint8_t minute = (clock_ms % ONE_HOUR_MS) / ONE_MINUTE_MS;
    int16_t angle = (clock_ms % ONE_MINUTE_MS) * 3600 / ONE_MINUTE_MS;

    lv_img_set_angle(ui_ImageArmSecond, angle);
    angle = (angle + (minute * 3600)) / 60;
    lv_img_set_angle(ui_ImageArmMinute, angle);
    angle = (angle + (hour * 3600)) / 12;
    lv_img_set_angle(ui_ImageArmHour, angle);

    lv_label_set_text(ui_TEMP, String(BME_Temp()).c_str());
    lv_label_set_text(ui_HUMI, String(BME_Humi()).c_str());

    data_weekday.toUpperCase();
    data_date.toUpperCase();
    data_month.toUpperCase();

    lv_label_set_text(ui_Day, data_weekday.c_str());
    lv_label_set_text(ui_Date, data_date.c_str());
    lv_label_set_text(ui_month, data_month.c_str());

    lv_label_set_text(ui_hour_1, String((data_hour / 10) % 10).c_str());
    lv_label_set_text(ui_hour_2, String((data_hour) % 10).c_str());
    lv_label_set_text(ui_Label16, ":");
    lv_label_set_text(ui_minute_1, String((data_minutes / 10) % 10).c_str());
    lv_label_set_text(ui_minute_2, String((data_minutes) % 10).c_str());
}

void my_disp_flush(lv_disp_drv_t *disp_drv, const lv_area_t *area, lv_color_t *color_p)
{
    uint32_t w = (area->x2 - area->x1 + 1);
    uint32_t h = (area->y2 - area->y1 + 1);

    tft.startWrite();
    tft.setAddrWindow(area->x1, area->y1, w, h);
    tft.pushColors((uint16_t *)&color_p->full, w * h, true);
    tft.endWrite();

    lv_disp_flush_ready(disp_drv);
}