#include <Screen_TFT.h>

TFT_eSPI tft = TFT_eSPI();

static int data_N ;
static int data_S ;
static int data_V ;
static int data_F ;
static int data_Q ;
static int Reset ;
static int Stop ;

static int flag = 0;

void TFT_Setup()
{
    Serial.begin(9600);

    tft.init();
    tft.setRotation(2);
    tft.fillScreen(TFT_WHITE);
    tft.setSwapBytes(true);

    tft.pushImage(50, 0, 140, 140, Screen_TFT);

    tft.setTextColor(ILI9341_BLACK);
    tft.setFreeFont(&nulshock_bd9pt7b);
    tft.drawString("ECG Classification", 5, 150);
}

void TFT_Screen()
{
    if (Serial.available())
    {                                                      // Kiểm tra xem có dữ liệu nào trên cổng Serial không
        String jsonMessage = Serial.readStringUntil('\n'); // Đọc dữ liệu JSON từ Serial cho đến khi gặp ký tự xuống dòng (\n)

        StaticJsonDocument<200> doc; // Tạo một đối tượng JSON để lưu trữ dữ liệu

        DeserializationError error = deserializeJson(doc, jsonMessage); // Giải mã dữ liệu JSON từ chuỗi

        if (error)
        { // Kiểm tra xem có lỗi trong quá trình giải mã không
            Serial.print("deserializeJson() failed: ");
            Serial.println(error.f_str());
            return;
        }

        // Trích xuất dữ liệu từ JSON
        data_N = doc["N"];
        data_S = doc["S"];
        data_V = doc["V"];
        data_F = doc["F"];
        data_Q = doc["Q"];
        Reset = doc["Reset"];
        Stop = doc["Stop"];

        flag = 1;
    }

    if(flag == 1)
    {
        // In ra dữ liệu đã trích xuất
        Serial.print("N: ");
        Serial.println(data_N);
        Serial.print("S: ");
        Serial.println(data_S);
        Serial.print("V: ");
        Serial.println(data_V);
        Serial.print("F: ");
        Serial.println(data_F);
        Serial.print("Q: ");
        Serial.println(data_Q);
        Serial.print("Reset: ");
        Serial.println(Reset);
        Serial.print("Stop: ");
        Serial.println(Stop);

        tft.setFreeFont(&nulshock_bd12pt7b);

        tft.setTextColor(ILI9341_BLACK);
        tft.drawString("N", 67, 175);
        tft.drawString("S", 153, 175);
        tft.drawString("V", 30, 240);
        tft.drawString("F", 115, 240);
        tft.drawString("Q", 190, 240);

        tft.setFreeFont(&nulshock_bd9pt7b);

        tft.setTextColor(ILI9341_BLACK);
        tft.setCursor(58, 220);
        tft.println(data_N);

        tft.setTextColor(ILI9341_BLACK);
        tft.setCursor(143, 220);
        tft.println(data_S);

        tft.setTextColor(ILI9341_BLACK);
        tft.setCursor(20, 290);
        tft.println(data_V);

        tft.setTextColor(ILI9341_BLACK);
        tft.setCursor(100, 290);
        tft.println(data_F);

        tft.setTextColor(ILI9341_BLACK);
        tft.setCursor(180, 290);
        tft.println(data_Q);

        tft.fillRect(0, 205, 120, 30, ILI9341_WHITE);
        tft.fillRect(120, 205, 120, 30, ILI9341_WHITE);
        tft.fillRect(0, 275, 80, 30, ILI9341_WHITE);
        tft.fillRect(80, 275, 80, 30, ILI9341_WHITE);
        tft.fillRect(160, 275, 80, 30, ILI9341_WHITE);

        flag = 0;
    }
}