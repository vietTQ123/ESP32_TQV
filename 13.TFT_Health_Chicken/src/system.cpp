#include <system.h>

TFT_eSPI tft = TFT_eSPI();

void TFT_Setup()
{
    Serial.begin(115200);

    tft.init();
    tft.setRotation(2);
    tft.fillScreen(TFT_WHITE);
    tft.setSwapBytes(true);

    tft.fillRect(0,0,120,60,TFT_GREEN);
    tft.fillRect(120,0,120,60,TFT_RED);

    tft.setFreeFont(&FreeMonoBold9pt7b);

    tft.setTextColor(TFT_BLACK);
    tft.drawString("HEALTHY", 23, 23);

    tft.setTextColor(TFT_BLACK);
    tft.drawString("UNHEALTHY", 130, 23);

    tft.drawFastHLine(0,60,240,TFT_BLACK);
    tft.drawLine(120,0,120,320,TFT_BLACK);

}

void TFT_healthy()
{

}