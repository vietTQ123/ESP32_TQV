#include <Arduino.h>
#include <WiFi.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>

const char *ssid = "AIoT Lab 2G";      // Replace with your WiFi SSID
const char *password = "ptitlab@123";  // Replace with your WiFi password

// const char *ssid = "Thanh Trung";      // Replace with your WiFi SSID
// const char *password = "17062009";  // Replace with your WiFi password
//Your Domain name with URL path or IP address with path


const char* serverName = "http://192.168.1.106:1880/update-sensor";

unsigned long lastTime = 0;

unsigned long timerDelay = 1000;

void setup() {
  Serial.begin(115200);

  WiFi.begin(ssid, password);
  Serial.println("Connecting");
  while( WiFi.status() != WL_CONNECTED) 
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to WiFi network with IP Address: ");
  Serial.println(WiFi.localIP());
 
  Serial.println("Timer set to 5 seconds (timerDelay variable), it will take 5 seconds before publishing the first reading.");
}

void loop() {

  if ((millis() - lastTime) > timerDelay) 
  {
    if(WiFi.status()== WL_CONNECTED)
    {
      WiFiClient client;
      HTTPClient http;
    
      http.begin(client, serverName);
      
      http.addHeader("Content-Type", "application/json");
      int httpResponseCode = http.POST("{\"ID\" : \"door1\" , \"STT\" : \"start}");

      Serial.print("HTTP Response code: ");
      Serial.println(httpResponseCode);
        
      http.end();
    }
    else 
    {
      Serial.println("WiFi Disconnected");
    }
    lastTime = millis();
  }
}