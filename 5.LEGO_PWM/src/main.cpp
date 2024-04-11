#include <Arduino.h>

const int ledPin = 16;  // chọn chân 16 xuất tín hiệu
 
// cài đặt PWM
const int freq = 10000;  // tần số xung
const int ledChannel = 0; // kênh PWM
const int resolution = 10; // độ phân giải 10bit

  
void setup(){
  // setup kênh pwm
  ledcSetup(ledChannel, freq, resolution);
   
  // xuất pwm ra chân 16
  ledcAttachPin(ledPin, ledChannel);
}
  
void loop(){
  // nhanh dần
  // for(int dutyCycle = 0; dutyCycle <= 511; dutyCycle++){   
    // changing the LED brightness with PWM
    ledcWrite(ledChannel, 1023);
    delay(100);
  // }
 
  // // chậm dần
  // // for(int dutyCycle = 1024; dutyCycle >= 0; dutyCycle--){
  //   // changing the LED brightness with PWM
  //   ledcWrite(ledChannel, dutyCycle);   
  // //   delay(100);
  // // }
}