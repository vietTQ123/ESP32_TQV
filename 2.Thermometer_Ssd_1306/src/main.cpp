#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Fonts/DSEG7_Classic_Mini_Bold_22.h>
#include <Fonts/DejaVu_LGC_Sans_Bold_14.h>
#include <ArduinoJson.h>
#include <Adafruit_MLX90614.h>
#include <SPI.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

int button = 19;
char onoff = 1;
int flag_stt;
int button_servo_old ;
int button_servo_new =1;

hw_timer_t *Timer0_Cfg = NULL;
Adafruit_MLX90614 mlx = Adafruit_MLX90614();
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);
StaticJsonDocument<16> doc;

const unsigned char thermometergun[] = {
    0x07, 0xFF, 0xFE, 0x00, 0x1F, 0xFF, 0xFF, 0x06, 0x18, 0x00, 0x37, 0x06, 0x19, 0xFE, 0x33, 0x33,
    0x31, 0xFF, 0x33, 0x33, 0x33, 0x87, 0x33, 0x33, 0x33, 0x87, 0x33, 0x33, 0x33, 0xFF, 0x33, 0x33,
    0x31, 0xFE, 0x37, 0x33, 0x30, 0x00, 0x37, 0x06, 0x30, 0x07, 0xFF, 0x06, 0x30, 0x0F, 0xFE, 0x00,
    0x18, 0x1D, 0x80, 0x00, 0x18, 0x19, 0x80, 0x00, 0x18, 0x19, 0x80, 0x00, 0x18, 0x19, 0x80, 0x00,
    0x18, 0x19, 0x80, 0x00, 0x30, 0x3F, 0x80, 0x00, 0x30, 0x3F, 0x80, 0x00, 0x30, 0x3E, 0x00, 0x00,
    0x30, 0x30, 0x00, 0x00, 0x70, 0x30, 0x00, 0x00, 0x60, 0x30, 0x00, 0x00, 0x60, 0x60, 0x00, 0x00,
    0x60, 0x60, 0x00, 0x00, 0x60, 0x60, 0x00, 0x00, 0xE0, 0x60, 0x00, 0x00, 0xC0, 0x60, 0x00, 0x00,
    0xC0, 0xE0, 0x00, 0x00, 0xC0, 0xC0, 0x00, 0x00, 0xFF, 0xC0, 0x00, 0x00, 0x7F, 0x80, 0x00, 0x00};

void JSON(float a)
{
  doc["Temp"] = a;
  serializeJson(doc, Serial);
}

void IRAM_ATTR check_status()
{
  flag_stt = 1;
}

void setup()
{
  pinMode(button, INPUT);
  Serial.begin(115200);
  mlx.begin();
  Timer0_Cfg = timerBegin(0, 8000, true);
  timerAttachInterrupt(Timer0_Cfg, &check_status, true);
  timerAlarmWrite(Timer0_Cfg, 1000, true); // 100ms
  timerAlarmEnable(Timer0_Cfg);
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C))
  {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;)
      ;
  }
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(17, 10);
  display.println("EMBEDDED     IOT       LAB");
  display.display();
  delay(2000);
  display.clearDisplay();
  display.display();
}

void loop()
{
  if (flag_stt == 1)
  {
    button_servo_old = button_servo_new;
    button_servo_new = digitalRead(button);
    if (button_servo_old == 1 && button_servo_new == 0)
    {
      if (onoff == 1)
      {
        onoff = 0;
        float a = mlx.readObjectTempC();
        if (a > -1 && a < 10.0)
        {
          display.clearDisplay();
          display.setFont(&DejaVu_LGC_Sans_Bold_14);
          display.setTextSize(1);
          display.setCursor(2, 14);
          display.println("TEMPERATURE");
          display.setFont(&DSEG7_Classic_Mini_Bold_22);
          display.setTextSize(1);
          display.setCursor(17, 53);
          display.println(a);
          display.drawCircle(82, 34, 3, WHITE);
          display.setFont();
          display.setTextSize(3);
          display.setCursor(92, 31);
          display.println("C");
          display.display();
        }
        else
        {
          display.clearDisplay();
          display.setTextSize(1);
          display.setFont(&DejaVu_LGC_Sans_Bold_14);
          display.setCursor(2, 14);
          display.println("TEMPERATURE");
          display.setFont(&DSEG7_Classic_Mini_Bold_22);
          display.setTextSize(1);
          display.setCursor(8, 53);
          display.println(a);
          display.drawCircle(92, 34, 3, WHITE);
          display.setFont();
          display.setTextSize(3);
          display.setCursor(102, 31);
          display.println("C");
          display.display();
        }
        JSON(a);
      }
      else
      {
        onoff = 1;
        display.clearDisplay();
        display.setTextSize(1);
        display.setFont(&DejaVu_LGC_Sans_Bold_14);
        display.setCursor(5, 10);
        display.println("continue......");
        display.drawBitmap(50, 25, thermometergun, 32, 32, WHITE);
        display.display();
      }
    }
    flag_stt = 0;
  }
}