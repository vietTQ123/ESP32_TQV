#include <weather.h>
#include <TFT_eSPI.h>
#include <SPI.h>
#include <FS.h>
#include <SPIFFS.h>
#include <DHT.h>




DHT dht(DHTPIN, DHTTYPE);

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

String Apikey = "4d7bc52458715c7ef7e26a5a81b7036a";
String city = "Hanoi";
String countryCode = "VN";
unsigned long lastTime = 0;
unsigned long timerDelay = 10000;
String jsonBuffer;

String httpGETRequest(const char *serverName)
{
  WiFiClient client;
  HTTPClient http;

  http.begin(client, serverName);

  int httpResponseCode = http.GET();

  String payload = "{}";

  if (httpResponseCode > 0)
  {
    // Serial.print("HTTP Response code: ");
    // Serial.println(httpResponseCode);
    payload = http.getString();
  }
  else
  {
    Serial.print("Error code: ");
    Serial.println(httpResponseCode);
  }

  http.end();

  return payload;
}

void Weather_Infor()
{
  if ((millis() - lastTime) > timerDelay)
  {

    if (WiFi.status() == WL_CONNECTED)
    {
      // String serverPath = "http://api.openweathermap.org/data/2.5/weather?q=" + city + "," + countryCode + "&APPID=" + Apikey;
      String serverPath = "http://api.openweathermap.org/data/2.5/forecast?q=" + city + "," + countryCode + "&cnt=4&APPID=" + Apikey;

      // jsonBuffer = httpGETRequest(serverPath.c_str());
      // // Serial.println(jsonBuffer);
      // JSONVar myObject = JSON.parse(jsonBuffer);
      // JSONVar today = myObject["list"][0];
      // JSONVar next_day = myObject["list"][1];
      // JSONVar third_day = myObject["list"][2];
      // JSONVar fourth_day = myObject["list"][3];

      // if (JSON.typeof(myObject) == "undefined")
      // {
      //   Serial.println("Parsing input failed!");
      //   return;
      // }

      // Serial.println(myObject);
      // Serial.print("Temperature: ");
      // Serial.println((int)myObject["list"][0]["main"]["temp"] - 273);
      // Serial.print("Humidity: ");
      // Serial.println((double)today["main"]["temp"] - 273);
      // Serial.println((double)next_day["main"]["temp"] - 273);
      // Serial.println((double)third_day["main"]["temp"] - 273);
      // Serial.println((double)fourth_day["main"]["temp"] - 273);
      // Serial.print("Wind Speed: ");
      // Serial.println(myObject["wind"]["speed"]);
    }
    else
    {
      Serial.println("WiFi Disconnected");
    }
    lastTime = millis();
  }
}