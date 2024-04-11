// #include "http.h"

// String serverAddress = "https://postman-echo.com/";

// const char *ssid = "AIoT Lab 2G";      // Replace with your WiFi SSID
// const char *password = "ptitlab@123";  // Replace with your WiFi password

// // const char *ssid = "Thanh Trung";      // Replace with your WiFi SSID
// // const char *password = "17062009";  // Replace with your WiFi password
// char jsonoutput [128];
// HTTPClient http;

// void Http_Setup() 
// {
//   WiFi.begin(ssid, password);
//   while (WiFi.status() != WL_CONNECTED)
//   {
//     delay(500);
//     Serial.println("Connecting to WiFi..");
//   }
//   Serial.println("Connected to the WiFi network");
// }

// void SendData_HttpPost_Json()
// {
//   if(WiFi.status() == WL_CONNECTED)
//   {
//     http.begin("https://jsonplaceholder.typicode.com/posts");
//     http.addHeader("Content-Type", "application/json");

//     const size_t CAPACITY = JSON_OBJECT_SIZE(1);
//     StaticJsonDocument<CAPACITY> doc;

//     JsonObject object = doc.to<JsonObject>();
//     object["title"] = "Subscribe to Asali";

//     serializeJson(doc, jsonoutput);

//     int httpCode=http.GET();

//     if(httpCode > 0)
//     {
//         String payload =http.getString();
//         Serial.println("\nStatuscode: " + String(httpCode));
//         Serial.println(payload);

//         http.end();
//     }
//     else
//     {
//         Serial.println("Error on HTTP requet");
//     }
//   }
//   else
//   {
//     Serial.println("Connection lost");
//   }
// }
