#include <ssd1306.h>
#include <mqtt.h>

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void Setup_SSD_1306()
{
    Serial.begin(9600);
    display.begin(SSD1306_SWITCHCAPVCC, SCREEN_I2C_ADDR);
}

void Connecting_SSD_1306()
{
    display.clearDisplay();
    display.setFont(&FreeSansBold9pt7b);
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.setCursor(8, 37);
    display.println("Connecting...");
    display.display();
}

void Waiting_SSD_1306()
{
    display.clearDisplay();
    display.setFont(&FreeSansBold9pt7b);
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.setCursor(20, 37);
    display.println("Waiting......");
    display.display();
}

void Reset_SSD_1306()
{
    display.clearDisplay();
    display.setFont(&FreeSansBold9pt7b);
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.setCursor(30, 37);
    display.println("Reset.....");
    display.display();
}


void Start_SSD_1306()
{
    display.clearDisplay();
    display.setFont(&FreeSansBold9pt7b);
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.setCursor(43, 11);
    display.println("Start");
    display.setFont(&DSEG7_Classic_Bold_22);
    if(racing_time < 10)
    {
        display.setTextSize(1);
        display.setTextColor(WHITE);
        display.setCursor(55,50);
        display.println(racing_time);
    }
    if((racing_time < 20) && (racing_time >= 10) )
    {
        display.setTextSize(1);
        display.setTextColor(WHITE);
        display.setCursor(42,50);
        display.println(racing_time);
    }
    if((racing_time < 100) && (racing_time >= 20) )
    {
        display.setTextSize(1);
        display.setTextColor(WHITE);
        display.setCursor(45,50);
        display.println(racing_time);
    }
    if((racing_time < 1000) && (racing_time >= 100) )
    {
        display.setTextSize(1);
        display.setTextColor(WHITE);
        display.setCursor(35,50);
        display.println(racing_time);
    }
    display.display();
}

void Stop_SSD_1306()
{
    display.clearDisplay();
    display.setFont(&FreeSansBold9pt7b);
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.setCursor(43, 11);
    display.println("Stop");
    display.setFont(&DSEG7_Classic_Bold_22);
    if(racing_time < 10)
    {
        display.setTextSize(1);
        display.setTextColor(WHITE);
        display.setCursor(55,50);
        display.println(racing_time);
    }
    if((racing_time < 20) && (racing_time >= 10) )
    {
        display.setTextSize(1);
        display.setTextColor(WHITE);
        display.setCursor(42,50);
        display.println(racing_time);
    }
    if((racing_time < 100) && (racing_time >= 20) )
    {
        display.setTextSize(1);
        display.setTextColor(WHITE);
        display.setCursor(45,50);
        display.println(racing_time);
    }
    if((racing_time < 1000) && (racing_time >= 100) )
    {
        display.setTextSize(1);
        display.setTextColor(WHITE);
        display.setCursor(35,50);
        display.println(racing_time);
    }
    display.display();
}