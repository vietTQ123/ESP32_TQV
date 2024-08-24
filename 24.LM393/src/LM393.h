#ifndef __LM_393__
#define __LM_393__

#include "Arduino.h"

#define PIN_ANALOG_LM393 25
#define PIN_DIGITAL_LM393 27

void LM393_Setup(void);
int LM393_Soil_Moisture(void);
int LM393_Check_Soil_Moisture(void);

#endif