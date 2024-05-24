#include <Screen_TFT.h>

TFT_eSPI tft = TFT_eSPI();

void TFT_Setup()
{
    Serial.begin(9600);
    
    tft.init();
    tft.setRotation(0);
    tft.fillScreen(TFT_WHITE);
    tft.setSwapBytes(true);

    tft.pushImage(0,0,240,240,sky);
}

void TFT_Screen(int temperature, int humidity)
{   

    tft.setFreeFont(&FreeSans12pt7b);
    tft.setTextColor(TFT_WHITE);
    tft.drawString ("AIoT PTIT",65,35);

    tft.setFreeFont(&Oswald_Regular24pt7b);
    tft.setTextColor(TFT_WHITE);
    tft.drawString ((String) temperature,30,80);
    tft.drawCircle(85, 90, 5, TFT_WHITE);
    tft.setFreeFont(&FreeSansBold12pt7b);
    tft.drawString("C",98,85);

    tft.setFreeFont(&FreeMono24pt7b);
    tft.drawString("|",115,85);

    tft.setFreeFont(&Oswald_Regular24pt7b);
    tft.setTextColor(TFT_WHITE);
    tft.drawString ((String) humidity,145,80);
    tft.drawString ("%",200,93,4);
}

void TFT_Clean(void)
{
    tft.pushImage(0,0,240,240,sky);
}


// #define TFT_MOSI 15 // In some display driver board, it might be written as "SDA" and so on.
// #define TFT_SCLK 14
// #define TFT_CS   5  // Chip select control pin
// #define TFT_DC   27  // Data Command control pin
// #define TFT_RST  33  // Reset pin (could connect to Arduino RESET pin)

// #define TOUCH_CS 21     // Chip select pin (T_CS) of touch screen