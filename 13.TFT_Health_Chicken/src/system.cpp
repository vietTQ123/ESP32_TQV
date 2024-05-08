#include <system.h>

TFT_eSPI tft = TFT_eSPI();


void TFT_Setup()
{
    Serial.begin(115200);

    tft.init();
    tft.setRotation(2);
    tft.fillScreen(TFT_WHITE);
    tft.setSwapBytes(true);
    
    tft.pushImage(0, 100, 256, 256, unhealthy_chicken);

    tft.setFreeFont(&FreeSansBold12pt7b);

    tft.setTextColor(TFT_RED);
    tft.drawString("UNHEALTHY", 45, 25);
}


void TFT_Unhealthy_Chicken()
{
    tft.fillRect(0,70,240,50,TFT_WHITE);
    tft.setTextColor(TFT_BLACK);
    tft.drawString("1",90,70,7);
}

// tọa độ 1 : 90,70,7
// tọa độ 0,2,3,4,5,6,7,8,9 : 100,70,7
// tọa độ 10 -> 20 : 88,70,7
