#include <Arduino.h>
#include <Ucglib.h>
#include <SPI.h>
#include <ESP32Servo.h>

const int trigPin = 17;
const int echoPin = 16;
const int servoPin = 13;

int Ymax = 240;
int Xmax = 320;
int base = 8;
int pos = base + 6;
int deg = 0;
int x;
// int val = 200;
int val = 360;
int j = 2;

Servo myServo;

long duration;
int distance;
int k;

Ucglib_ILI9341_18x240x320_HWSPI ucg(/*cd=*/2, /*cs=*/15, /*reset=*/4);

void fix()
{
  ucg.setColor(255, 0, 0);
  ucg.drawDisc(Xmax / 2, base, 5, UCG_DRAW_LOWER_RIGHT);
  ucg.drawDisc(Xmax / 2, base, 5, UCG_DRAW_LOWER_LEFT);

  ucg.setColor(225, 255, 50);
  ucg.drawCircle(160, base, 227, UCG_DRAW_LOWER_RIGHT);
  ucg.drawCircle(160, base, 227, UCG_DRAW_LOWER_LEFT);

  ucg.drawCircle(160, base, 190, UCG_DRAW_LOWER_RIGHT);
  ucg.drawCircle(160, base, 190, UCG_DRAW_LOWER_LEFT);

  ucg.drawCircle(160, base, 152, UCG_DRAW_LOWER_RIGHT);
  ucg.drawCircle(160, base, 152, UCG_DRAW_LOWER_LEFT);

  ucg.drawLine(0, base, 320, base);

  ucg.setColor(0, 0, 0);
  ucg.drawBox(320, 0, 60, 8);
}

int calculateDistance()
{

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH); // Reads the echoPin, returns the sound wave travel time in microseconds
  distance = duration * 0.034 / 2;
  return distance;
}

void setup(void)
{
  // myServo.write(80);
  // ucg.begin(UCG_FONT_MODE_TRANSPARENT);
  ucg.begin(UCG_FONT_MODE_SOLID);
  ucg.setFont(ucg_font_6x10_tr);
  ucg.clearScreen();
  ucg.setRotate270();

  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT);  // Sets the echoPin as an Input
  Serial.begin(9600);
  myServo.attach(servoPin); // Defines on which pin is the servo motor attached
}

void loop(void)
{

  fix();

  for (x = 80; x > 10; x--)
  {

    distance = calculateDistance();
    Serial.println(distance);

    k = map(x, 80, 10, 15, 165);
    // myServo.write(k);
    if (distance < 30)
    {
      int f = x + 6;
      ucg.setColor(255, 0, 0);
      ucg.drawLine(Xmax / 2, pos, -val * cos(radians(f * 2)), val * sin(radians(f * 2)));
    }
    ucg.setColor(0, 207, 0);
    ucg.drawLine(Xmax / 2, pos, -val * cos(radians(x * 2)), val * sin(radians(x * 2)));

    int d = x + 1;
    ucg.setColor(0, 207, 0);
    ucg.drawLine(Xmax / 2, pos, -val * cos(radians(d * 2)), val * sin(radians(d * 2)));

    int c = x + 2;
    ucg.setColor(0, 207, 0);
    ucg.drawLine(Xmax / 2, pos, -val * cos(radians(c * 2)), val * sin(radians(c * 2)));

    int b = x + 3;
    ucg.setColor(0, 102, 0);
    ucg.drawLine(Xmax / 2, pos, -val * cos(radians(b * 2)), val * sin(radians(b * 2)));

    int a = x + 4;
    ucg.setColor(0, 102, 0);
    ucg.drawLine(Xmax / 2, pos, -val * cos(radians(a * 2)), val * sin(radians(a * 2)));

    int e = x + 5;
    ucg.setColor(0, 0, 0);
    ucg.drawLine(Xmax / 2, pos, -val * cos(radians(e * 2)), val * sin(radians(e * 2)));
    ucg.setColor(255, 0, 0);
    ucg.setPrintPos(320, 0);
    ucg.setPrintDir(2);
    ucg.print("Deg :");
    deg = map(x, 80, 10, 0, 180);
    ucg.setPrintPos(280, 0);
    ucg.setPrintDir(2);
    ucg.print(deg);
    ucg.setPrintPos(10, 0);
    ucg.print(distance);
    ucg.setColor(0, 0, 255);
    ucg.setPrintPos(170, 150);
    ucg.setPrintDir(2);
    ucg.print("0.25");
    ucg.setPrintPos(170, 182);
    ucg.print("0.50");
    ucg.setPrintPos(170, 222);
    ucg.print("1.00");
  }

  // ucg.clearScreen();

  fix();

  for (x = 10; x < 80; x++)
  {
    distance = calculateDistance();
    Serial.println(distance);
    k = map(x, 10, 80, 165, 15);
    // myServo.write(k);
    if (distance < 10)
    {
      int e = x - 5;
      ucg.setColor(255, 0, 0);
      ucg.drawLine(Xmax / 2, pos, -val * cos(radians(e * 2)), val * sin(radians(e * 2)));
    }

    ucg.setColor(0, 207, 0);
    ucg.drawLine(Xmax / 2, pos, -val * cos(radians(x * 2)), val * sin(radians(x * 2)));

    int a = x - 1;

    ucg.drawLine(Xmax / 2, pos, -val * cos(radians(a * 2)), val * sin(radians(a * 2)));

    int b = x - 2;
    ucg.setColor(0, 102, 0);
    ucg.drawLine(Xmax / 2, pos, -val * cos(radians(b * 2)), val * sin(radians(b * 2)));

    int c = x - 3;
    ucg.setColor(0, 102, 0);
    ucg.drawLine(Xmax / 2, pos, -val * cos(radians(c * 2)), val * sin(radians(c * 2)));

    int d = x - 4;
    ucg.setColor(0, 0, 0);
    ucg.drawLine(Xmax / 2, pos, -val * cos(radians(d * 2)), val * sin(radians(d * 2)));

    ucg.setColor(255, 0, 0);
    ucg.setPrintPos(320, 0);
    ucg.setPrintDir(2);
    ucg.print("Deg :");
    deg = map(x, 10, 80, 0, 180);
    ucg.setPrintPos(280, 0);
    ucg.setPrintDir(2);
    ucg.print(deg);
    ucg.setPrintPos(10, 0);
    ucg.print(distance);

    ucg.setColor(0, 0, 255);
    ucg.setPrintPos(170, 150);
    ucg.setPrintDir(2);
    ucg.print("0.25");
    ucg.setPrintPos(170, 182);
    ucg.print("0.50");
    ucg.setPrintPos(170, 222);
    ucg.print("1.00");
  }
  // ucg.clearScreen();
}