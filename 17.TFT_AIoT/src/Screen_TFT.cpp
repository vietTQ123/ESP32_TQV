#include <Screen_TFT.h>

TFT_eSPI tft = TFT_eSPI();

// int temperature_new;
// int temperature_old;
// int humidity_new;
// int humidity_old;

void TFT_Setup(void)
{
    Serial.begin(9600);
    
    tft.init();
    tft.setRotation(0);
    tft.fillScreen(TFT_WHITE);
    tft.setSwapBytes(true);

    tft.pushImage(0,0,240,240,sky);
}

void TFT_Screen_Temperature(int temperature, int humidity)
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

 void TFT_Screen_Clock(/*String day, String date, String month, int hour, int minute*/)
{
    tft.setFreeFont(&FreeSans12pt7b);
    tft.setTextColor(TFT_WHITE);
    tft.drawString ("SUN",54,55);
    tft.drawString ("16",107,55);
    tft.drawString ("JUN",137,55);

    tft.setFreeFont(&Roboto_Bold35pt7b);
    // tft.setTextColor(TFT_WHITE);
    // tft.setCursor(25,85);
    // tft.print((hour / 10) % 10);
    // tft.setCursor(65,85);
    // tft.print(hour % 10);
    // tft.setCursor(110,85);
    // tft.print(":");
    // tft.setCursor(135,85);
    // tft.print((minute / 10) % 10);
    // tft.setCursor(175,85);
    // tft.print(minute % 10);

    tft.drawString ("0",25,85);
    tft.drawString ("0",65,85);
    tft.drawString (":",110,85);
    tft.drawString ("0",135,85);
    tft.drawString ("0",175,85);
}

void TFT_Clear_Clock(void)
{
    tft.pushImage(0,0,240,240,castle);
}

void TFT_Clear_Temperature(void)
{
    tft.pushImage(0,0,240,240,sky);
}
