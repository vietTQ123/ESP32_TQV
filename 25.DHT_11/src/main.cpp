#include "DHT_11.h"

void setup()
{
  Serial.begin(9600);
  DHT11_Setup();
}

void loop()
{
  int a = DHT11_Temperature();
  int b = DHT11_Humidity();

  Serial.print("Humidity: ");
  Serial.print(b);
  Serial.print("%  Temperature: ");
  Serial.print(a);
  Serial.print("°C ");
  Serial.println();
  delay(1000);
}
