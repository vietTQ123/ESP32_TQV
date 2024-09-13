#include "DHT_11.h"

DHT dht(PIN_DHT_11, TYPE_DHT_11);

void DHT11_Setup()
{
    dht.begin();
}

int DHT11_Temperature()
{
    int t = dht.readTemperature();
    return t;
}

int DHT11_Humidity()
{
    int h = dht.readHumidity();
    return h;
}