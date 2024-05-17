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

void TFT_Screen()
{   
    tft.setFreeFont(&FreeSans12pt7b);
    tft.setTextColor(TFT_WHITE);
    tft.drawString ("AIoT PTIT",65,26);

    tft.setFreeFont(&Oswald_Regular24pt7b);
    tft.setTextColor(TFT_WHITE);
    tft.drawString ("29",30,70);
    tft.drawCircle(85, 80, 6, TFT_WHITE);
    tft.setFreeFont(&FreeSansBold12pt7b);
    tft.drawString("C",98,75);

    tft.setFreeFont(&FreeMono24pt7b);
    tft.drawString("/",115,75);

    tft.setFreeFont(&Oswald_Regular24pt7b);
    tft.setTextColor(TFT_WHITE);
    tft.drawString ("83",145,70);
    tft.drawString ("%",200,82,4);
}
