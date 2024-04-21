#include <Arduino.h>
#include <Ucglib.h>
#include <SPI.h>
#include <ESP32Servo.h>

const int trigPin = 17;
const int echoPin = 16;
const int servoPin = 13;

int Ymax = 128;
int Xmax = 160;
int Xcent = Xmax / 2;
int base = 118;
int scanline = 105;

Servo baseServo;

Ucglib_ILI9341_18x240x320_HWSPI ucg(/*cd=*/2, /*cs=*/15, /*reset=*/4);
// Ucglib_ST7735_18x128x160_HWSPI ucg(/*cd=*/ 9, /*cs=*/ 10, /*reset=*/ 8);

void cls()
{

  ucg.setColor(0, 0, 0, 0);

  for (int s = 0; s < 128; s += 8)
    for (int t = 0; t < 160; t += 16)
    {
      ucg.drawBox(t, s, 16, 8);
    }
}

int calculateDistance()
{
  long duration;

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);

  return duration * 0.034 / 2;
}

void fix_font()
{
  ucg.setColor(0, 180, 0);
  ucg.setPrintPos(70, 14);
  ucg.print("1.00");
  ucg.setPrintPos(70, 52);
  ucg.print("0.50");
  ucg.setPrintPos(70, 90);
  ucg.print("0.25");
}

void fix()
{

  ucg.setColor(0, 40, 0);

  ucg.drawDisc(Xcent, base + 1, 3, UCG_DRAW_ALL);
  ucg.drawCircle(Xcent, base + 1, 115, UCG_DRAW_UPPER_LEFT);
  ucg.drawCircle(Xcent, base + 1, 115, UCG_DRAW_UPPER_RIGHT);
  ucg.drawCircle(Xcent, base + 1, 78, UCG_DRAW_UPPER_LEFT);
  ucg.drawCircle(Xcent, base + 1, 78, UCG_DRAW_UPPER_RIGHT);
  ucg.drawCircle(Xcent, base + 1, 40, UCG_DRAW_UPPER_LEFT);
  ucg.drawCircle(Xcent, base + 1, 40, UCG_DRAW_UPPER_RIGHT);
  ucg.drawLine(0, base + 1, Xmax, base + 1);

  ucg.setColor(0, 120, 0);

  for (int i = 40; i < 140; i += 2)
  {

    if (i % 10 == 0)
      ucg.drawLine(105 * cos(radians(i)) + Xcent, base - 105 * sin(radians(i)), 113 * cos(radians(i)) + Xcent, base - 113 * sin(radians(i)));
    else

      ucg.drawLine(110 * cos(radians(i)) + Xcent, base - 110 * sin(radians(i)), 113 * cos(radians(i)) + Xcent, base - 113 * sin(radians(i)));
  }

  ucg.setColor(0, 200, 0);
  ucg.drawLine(0, 0, 0, 18);
  for (int i = 0; i < 5; i++)
  {
    ucg.setColor(0, random(200) + 50, 0);
    ucg.drawBox(2, i * 4, random(14) + 2, 3);
  }

  ucg.setColor(0, 180, 0);
  ucg.drawFrame(146, 0, 14, 14);
  ucg.setColor(0, 60, 0);
  ucg.drawHLine(148, 0, 10);
  ucg.drawVLine(146, 2, 10);
  ucg.drawHLine(148, 13, 10);
  ucg.drawVLine(159, 2, 10);

  ucg.setColor(0, 220, 0);
  ucg.drawBox(148, 2, 4, 4);
  ucg.drawBox(148, 8, 4, 4);
  ucg.drawBox(154, 8, 4, 4);
  ucg.setColor(0, 100, 0);
  ucg.drawBox(154, 2, 4, 4);

  ucg.setColor(0, 90, 0);
  ucg.drawTetragon(62, 123, 58, 127, 98, 127, 102, 123);
  ucg.setColor(0, 160, 0);
  ucg.drawTetragon(67, 123, 63, 127, 93, 127, 97, 123);
  ucg.setColor(0, 210, 0);
  ucg.drawTetragon(72, 123, 68, 127, 88, 127, 92, 123);
}

void setup(void)
{

  ucg.begin(UCG_FONT_MODE_SOLID);
  ucg.setRotate90();

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(115200);
  baseServo.attach(servoPin);

  ucg.setFontMode(UCG_FONT_MODE_TRANSPARENT);
  ucg.setColor(0, 0, 100, 0);
  ucg.setColor(1, 0, 100, 0);
  ucg.setColor(2, 20, 20, 20);
  ucg.setColor(3, 20, 20, 20);
  ucg.drawGradientBox(0, 0, 160, 128);
  ucg.setPrintDir(0);
  ucg.setColor(0, 5, 0);
  ucg.setPrintPos(27, 42);
  ucg.setFont(ucg_font_logisoso18_tf);
  ucg.print("Mini Radar");
  ucg.setColor(0, 255, 0);
  ucg.setPrintPos(25, 40);
  ucg.print("Mini Radar");
  ucg.setFont(ucg_font_helvB08_tf);
  ucg.setColor(0, 255, 0);
  ucg.setPrintPos(40, 100);
  ucg.print("Testing...");
  baseServo.write(90);
  ucg.setColor(0, 255, 0);

  for (int x = 0; x < 180; x += 5)
  {
    baseServo.write(x);
    delay(50);
  }
  ucg.print("OK!");
  delay(500);
  ucg.setColor(0, 0, 0, 0);
  ucg.setColor(1, 0, 0, 0);
  ucg.setColor(2, 0, 0, 0);
  ucg.setColor(3, 0, 0, 0);

  cls();

  ucg.setFont(ucg_font_orgv01_hr);
  ucg.setFontMode(UCG_FONT_MODE_SOLID);
}

void loop(void)
{

  int distance;

  fix();
  fix_font();

  for (int x = 180; x > 4; x -= 2)
  {

    baseServo.write(x);

    int f = x - 4;
    ucg.setColor(0, 255, 0);
    ucg.drawLine(Xcent, base, scanline * cos(radians(f)) + Xcent, base - scanline * sin(radians(f)));
    f += 2;
    ucg.setColor(0, 128, 0);
    ucg.drawLine(Xcent, base, scanline * cos(radians(f)) + Xcent, base - scanline * sin(radians(f)));
    f += 2;
    ucg.setColor(0, 0, 0);
    ucg.drawLine(Xcent, base, scanline * cos(radians(f)) + Xcent, base - scanline * sin(radians(f)));
    ucg.setColor(0, 200, 0);

    distance = calculateDistance();

    if (distance < 100)
    {
      ucg.setColor(255, 0, 0);
      ucg.drawDisc(distance * cos(radians(x)) + Xcent, -distance * sin(radians(x)) + base, 1, UCG_DRAW_ALL);
    }
    else
    {
      ucg.setColor(255, 255, 0);
      ucg.drawDisc(116 * cos(radians(x)) + Xcent, -116 * sin(radians(x)) + base, 1, UCG_DRAW_ALL);
    }

    Serial.print(x);
    Serial.print("    ,   ");
    Serial.println(distance);

    if (x > 70 and x < 110)
      fix_font();

    ucg.setColor(0, 0, 155, 0);
    ucg.setPrintPos(0, 126);
    ucg.print("DEG: ");
    ucg.setPrintPos(24, 126);
    ucg.print(x);
    ucg.print("  ");
    ucg.setPrintPos(125, 126);
    ucg.print("  ");
    ucg.print(distance);
    ucg.print("cm  ");
  }

  delay(50);
  cls();

  fix();
  fix_font();

  for (int x = 1; x < 176; x += 2)
  {
    baseServo.write(x);

    int f = x + 4;
    ucg.setColor(0, 255, 0);
    ucg.drawLine(Xcent, base, scanline * cos(radians(f)) + Xcent, base - scanline * sin(radians(f)));
    f -= 2;
    ucg.setColor(0, 128, 0);
    ucg.drawLine(Xcent, base, scanline * cos(radians(f)) + Xcent, base - scanline * sin(radians(f)));
    f -= 2;
    ucg.setColor(0, 0, 0);
    ucg.drawLine(Xcent, base, scanline * cos(radians(f)) + Xcent, base - scanline * sin(radians(f)));
    ucg.setColor(0, 200, 0);

    distance = calculateDistance();

    if (distance < 100)
    {
      ucg.setColor(255, 0, 0);
      ucg.drawDisc(distance * cos(radians(x)) + Xcent, -distance * sin(radians(x)) + base, 1, UCG_DRAW_ALL);
    }
    else
    {
      ucg.setColor(255, 255, 0);
      ucg.drawDisc(116 * cos(radians(x)) + Xcent, -116 * sin(radians(x)) + base, 1, UCG_DRAW_ALL);
    }

    Serial.print(x);
    Serial.print("    ,   ");
    Serial.println(distance);

    if (x > 70 and x < 110)
      fix_font();

    ucg.setColor(0, 0, 155, 0);
    ucg.setPrintPos(0, 126);
    ucg.print("DEG: ");
    ucg.setPrintPos(24, 126);
    ucg.print(x);
    ucg.print("   ");
    ucg.setPrintPos(125, 126);
    ucg.print("   ");
    ucg.print(distance);
    ucg.print("cm   ");
  }
  delay(50);
  cls();
}