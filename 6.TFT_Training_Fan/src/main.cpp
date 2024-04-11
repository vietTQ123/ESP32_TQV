#include <system.h>

int stt = -1;

enum state {
    OFF = 0,
    ON = 1,
    TAP = 2,
    MOUNT_FALL = 3,
    FLOW_BLOCK = 4,
    BLADE_FAULT = 5
};

void setup()
{
    Serial.begin(115200);
    setup_tft();
}

void loop()
{
    if (Serial.available())
    {
        stt = Serial.parseInt();
    }
    switch (stt)
    {
    case OFF:
        Serial.println("OFF");
        off();
        break;
    case ON:
        Serial.println("ON");
        on();
        break;
    case TAP:
        Serial.println("TAP");
        tapping();
        break;
    case MOUNT_FALL:
        Serial.println("MOUNT FALL");
        mount_fault();
        break;
    case FLOW_BLOCK:
        Serial.println("FLOW BLOCK");
        flow_blocked();
        break;
    case BLADE_FAULT:
        Serial.println("BLADE FAULT");
        blade_fault();
        break;
    default:
        off();
        break;
    }
}
