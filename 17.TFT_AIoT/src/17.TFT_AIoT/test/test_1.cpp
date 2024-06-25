void TFT_Setup()
{
    Serial.begin(9600);

    tft.init();
    tft.setRotation(0);
    tft.fillScreen(TFT_WHITE);
    tft.setSwapBytes(true);

    tft.drawFastHLine(0,80,240,TFT_BLACK);
    tft.drawFastHLine(0,160,240,TFT_BLACK);

}

void TFT_Screen()
{   
    tft.pushImage(62,33,32,32,sun);

    tft.setTextColor(tft.color565(157,203,128));
    tft.setFreeFont(&DSEG7_Classic_Mini_Bold_30);
    tft.drawString ("25",120,35);

    tft.drawCircle(175, 38, 4, tft.color565(157,203,128));
    tft.setFreeFont();
    tft.drawString("C",185,36,4);

    tft.setTextColor (tft.color565(82,226,242));
    tft.drawString ("HUMIDITY:",10,90,4);
    tft.setFreeFont(&DSEG7_Classic_Mini_Bold_25);
    tft.drawString ("90",140,87);
    tft.drawString ("%",185,90,4);

    tft.setTextColor(tft.color565(242,220,155));
    tft.drawString ("WIND:",10,130,4);
    tft.setFreeFont(&DSEG7_Classic_Mini_Bold_25);
    tft.drawString ("5",90,127);
    tft.drawString ("Km/h",120,130,4);

    tft.setTextColor(tft.color565(242,107,94));
    tft.drawString ("HA NOI",83,170,4);
    tft.drawString ("16/05/2024",56,195,4);
}