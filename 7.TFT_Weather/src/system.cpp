#include <system.h>

char ssid[30] = "Embedded AIoT Lab(2G)";
char password[30] = "embeddedlab";

// char ssid[30] = "Kim Thanh 2.4ghz";
// char password[30] = "88888888";

struct TIME
{
    unsigned int Hournew;
    unsigned int Hourold;
    unsigned int Minutenew;
    unsigned int Minuteold;
};

struct TEMP
{
    int Tempnew;
    int Tempold;
    int Huminew;
    int Humiold;
};

struct DAY
{
    char daynew[4];
    char dayold[4];
};

char Daymon[4] = "Mon";
char Daytue[4] = "Tue";
char Daywed[4] = "Wed";
char Daythu[4] = "Thu";
char Dayfri[4] = "Fri";
char Daysat[4] = "Sat";
char Daysun[4] = "Sun";

struct TIME TIME;
struct TEMP TEMP;
struct DAY DAY;

int count=0;

TFT_eSPI tft = TFT_eSPI();

hw_timer_t *Timer0_Cfg = NULL;

void IRAM_ATTR check_status()
{
    count=(count+1)%19;
}

unsigned int rainbow(byte value)
{
    byte red = 0;   // Red is the top 5 bits of a 16 bit colour value
    byte green = 0; // Green is the middle 6 bits
    byte blue = 0;  // Blue is the bottom 5 bits

    byte quadrant = value / 32;

    if (quadrant == 0)
    {
        blue = 31;
        green = 2 * (value % 32);
        red = 0;
    }
    if (quadrant == 1)
    {
        blue = 31 - (value % 32);
        green = 63;
        red = 0;
    }
    if (quadrant == 2)
    {
        blue = 0;
        green = 63;
        red = value % 32;
    }
    if (quadrant == 3)
    {
        blue = 0;
        green = 63 - 2 * (value % 32);
        red = 31;
    }
    return (red << 11) + (green << 5) + blue;
}

int ringMeter(int value, int vmin, int vmax, int x, int y, int r, char units, byte scheme)
{
    x += r;
    y += r; // Calculate coords of centre of ring

    int w = r / 4; // Width of outer ring is 1/4 of radius

    int angle = 150; // Half the sweep angle of meter (300 degrees)

    int text_colour = 0; // To hold the text colour

    int v = map(value, vmin, vmax, -angle, angle); // Map the value to an angle v

    byte seg = 5; // Segments are 5 degrees wide = 60 segments for 300 degrees
    byte inc = 5; // Draw segments every 5 degrees, increase to 10 for segmented ring

    // Draw colour blocks every inc degrees
    for (int i = -angle; i < angle; i += inc)
    {

        // Choose colour from scheme
        int colour = 0;
        switch (scheme)
        {
        case 0:
            colour = TFT_RED;
            break; // Fixed colour
        case 1:
            colour = TFT_GREEN;
            break; // Fixed colour
        case 2:
            colour = TFT_BLUE;
            break; // Fixed colour
        case 3:
            colour = rainbow(map(i, -angle, angle, 0, 127));
            break; // Full spectrum blue to red
        case 4:
            colour = rainbow(map(i, -angle, angle, 63, 127));
            break; // Green to red (high temperature etc)
        case 5:
            colour = rainbow(map(i, -angle, angle, 127, 63));
            break; // Red to green (low battery etc)
        case 6:
            colour = rainbow(map(i, -angle, angle, 30, 0));
            break; // lightblue to darkblue
        default:
            colour = TFT_BLUE;
            break; // Fixed colour
        }

        // Calculate pair of coordinates for segment start
        float sx = cos((i - 90) * 0.0174532925);
        float sy = sin((i - 90) * 0.0174532925);
        uint16_t x0 = sx * (r - w) + x;
        uint16_t y0 = sy * (r - w) + y;
        uint16_t x1 = sx * r + x;
        uint16_t y1 = sy * r + y;

        // Calculate pair of coordinates for segment end
        float sx2 = cos((i + seg - 90) * 0.0174532925);
        float sy2 = sin((i + seg - 90) * 0.0174532925);
        int x2 = sx2 * (r - w) + x;
        int y2 = sy2 * (r - w) + y;
        int x3 = sx2 * r + x;
        int y3 = sy2 * r + y;

        if (i < v)
        { // Fill in coloured segments with 2 triangles
            tft.fillTriangle(x0, y0, x1, y1, x2, y2, colour);
            tft.fillTriangle(x1, y1, x2, y2, x3, y3, colour);
            text_colour = colour; // Save the last colour drawn
        }
        else // Fill in blank segments
        {
            tft.fillTriangle(x0, y0, x1, y1, x2, y2, TFT_DARKGREY);
            tft.fillTriangle(x1, y1, x2, y2, x3, y3, TFT_DARKGREY);
        }
    }

    // Convert value to a string
    char buf[10];
    byte len = 4;
    if (value > 999)
        len = 5;
    dtostrf(value, 5, 1, buf);

    // Set the text colour to default
    // tft.setTextColor(ILI9341_WHITE, ILI9341_BLACK);
    // Uncomment next line to set the text colour to the last segment value!

    // toegevoegd omdat de library Adafruit_GFX geen functie drawCentreString heeft

    if (text_colour < 31)
    {
        text_colour = TFT_DARKGREY;
    }
    // tft.setTextColor(text_colour, ILI9341_BLACK);
    // tft.setTextSize(3);
    // tft.setCursor(x - 50, y - 25);
    // tft.print(buf);

    tft.setTextColor(text_colour, TFT_BLACK);
    tft.setTextSize(2);
    tft.setCursor(x - 5, y - 5);
    tft.print(units);

    return x + r;
}

void Load_credentials()
{
    EEPROM.begin(512);
    EEPROM.get(0, ssid);
    EEPROM.get(0 + sizeof(ssid), password);
    char ok[2 + 1];
    EEPROM.get(0 + sizeof(ssid) + sizeof(password), ok);
    EEPROM.end();
    if (String(ok) != String("OK"))
    {
        ssid[0] = 0;
        password[0] = 0;
    }
    Serial.println("Recovered credentials:");
    Serial.println(ssid);
    Serial.println(password);
    Serial.println(strlen(password) > 0 ? "******" : "<no password>");
}

void Save_credentials()
{
    EEPROM.begin(512);
    EEPROM.put(0, ssid);
    EEPROM.put(0 + sizeof(ssid), password);
    char ok[2 + 1] = "OK";
    EEPROM.put(0 + sizeof(ssid) + sizeof(password), ok);
    EEPROM.commit();
    EEPROM.end();
    Serial.print("Saving SSID: ");
    Serial.println(ssid);
    Serial.print("Password: ");
    Serial.println(password);
    Serial.println("Done");
}

const unsigned short* animation [19] = {
    dragon_1,
    dragon_2,
    dragon_3,
    dragon_4,
    dragon_5,
    dragon_6,
    dragon_7,
    dragon_8,
    dragon_9,
    dragon_10,
    dragon_11,
    dragon_12,
    dragon_13,
    dragon_14,
    dragon_15,
    dragon_16,
    dragon_17,
    dragon_18,
    dragon_19
};

void Setup_weather()
{
    Serial.begin(115200);

    Connect_wifi();

    Timer0_Cfg = timerBegin(0, 8000, true);
    timerAttachInterrupt(Timer0_Cfg, &check_status, true);
    timerAlarmWrite(Timer0_Cfg, 1000, true); // 10ms
    timerAlarmEnable(Timer0_Cfg);

    Time_setup();

    tft.init();
    tft.fillScreen(tft.color565(0, 0, 0));
    tft.setSwapBytes(true);
}

void Run_weather()
{
    String serverPath = "http://api.openweathermap.org/data/2.5/forecast?q=" + city + "," + countryCode + "&cnt=4&APPID=" + Apikey;

    Weather_Infor();

    tft.pushImage(80,205,80,80,animation[count]);

    tft.pushImage(190, 120, 40, 40, sunshine);
    tft.pushImage(15, 30, 40, 40, cloudy);
    tft.pushImage(102, 35, 40, 40, wind);
    tft.pushImage(185, 35, 40, 40, rain);
    tft.pushImage(105, 290, 30, 30, wifi);
    tft.pushImage(210, 290, 30, 30, right_arrow);
    tft.pushImage(5, 290, 30, 30, left_arrow);

    struct tm timeinfo;

    if (!getLocalTime(&timeinfo))
    {
        Serial.println("Failed to obtain time");
        return;
    }

    char Daynow[4];
    strftime(Daynow, 4, "%a", &timeinfo);

    strcpy(DAY.daynew, Daynow);

    if (strcmp(Daynow, Daymon) == 0 && strcmp(DAY.daynew, DAY.dayold) != 0)
    {
        tft.fillRect(0, 0, 240, 25, tft.color565(0, 0, 0));

        tft.setFreeFont(&SFProText_Semibold10pt7b);
        tft.setCursor(15, 25);
        tft.setTextColor(tft.color565(124, 202, 0));
        tft.setTextSize(1);
        tft.println("TUE");
        tft.setCursor(105, 25);
        tft.setTextColor(tft.color565(124, 202, 0));
        tft.setTextSize(1);
        tft.println("WED");
        tft.setCursor(185, 25);
        tft.setTextColor(tft.color565(124, 202, 0));
        tft.setTextSize(1);
        tft.println("THU");

        strcpy(DAY.dayold, DAY.daynew);
    }

    if (strcmp(Daynow, Daytue) == 0 && strcmp(DAY.daynew, DAY.dayold) != 0)
    {
        tft.fillRect(0, 0, 240, 25, tft.color565(0, 0, 0));

        tft.setFreeFont(&SFProText_Semibold10pt7b);
        tft.setCursor(15, 25);
        tft.setTextColor(tft.color565(124, 202, 0));
        tft.setTextSize(1);
        tft.println("WED");
        tft.setCursor(100, 25);
        tft.setTextColor(tft.color565(124, 202, 0));
        tft.setTextSize(1);
        tft.println("THU");
        tft.setCursor(190, 25);
        tft.setTextColor(tft.color565(124, 202, 0));
        tft.setTextSize(1);
        tft.println("FRI");

        strcpy(DAY.dayold, DAY.daynew);
    }

    if (strcmp(Daynow, Daywed) == 0 && strcmp(DAY.daynew, DAY.dayold) != 0)
    {
        tft.fillRect(0, 0, 240, 25, tft.color565(0, 0, 0));

        tft.setFreeFont(&SFProText_Semibold10pt7b);
        tft.setCursor(15, 25);
        tft.setTextColor(tft.color565(124, 202, 0));
        tft.setTextSize(1);
        tft.println("THU");
        tft.setCursor(105, 25);
        tft.setTextColor(tft.color565(124, 202, 0));
        tft.setTextSize(1);
        tft.println("FRI");
        tft.setCursor(185, 25);
        tft.setTextColor(tft.color565(124, 202, 0));
        tft.setTextSize(1);
        tft.println("SAT");

        strcpy(DAY.dayold, DAY.daynew);
    }

    if (strcmp(Daynow, Daythu) == 0 && strcmp(DAY.daynew, DAY.dayold) != 0)
    {
        tft.fillRect(0, 0, 240, 25, tft.color565(0, 0, 0));

        tft.setFreeFont(&SFProText_Semibold10pt7b);
        tft.setCursor(15, 25);
        tft.setTextColor(tft.color565(124, 202, 0));
        tft.setTextSize(1);
        tft.println("FRI");
        tft.setCursor(105, 25);
        tft.setTextColor(tft.color565(124, 202, 0));
        tft.setTextSize(1);
        tft.println("SAT");
        tft.setCursor(185, 25);
        tft.setTextColor(tft.color565(124, 202, 0));
        tft.setTextSize(1);
        tft.println("SUN");

        strcpy(DAY.dayold, DAY.daynew);
    }

    if (strcmp(Daynow, Dayfri) == 0 && strcmp(DAY.daynew, DAY.dayold) != 0)
    {
        tft.fillRect(0, 0, 240, 25, tft.color565(0, 0, 0));

        tft.setFreeFont(&SFProText_Semibold10pt7b);
        tft.setCursor(15, 25);
        tft.setTextColor(tft.color565(124, 202, 0));
        tft.setTextSize(1);
        tft.println("SAT");
        tft.setCursor(105, 25);
        tft.setTextColor(tft.color565(124, 202, 0));
        tft.setTextSize(1);
        tft.println("SUN");
        tft.setCursor(185, 25);
        tft.setTextColor(tft.color565(124, 202, 0));
        tft.setTextSize(1);
        tft.println("MON");

        strcpy(DAY.dayold, DAY.daynew);
    }

    if (strcmp(Daynow, Daysat) == 0 && strcmp(DAY.daynew, DAY.dayold) != 0)
    {
        tft.fillRect(0, 0, 240, 25, tft.color565(0, 0, 0));

        tft.setFreeFont(&SFProText_Semibold10pt7b);
        tft.setCursor(15, 25);
        tft.setTextColor(tft.color565(124, 202, 0));
        tft.setTextSize(1);
        tft.println("SUN");
        tft.setCursor(103, 25);
        tft.setTextColor(tft.color565(124, 202, 0));
        tft.setTextSize(1);
        tft.println("MON");
        tft.setCursor(185, 25);
        tft.setTextColor(tft.color565(124, 202, 0));
        tft.setTextSize(1);
        tft.println("TUE");

        strcpy(DAY.dayold, DAY.daynew);
    }

    if (strcmp(Daynow, Daysun) == 0 && strcmp(DAY.daynew, DAY.dayold) != 0)
    {
        tft.fillRect(0, 0, 240, 25, tft.color565(0, 0, 0));

        tft.setFreeFont(&SFProText_Semibold10pt7b);
        tft.setCursor(15, 25);
        tft.setTextColor(tft.color565(124, 202, 0));
        tft.setTextSize(1);
        tft.println("MON");
        tft.setCursor(105, 25);
        tft.setTextColor(tft.color565(124, 202, 0));
        tft.setTextSize(1);
        tft.println("TUE");
        tft.setCursor(185, 25);
        tft.setTextColor(tft.color565(124, 202, 0));
        tft.setTextSize(1);
        tft.println("WED");

        strcpy(DAY.dayold, DAY.daynew);
    }

    tft.drawFastHLine(0, 88, 240, tft.color565(255, 255, 255));

    tft.setFreeFont(&SFProText_Semibold10pt7b);
    tft.setCursor(5, 105);
    tft.setTextColor(tft.color565(238, 7, 1));
    tft.setTextSize(1);
    tft.println(&timeinfo, "%a, %b %d %Y");

    tft.setCursor(5, 195);
    tft.setTextColor(tft.color565(255, 160, 0));
    tft.setFreeFont(&Notably_Absent_DEMO12pt7b);
    tft.setTextSize(1);
    tft.println("HA NOI , VIET NAM");

    char timeHour[3];
    char timeMinute[3];
    strftime(timeHour, 3, "%H", &timeinfo);
    strftime(timeMinute, 3, "%M", &timeinfo);

    TIME.Hournew = timeHour[0] * 10 + timeHour[1];
    TIME.Minutenew = timeMinute[0] * 10 + timeMinute[1];

    if (TIME.Hournew != TIME.Hourold)
    {
        tft.fillRect(3, 123, 100, 50, tft.color565(0, 0, 0));

        TIME.Hourold = TIME.Hournew;
    }

    tft.setCursor(3, 163);
    tft.setTextColor(tft.color565(255, 255, 0));
    tft.setFreeFont(&DSEG7_Classic_Mini_Bold_40);
    tft.print(timeHour);

    tft.print(":");

    if (TIME.Minutenew != TIME.Minuteold)
    {

        tft.fillRect(80, 123, 100, 50, tft.color565(0, 0, 0));

        TIME.Minuteold = TIME.Minutenew;
    }

    tft.setCursor(80, 163);
    tft.setTextColor(tft.color565(255, 255, 0));
    tft.setFreeFont(&DSEG7_Classic_Mini_Bold_40);
    tft.print(timeMinute);

    tft.drawFastHLine(0, 200, 240, tft.color565(255, 255, 255));

    tft.setFreeFont(&SFProText_Semibold12pt7b);

    TEMP.Tempnew = Current_temp();
    TEMP.Huminew = Current_humi();

    if (TEMP.Tempnew != TEMP.Tempold)
    {
        tft.fillRect(10, 260, 60, 30, tft.color565(0, 0, 0));

        TEMP.Tempold = TEMP.Tempnew;
    }

    tft.setCursor(10, 280);
    tft.setTextColor(tft.color565(255, 255, 255));
    tft.setTextSize(1);
    tft.println(TEMP.Tempnew);

    if (TEMP.Huminew != TEMP.Humiold)
    {
        tft.fillRect(185, 260, 60, 30, tft.color565(0, 0, 0));

        TEMP.Humiold = TEMP.Huminew;
    }

    tft.setCursor(185, 280);
    tft.setTextColor(tft.color565(255, 255, 255));
    tft.setTextSize(1);
    tft.println(TEMP.Huminew);

    tft.drawCircle(45, 267, 3, tft.color565(255, 255, 255));
    tft.setFreeFont();
    tft.setTextSize(2);
    tft.setCursor(53, 265);
    tft.println("C");
    tft.setCursor(223, 265);
    tft.println("%");

    ringMeter((int)Current_temp(), -10, 50, 10, 210, 25, 'T', BLUE2RED);
    ringMeter((int)Current_humi(), 0, 100, 185, 210, 25, 'H', LBLUE2DBLUE);
}
