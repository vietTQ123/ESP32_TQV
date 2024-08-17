#include <Arduino.h>

int adcPin = 32;  

void setup() {
  Serial.begin(9600);
  pinMode(adcPin, INPUT);
}

void loop() {
  int adcValue = analogRead(adcPin);

  Serial.print("ADC Value: ");
  Serial.println(adcValue);
  
  delay(100);
}