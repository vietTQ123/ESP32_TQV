#include <wifi_scan.h>


void Scan_wifi(){
  Serial.println("Scan start");
 
    // WiFi.scanNetworks will return the number of networks found.
    int n = WiFi.scanNetworks();
    Serial.println("Scan done");
    if (n == 0) {
        Serial.println("no networks found");
    } else {
        Serial.print(n);
        Serial.println(" networks found");
        for (int i = 0; i < n; ++i) {
            // Print SSID and RSSI for each network found
            Serial.printf("%2d",i + 1);
            Serial.print(" | ");
            Serial.printf("%-32.32s", WiFi.SSID(i).c_str());
            Serial.println();
            delay(10);
        }
    }
    Serial.println("");
 
    // Delete the scan result to free memory for code below.
    WiFi.scanDelete();
 
    // Wait a bit before scanning again.
    delay(5000);
}

void Connect_wifi(){
    Serial.println("Connect to AP...");
    WiFi.begin(ssid,password);
    while(WiFi.status() != WL_CONNECTED)
    {
    Serial.print(".");
    delay(100);
    }
    Serial.println("AP IP address: ");
    Serial.println(WiFi.localIP());
}