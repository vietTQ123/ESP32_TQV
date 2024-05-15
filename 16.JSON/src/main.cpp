#include <Arduino.h>
#include <ArduinoJson.h>

static int data_N ;
static int data_S ;
static int data_V ;
static int data_F ;
static int data_Q ;
static int Reset;
static int Stop;

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  data_N = random(10, 100);
  data_S = random(10, 100);
  data_V = random(10, 100);
  data_F = random(10, 100);
  data_Q = random(10, 100);
  Reset = random(0, 1);
  Stop = random(0, 1);

  StaticJsonDocument<200> doc;

  doc["N"] = data_N;
  doc["S"] = data_S;
  doc["V"] = data_V;
  doc["F"] = data_F;
  doc["Q"] = data_Q;
  doc["Reset"] = Reset;
  doc["Stop"] = Stop;

  serializeJson(doc, Serial);
  Serial.println(); // Kết thúc dòng

  delay(1000);
}