#include <Arduino.h>
#include <timer.h>

#define LAZER 12

int stt_lazer_new = 0;
int stt_lazer_old;
int rpm;

int count_round;

void setup()
{
  Serial.begin(9600);

  pinMode(LAZER, INPUT);

  Setup_Timer();
}

void loop()
{
  if (flag_end != 1)
  {
    stt_lazer_old = stt_lazer_new;
    stt_lazer_new = digitalRead(LAZER);
    if ((stt_lazer_old == 0) && (stt_lazer_new == 1))
    {
      count_round++;
    }
  }
  if (flag_end == 1)
  {
    rpm = count_round/3;
    count_round = 0;
    flag_end = 0;
  }

  Serial.print(count_round);
  Serial.print("  ");
  Serial.print(flag_time);
  Serial.print("  ");
  Serial.print(flag_end);
  Serial.println();
}
