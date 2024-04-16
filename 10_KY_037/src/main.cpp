#include <Arduino.h>

int sound_digital = 0;
int sound_analog = 4;

void setup(){
  Serial.begin(9600);
  pinMode(sound_digital, INPUT);  
}

void loop(){
  int val_digital = digitalRead(sound_digital);
  int val_analog = analogRead(sound_analog);

  Serial.print(val_analog);
  Serial.print("\t");
  Serial.println(val_digital);

  delay(1000);

}