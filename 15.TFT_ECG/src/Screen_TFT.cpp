#include <Screen_TFT.h>

TFT_eSPI tft = TFT_eSPI();

static int data_N;
static int data_S;
static int data_V;
static int data_F;
static int data_Q;
static int Reset;
static int Stop;

int data_N_new;
int data_N_old;
int data_S_new;
int data_S_old;
int data_V_new;
int data_V_old;
int data_F_new;
int data_F_old;
int data_Q_new;
int data_Q_old;

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
    if (Serial.available()) // Kiểm tra xem có dữ liệu nào trên cổng Serial không
    {
        String jsonMessage = Serial.readStringUntil('\n'); // Đọc dữ liệu JSON từ Serial cho đến khi gặp ký tự xuống dòng (\n)

        StaticJsonDocument<200> doc; // Tạo một đối tượng JSON để lưu trữ dữ liệu

        DeserializationError error = deserializeJson(doc, jsonMessage); // Giải mã dữ liệu JSON từ chuỗi

        if (error) // Kiểm tra xem có lỗi trong quá trình giải mã không
        {
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

    if (flag == 1)
    {
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

        data_N_new = data_N;
        data_S_new = data_S;
        data_V_new = data_V;
        data_F_new = data_F;
        data_Q_new = data_Q;

        tft.setFreeFont(&nulshock_bd12pt7b);

        tft.setTextColor(ILI9341_BLACK);
        tft.drawString("N", 67, 175);
        tft.drawString("S", 153, 175);
        tft.drawString("V", 30, 240);
        tft.drawString("F", 115, 240);
        tft.drawString("Q", 190, 240);

        tft.setFreeFont(&nulshock_bd9pt7b);

        if (data_N_new != data_N_old)
        {
            tft.fillRect(0, 205, 120, 30, ILI9341_WHITE);

            data_N_old = data_N_new;
        }

        tft.setTextColor(ILI9341_BLACK);

        if (0 <= data_N && data_N <= 9)
        {
            tft.setCursor(72, 220);
            tft.println(data_N);
        }
        else if (10 <= data_N && data_N <= 99)
        {
            tft.setCursor(65, 220);
            tft.println(data_N);
        }
        else if (100 <= data_N && data_N <= 999)
        {
            tft.setCursor(58, 220);
            tft.println(data_N);
        }
        else if (1000 <= data_N && data_N <=9999)
        {
            tft.setCursor(50, 220);
            tft.println(data_N);
        }

        if (data_S_new != data_S_old)
        {
            tft.fillRect(120, 205, 120, 30, ILI9341_WHITE);

            data_S_old = data_S_new;
        }

        tft.setTextColor(ILI9341_BLACK);

        if (0 <= data_S && data_S <= 9)
        {
            tft.setCursor(157, 220);
            tft.println(data_S);
        }
        else if (10 <= data_S && data_S <= 99)
        {
            tft.setCursor(150, 220);
            tft.println(data_S);
        }
        else if (100 <= data_S && data_S <= 999)
        {
            tft.setCursor(143, 220);
            tft.println(data_S);
        }
        else if (1000 <= data_S && data_S <= 9999)
        {
            tft.setCursor(135, 220);
            tft.println(data_S);
        }

        if (data_V_new != data_V_old)
        {
            tft.fillRect(0, 275, 80, 30, ILI9341_WHITE);

            data_V_old = data_V_new;
        }

        tft.setTextColor(ILI9341_BLACK);

        if (0 <= data_V && data_V <= 9)
        {
            tft.setCursor(37, 290);
            tft.println(data_V);
        }
        else if (10 <= data_V && data_V <= 99)
        {
            tft.setCursor(30, 290);
            tft.println(data_V);
        }
        else if (100 <= data_V && data_V <= 999)
        {
            tft.setCursor(20, 290);
            tft.println(data_V);
        }
        else if (1000 <= data_V && data_V <= 9999)
        {
            tft.setCursor(15, 290);
            tft.println(data_V);
        }

        if (data_F_new != data_F_old)
        {
            tft.fillRect(80, 275, 80, 30, ILI9341_WHITE);

            data_F_old = data_F_new;
        }

        tft.setTextColor(ILI9341_BLACK);

        if (0 <= data_F && data_F <= 9)
        {
            tft.setCursor(117, 290);
            tft.println(data_F);
        }
        else if (10 <= data_F && data_F <= 99)
        {
            tft.setCursor(110, 290);
            tft.println(data_F);
        }
        else if (100 <= data_F && data_F <= 999)
        {
            tft.setCursor(100, 290);
            tft.println(data_F);
        }
        else if (1000 <= data_F && data_F <= 9999)
        {
            tft.setCursor(95, 290);
            tft.println(data_F);
        }

        if (data_Q_new != data_Q_old)
        {
            tft.fillRect(160, 275, 80, 30, ILI9341_WHITE);

            data_Q_old = data_Q_new;
        }

        tft.setTextColor(ILI9341_BLACK);

        if (0 <= data_Q && data_Q <= 9)
        {
            tft.setCursor(197, 290);
            tft.println(data_Q);
        }
        else if (10 <= data_Q && data_Q <= 99)
        {
            tft.setCursor(190, 290);
            tft.println(data_Q);
        }
        else if (100 <= data_Q && data_Q <= 999)
        {
            tft.setCursor(180, 290);
            tft.println(data_Q);
        }
        else if (1000 <= data_Q && data_Q <= 9999)
        {
            tft.setCursor(175, 290);
            tft.println(data_Q);
        }

        flag = 0;
    }
}

// 0 -> 9
// tft.setCursor(72, 220); N
// tft.setCursor(157, 220); S
// tft.setCursor(37, 290); V
// tft.setCursor(117, 290); F
// tft.setCursor(197, 290); Q

// 10 - 99
// tft.setCursor(65, 220); N
// tft.setCursor(150, 220); S
// tft.setCursor(30, 290); V
// tft.setCursor(110, 290); F
// tft.setCursor(190, 290); Q

// 100 -> 999
// tft.setCursor(58, 220); N
// tft.setCursor(143, 220); S
// tft.setCursor(20, 290); V
// tft.setCursor(100, 290); F
// tft.setCursor(180, 290); Q

// 1000 -> 9999
// tft.setCursor(50, 220); N
// tft.setCursor(135, 220); S
// tft.setCursor(25, 290); V
// tft.setCursor(95, 290); F
// tft.setCursor(175, 290); Q

// xóa màn hình
// tft.fillRect(0, 205, 120, 30, ILI9341_WHITE);
// tft.fillRect(120, 205, 120, 30, ILI9341_WHITE);
// tft.fillRect(0, 275, 80, 30, ILI9341_WHITE);
// tft.fillRect(80, 275, 80, 30, ILI9341_WHITE);
// tft.fillRect(160, 275, 80, 30, ILI9341_WHITE);