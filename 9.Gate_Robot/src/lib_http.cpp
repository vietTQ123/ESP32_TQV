#include "lib_http.h"

String URL = "http://10.42.0.1:3000/api/v1/update-match-result?";

#if DEGUB_CONNECT_WIFI
const char* ssid = "OpenWrt";
const char* password = "12345678";

void Wifi_Connect(void)
{
    WiFi.begin(ssid, password);
    Serial.println("Connecting");
    while(WiFi.status() != WL_CONNECTED) 
    {
      Connecting_SSD_1306();
      delay(100);
      Serial.print(".");
    }
    Serial.println("");
    Serial.print("Connected to WiFi network with IP Address: ");
    Serial.println(WiFi.localIP());
    Connected_SSD_1306();
    delay(500);
}
#endif


String HTTP_GETRequest(String id, String stt, long runningTime)
{
  WiFiClient client;
  HTTPClient http;

  String API_URL = URL + "id=" + id + "&stt=" + stt + "&runningTime=" + runningTime;
    
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
