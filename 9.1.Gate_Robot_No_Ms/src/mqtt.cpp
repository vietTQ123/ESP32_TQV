// #include <mqtt.h>


// WiFiClient espClient;
// PubSubClient client(espClient);

// char Wait[1000] = "Waiting...";
// char Rst[1000] = "Reset...";
// char Start[1000] = "Start";
// char Stop[1000]="Stop";

// char buffer[1000];

// uint8_t flag_mqtt_pubish=1;

// const char *mqtt_broker = "broker.mqttdashboard.com";
// const char *topic_pub = "Esp32/Mqtt";
// const char *topic_sub = "Mqtt/Esp32";
// const char *mqtt_username = "Viet";
// const char *mqtt_password = "612004";
// const char *topic1 = "listen";
// const int mqtt_port = 1883;

// // const char *ssid = "AIoT Lab 2G";      // Replace with your WiFi SSID
// // const char *password = "ptitlab@123";  // Replace with your WiFi password

// const char *ssid = "Thanh Trung";      // Replace with your WiFi SSID
// const char *password = "17062009";  // Replace with your WiFi password

// void callback(char *topic, byte *payload, unsigned int length)
// {
//     Serial.println("Message arrived: " + String(topic));
//     Serial.println("Payload: ");
//     for (unsigned int i = 0; i < length; i++)
//     {
//         buffer[i]=(char)payload[i];
//         // Serial.print((char)payload[i]);
//     }
//     buffer[length] ='\0';
//     flag_mqtt_pubish=1;
//     Serial.println();
// }

// void MQTT_Connect()
// {
//     // connecting to an MQTT broker
//     client.setServer(mqtt_broker, mqtt_port);
//     client.setCallback(callback);
//     while (!client.connected())
//     {
//         String client_id = "esp32-client-";
//         client_id += String(WiFi.macAddress());
//         Serial.printf("The client %s connects to the public mqtt broker\n", client_id.c_str());
//         if (client.connect(client_id.c_str(), mqtt_username, mqtt_password))
//         {
//             Serial.println("Public emqx mqtt broker connected");
//             client.subscribe(topic_sub);
//         }
//         else
//         {
//             Serial.print("failed with state ");
//             Serial.print(client.state());
//             // delay(2000);
//         }
//     }
// }

// void Setup_Mqtt()
// {
//     Serial.begin(9600); 
//     Serial.println("Connecting to WiFi...");
//     WiFi.begin(ssid, password);
//     while (WiFi.status() != WL_CONNECTED)
//     {
//         // delay(100);
//         Connecting_SSD_1306();
//         Serial.print(".");
//     }
//     Serial.println("\nConnected to WiFi");
//     Serial.print("AP IP address: ");
//     Serial.println(WiFi.localIP());
//     MQTT_Connect();
// }

// void connect_to_broker() {
//   while (!client.connected()) {
//     Serial.print("Attempting MQTT connection...");
//     String clientId = "ESP32";
//     clientId += String(random(0xffff), HEX);
//     if (client.connect(clientId.c_str())) {
//       Serial.println("connected");
//       client.subscribe(topic1);
//     } else {
//       Serial.print("failed, rc=");
//       Serial.print(client.state());
//       Serial.println(" try again in 2 seconds");
//       // delay(2000);
//     }
//   }
// }

// void run()
// {

// }