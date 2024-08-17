#include <Arduino.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <eyes.h>

#define SCREEN_I2C_ADDR 0x3C // or 0x3C
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void setup()
{
	display.begin(SSD1306_SWITCHCAPVCC, SCREEN_I2C_ADDR);

	if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3c))
	{
		Serial.println(F("SSD1306 allocation failed"));
		for (;;)
			;
	}

	display.display();
	display.clearDisplay();
	display.display();
}

void loop()
{
	// ^ ^ lớn
	display.clearDisplay();
	display.drawBitmap(24, 16, peyes[0][0][0], 32, 32, WHITE);
	display.drawBitmap(72, 16, peyes[0][0][0], 32, 32, WHITE);
	display.display();
	delay(500);

	// ^ ^ nhỏ
	display.clearDisplay();
	display.drawBitmap(24, 16, peyes[0][1][0], 32, 32, WHITE);
	display.drawBitmap(72, 16, peyes[0][1][0], 32, 32, WHITE);
	display.display();
	delay(500);

	// ^ ^ nhỏ cao
	display.clearDisplay();
	display.drawBitmap(24, 16, peyes[0][2][0], 32, 32, WHITE);
	display.drawBitmap(72, 16, peyes[0][2][0], 32, 32, WHITE);
	display.display();
	delay(500);

	// o o lớn
	display.clearDisplay();
	display.drawBitmap(24, 16, peyes[1][0][0], 32, 32, WHITE);
	display.drawBitmap(72, 16, peyes[1][0][0], 32, 32, WHITE);
	display.display();
	delay(500);
	
	// o o nhỏ
	display.clearDisplay();
	display.drawBitmap(24, 16, peyes[1][1][0], 32, 32, WHITE);
	display.drawBitmap(72, 16, peyes[1][1][0], 32, 32, WHITE);
	display.display();
	delay(500);

	// o o nhỏ cao
	display.clearDisplay();
	display.drawBitmap(24, 16, peyes[1][2][0], 32, 32, WHITE);
	display.drawBitmap(72, 16, peyes[1][2][0], 32, 32, WHITE);
	display.display();
	delay(500);

	// - - 
	display.clearDisplay();
	display.drawBitmap(24, 16, peyes[2][0][0], 32, 32, WHITE);
	display.drawBitmap(72, 16, peyes[2][0][0], 32, 32, WHITE);
	display.display();
	delay(500);
	
	// - - 
	display.clearDisplay();
	display.drawBitmap(24, 16, peyes[2][1][0], 32, 32, WHITE);
	display.drawBitmap(72, 16, peyes[2][1][0], 32, 32, WHITE);
	display.display();
	delay(500);

	// - - 
	display.clearDisplay();
	display.drawBitmap(24, 16, peyes[2][2][0], 32, 32, WHITE);
	display.drawBitmap(72, 16, peyes[2][2][0], 32, 32, WHITE);
	display.display();
	delay(500);

	// 0\ 0\ lớn
	display.clearDisplay();
	display.drawBitmap(24, 16, peyes[3][0][0], 32, 32, WHITE);
	display.drawBitmap(72, 16, peyes[3][0][0], 32, 32, WHITE);
	display.display();
	delay(500);

	// 0\ 0\ nhỏ
	display.clearDisplay();
	display.drawBitmap(24, 16, peyes[3][1][0], 32, 32, WHITE);
	display.drawBitmap(72, 16, peyes[3][1][0], 32, 32, WHITE);
	display.display();
	delay(500);

	// 0\ 0\ nhỏ cao
	display.clearDisplay();
	display.drawBitmap(24, 16, peyes[3][2][0], 32, 32, WHITE);
	display.drawBitmap(72, 16, peyes[3][2][0], 32, 32, WHITE);
	display.display();
	delay(500);

	//-0 -0 lớn
	display.clearDisplay();
	display.drawBitmap(24, 16, peyes[4][0][0], 32, 32, WHITE);
	display.drawBitmap(72, 16, peyes[4][0][0], 32, 32, WHITE);
	display.display();
	delay(500);
	
	//-0 -0 nhỏ
	display.clearDisplay();
	display.drawBitmap(24, 16, peyes[4][1][0], 32, 32, WHITE);
	display.drawBitmap(72, 16, peyes[4][1][0], 32, 32, WHITE);
	display.display();
	delay(500);

	//-0 -0 nhỏ cao
	display.clearDisplay();
	display.drawBitmap(24, 16, peyes[4][2][0], 32, 32, WHITE);
	display.drawBitmap(72, 16, peyes[4][2][0], 32, 32, WHITE);
	display.display();
	delay(500);

	// /0 /0 lớn
	display.clearDisplay();
	display.drawBitmap(24, 16, peyes[5][0][0], 32, 32, WHITE);
	display.drawBitmap(72, 16, peyes[5][0][0], 32, 32, WHITE);
	display.display();
	delay(500);
	
	// /0 /0 nhỏ
	display.clearDisplay();
	display.drawBitmap(24, 16, peyes[5][1][0], 32, 32, WHITE);
	display.drawBitmap(72, 16, peyes[5][1][0], 32, 32, WHITE);
	display.display();
	delay(500);
	
	// /0 /0 nhỏ cao
	display.clearDisplay();
	display.drawBitmap(24, 16, peyes[5][2][0], 32, 32, WHITE);
	display.drawBitmap(72, 16, peyes[5][2][0], 32, 32, WHITE);
	display.display();
	delay(500);
	display.clearDisplay();

	// /0 0\ 
	display.clearDisplay();
	display.drawBitmap(24, 16, peyes[5][0][0], 32, 32, WHITE);
	display.drawBitmap(72, 16, peyes[5][0][1], 32, 32, WHITE);
	display.display();
	delay(3000);
	display.clearDisplay();

	// 0\ /0
	display.clearDisplay();
	display.drawBitmap(24, 16, peyes[3][0][0], 32, 32, WHITE);
	display.drawBitmap(72, 16, peyes[3][0][1], 32, 32, WHITE);
	display.display();
	delay(3000);
	display.clearDisplay();

}