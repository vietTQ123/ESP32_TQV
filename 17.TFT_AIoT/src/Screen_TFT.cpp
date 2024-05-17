#include <Screen_TFT.h>

TFT_eSPI tft = TFT_eSPI();

DHT dht(DHTPIN, DHTTYPE);

int temperature_new;
int temperature_old;
int humidity_new;
int humidity_old;

void TFT_Setup()
{
    Serial.begin(9600);
    
    dht.begin();

    tft.init();
    tft.setRotation(0);
    tft.fillScreen(TFT_WHITE);
    tft.setSwapBytes(true);

    tft.pushImage(0,0,240,240,sky);
}

void TFT_Screen()
{   
    temperature_new = dht.readTemperature();
    humidity_new = dht.readHumidity();

    Serial.print(dht.readTemperature());
    Serial.print("   ");
    Serial.println(dht.readHumidity());

    if(temperature_new != temperature_old)
    {
        tft.pushImage(0,0,240,240,sky);

        temperature_old = temperature_new;
    }

    if(humidity_new != humidity_old)
    {
        tft.pushImage(0,0,240,240,sky);

        humidity_old = humidity_new;
    }

    tft.setFreeFont(&FreeSans12pt7b);
    tft.setTextColor(TFT_WHITE);
    tft.drawString ("AIoT PTIT",65,35);

    tft.setFreeFont(&Oswald_Regular24pt7b);
    tft.setTextColor(TFT_WHITE);
    tft.drawString ((String) temperature_new,30,80);
    tft.drawCircle(85, 90, 5, TFT_WHITE);
    tft.setFreeFont(&FreeSansBold12pt7b);
    tft.drawString("C",98,85);

    tft.setFreeFont(&FreeMono24pt7b);
    tft.drawString("|",115,85);

    tft.setFreeFont(&Oswald_Regular24pt7b);
    tft.setTextColor(TFT_WHITE);
    tft.drawString ((String) humidity_new,145,80);
    tft.drawString ("%",200,93,4);
}
