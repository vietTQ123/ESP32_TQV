#include <system.h>

TFT_eSPI tft = TFT_eSPI();


void TFT_Setup()
{
    Serial.begin(115200);

    tft.init();
    tft.setRotation(2);
    tft.fillScreen(TFT_WHITE);
    tft.setSwapBytes(true);

    tft.pushImage(0, 192, 120, 120, healthy_chicken);
    tft.pushImage(120, 192, 120, 120, unhealthy_chicken);

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

void TFT_Healthy_Chicken()
{
    tft.fillRect(0,100,119,50,TFT_WHITE);
    tft.drawString("20",27,100,7);
} 

void TFT_Unhealthy_Chicken()
{
    tft.fillRect(122,100,119,50,TFT_WHITE);
    tft.drawString("11",145,100,7);
}

// tọa độ 1 : 37,100,7 / 157,100,7
// tọa độ 0,2,3,4,5,6,7,8,9 : 45,100,7 / 167,100,7
// tọa độ 10 -> 20 : 27,100,7 / 145,100,7