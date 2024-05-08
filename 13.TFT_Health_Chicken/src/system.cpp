#include <system.h>

TFT_eSPI tft = TFT_eSPI();


void TFT_Setup()
{
    Serial.begin(115200);

    tft.init();
    tft.setRotation(2);
    tft.fillScreen(TFT_WHITE);
    tft.setSwapBytes(true);

    tft.pushImage(120, 35, 120, 120, healthy_chicken);
    tft.pushImage(120, 195, 120, 120, unhealthy_chicken);

    tft.setFreeFont(&FreeSansBold12pt7b);

    tft.setTextColor(TFT_GREEN);
    tft.drawString("HEALTHY", 12, 10);

    tft.setTextColor(TFT_RED);
    tft.drawString("UNHEALTHY", 3, 170);

    tft.drawFastHLine(0,160,240,TFT_BLACK);

}

void TFT_Healthy_Chicken()
{
    tft.fillRect(0,55,120,50,TFT_WHITE);
    tft.setTextColor(TFT_BLACK);
    tft.drawString("20",23,55,7);
} 

void TFT_Unhealthy_Chicken()
{
    tft.fillRect(0,215,120,50,TFT_WHITE);
    tft.setTextColor(TFT_BLACK);
    tft.drawString("20",23,215,7);
}

// tọa độ 1 : 33,55,7 / 33,215,7
// tọa độ 0,2,3,4,5,6,7,8,9 : 35,55,7 / 35,215,7
// tọa độ 10 -> 20 : 23,55,7 / 23,215,7
