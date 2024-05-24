#include <Screen_TFT.h>

void setup()
{
 TFT_Setup();
}

int cnt = 0;

void loop()
{
  TFT_Clean();
  TFT_Screen(cnt, cnt);
  delay(1000);
  cnt ++;
}