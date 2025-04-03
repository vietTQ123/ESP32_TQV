#include <Arduino.h>

// Chân GPIO cho PWM output và biến trở
#define PWM_PIN 18 // Chân xuất xung PWM
#define POT_PIN 34 // Chân đọc biến trở (ADC1)

// Cấu hình PWM
const int freq = 5000;    // Tần số PWM 5 kHz
const int pwmChannel = 0; // Kênh PWM
const int resolution = 8; // Độ phân giải 8-bit (0-255)

void setup()
{
  Serial.begin(9600); // Khởi động Serial Monitor
  pinMode(POT_PIN, INPUT);
  ledcSetup(pwmChannel, freq, resolution);
  ledcAttachPin(PWM_PIN, pwmChannel);
}

void loop()
{
  int potValue = analogRead(POT_PIN);            // Đọc giá trị ADC (0-4095)
  int dutyCycle = map(potValue, 0, 4095, 0, 99); // Chuyển đổi sang 0-99
  ledcWrite(pwmChannel, dutyCycle);

  Serial.print("ADC Value: ");
  Serial.print(potValue);
  Serial.print(" | PWM Duty Cycle: ");
  Serial.println(dutyCycle);

  delay(10); // Giảm tải CPU
}