#include "Module_DHT.h"

DHT dht(DHTPIN,DHTTYPE);

void Dht_setup()
{
  dht.begin();
}

int Current_temp()
{
  int temp = dht.readTemperature();
  return temp;
}

int Current_humi()
{
  int humi = dht.readHumidity();
  return humi;
}