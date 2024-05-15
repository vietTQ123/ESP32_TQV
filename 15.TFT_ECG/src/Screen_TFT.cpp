#include <Screen_TFT.h>

TFT_eSPI tft = TFT_eSPI();

void TFT_Setup()
{
    Serial.begin(9600);

    tft.init();
    tft.setRotation(2);
    tft.fillScreen(TFT_WHITE);
    tft.setSwapBytes(true);
    
    tft.pushImage(50,0,140,140,Screen_TFT);

    tft.setTextColor(ILI9341_BLACK);
    tft.setFreeFont(&nulshock_bd9pt7b);
    tft.drawString("ECG Classification",5,150);
}

void TFT_Screen()
{
    tft.setFreeFont(&nulshock_bd12pt7b);

    tft.setTextColor(ILI9341_BLACK);
    tft.drawString("N",67,175);
    tft.drawString("S",153,175);
    tft.drawString("V",30,240);
    tft.drawString("F",115,240);
    tft.drawString("Q",190,240);

    tft.setFreeFont(&nulshock_bd9pt7b);

    tft.setTextColor(ILI9341_BLACK);
    tft.setCursor(58,220);
    tft.println("100");

    tft.setTextColor(ILI9341_BLACK);
    tft.setCursor(143,220);
    tft.println("100");

    tft.setTextColor(ILI9341_BLACK);
    tft.setCursor(20,290);
    tft.println("100");

    tft.setTextColor(ILI9341_BLACK);
    tft.setCursor(100,290);
    tft.println("999");

    tft.setTextColor(ILI9341_BLACK);
    tft.setCursor(180,290);
    tft.println("100");

    // tft.fillRect(0,205,120,30,ILI9341_WHITE);
    // tft.fillRect(120,205,120,30,ILI9341_WHITE);
    // tft.fillRect(0,275,80,30,ILI9341_WHITE);
    // tft.fillRect(80,275,80,30,ILI9341_WHITE);
    // tft.fillRect(160,275,80,30,ILI9341_WHITE);
}