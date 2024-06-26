#include "lib_http.h"

String URL = "http://192.168.0.141:3000/api/v1/update-match-result?";

#if DEGUB_CONNECT_WIFI
const char *ssid = "AIoT Lab 2G";      // Replace with your WiFi SSID
const char *password = "ptitlab@123";  // Replace with your WiFi password

void Wifi_Connect(void)
{
    WiFi.begin(ssid, password);
    Serial.println("Connecting");
    while(WiFi.status() != WL_CONNECTED) 
    {
        Connecting_SSD_1306();
        Serial.print(".");
    }
    Serial.println("");
    Serial.print("Connected to WiFi network with IP Address: ");
    Serial.println(WiFi.localIP());
}
#endif

String HTTP_GETRequest(String id, String stt) 
{
  WiFiClient client;
  HTTPClient http;

  String API_URL = URL + "id=" + id + "&stt=" + stt;
    
  // Your Domain name with URL path or IP address with path
  http.begin(client, API_URL);
  
  // Send HTTP POST request
  int httpResponseCode = http.GET();
  
  String payload = "{}"; 
  
  if (httpResponseCode>0) 
  {
    Serial.print("HTTP Response code: ");
    Serial.println(httpResponseCode);
    payload = http.getString();
  }
  else 
  {
    Serial.print("Error code: ");
    Serial.println(httpResponseCode);
  }
  // Free resources
  http.end();

  return payload;
}
