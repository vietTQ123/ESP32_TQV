#include <Arduino.h>
#include <U8g2lib.h>
#include <Wire.h>
#include "arduinoFFT.h"
#include <driver/i2s.h>


#define I2S_WS GPIO_NUM_15
#define I2S_SD GPIO_NUM_13
#define I2S_SCK GPIO_NUM_2
#define I2S_PORT I2S_NUM_0

#define SAMPLE_RATE 44100

#define I2S_MIC_CHANNEL I2S_CHANNEL_FMT_ONLY_LEFT

// comment this to save some memory:
#define USE_32BIT_SAMPLING

#define SAMPLE_BUFFER_SIZE 512  // number of samples

#define PX2 0  // screen origin (left side edge)
#define PY1 16 // Bottom edge of waveform screen (counting from the top edge) - also yellow zone
#define PY2 55 // lower edge of spectrum screen (-50db)7

int barLength(double d);

const uint16_t samples = 64; //This value MUST ALWAYS be a power of 2
const double signalFrequency = 1000;
const double samplingFrequency = 5000;
const uint8_t amplitude = 100;

double vReal[SAMPLE_BUFFER_SIZE];
double vImag[SAMPLE_BUFFER_SIZE];

ArduinoFFT<double> FFT = ArduinoFFT<double>(vReal, vImag, samples, samplingFrequency);
 
// Computational domain of FFT:


// raw waveform data:
#ifdef USE_32BIT_SAMPLING
#define MIC_BITS_PER_SAMPLE  I2S_BITS_PER_SAMPLE_32BIT
int32_t wave[SAMPLE_BUFFER_SIZE];
#else
#define MIC_BITS_PER_SAMPLE  I2S_BITS_PER_SAMPLE_16BIT
int16_t wave[SAMPLE_BUFFER_SIZE];
#endif
double maxWave = 0.0;  // to compute scaling factor for wave display

U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);

void performFFT()
{
  // Prepare FFT calculation data (1.7ms)
  for (int i = 0; i < SAMPLE_BUFFER_SIZE; i++) {
    //vReal[i] = wave[i]; //(wave[i] - 2048) * 3.3 / 4096.0; // convert to voltage
    vReal[i] = wave[i] * 3.3 / 4096.0; // convert to voltage
    vImag[i] = 0;
  }
 
  // Calculate FFT (33ms)
  FFT.windowing(vReal, SAMPLE_BUFFER_SIZE, FFT_WIN_TYP_HAMMING, FFT_FORWARD); // Apply window function (Hamming)
 
  FFT.compute(vReal, vImag, SAMPLE_BUFFER_SIZE, FFT_FORWARD); // FFT
 
  FFT.complexToMagnitude(vReal, vImag, SAMPLE_BUFFER_SIZE); // Calculate absolute value
}

bool getWave() 
{

  //for (int i = 0; i < SAMPLE_BUFFER_SIZE; ++i) {
  //  wave[i] = 0;
  //}

  size_t bytesIn = 0;
  esp_err_t result = i2s_read(I2S_PORT, &wave, sizeof(wave), &bytesIn, portMAX_DELAY);
  /*
  */  
  if (result == ESP_OK)
  {
    maxWave = 0.0;
    int tmp;
    int samples_read = bytesIn / sizeof(wave[0]);
    if (samples_read > 0) {
      //Serial.println(samples_read);
      for (int i = 0; i < samples_read; ++i) {
        //wave[i] /= 4096;
        wave[i] >>= 16;
        if((tmp=abs(wave[i])) > maxWave)
        {
          maxWave = tmp;
        }
        //Serial.println(wave[i]);
      }
    }
  }
  return result;
}

void i2s_install() {
  const i2s_config_t i2s_config = {
    .mode = i2s_mode_t(I2S_MODE_MASTER | I2S_MODE_RX),
    .sample_rate = SAMPLE_RATE,
    .bits_per_sample = MIC_BITS_PER_SAMPLE, // I2S_BITS_PER_SAMPLE_16BIT or I2S_BITS_PER_SAMPLE_32BIT
    .channel_format = I2S_MIC_CHANNEL,      // L/R to high - left, L/R to ground - right channel
    .communication_format = i2s_comm_format_t(I2S_COMM_FORMAT_STAND_I2S),
    .intr_alloc_flags = 0, // default interrupt priority
    //.intr_alloc_flags = ESP_INTR_FLAG_LEVEL1,
    .dma_buf_count = 4,
    .dma_buf_len = 1024,
    .use_apll = false,
    .tx_desc_auto_clear = false,
    .fixed_mclk = 0
  };

  i2s_driver_install(I2S_PORT, &i2s_config, 0, NULL);
}

void i2s_setpin() {
  const i2s_pin_config_t pin_config = {
    .bck_io_num = I2S_SCK,
    .ws_io_num = I2S_WS,
    .data_out_num = I2S_PIN_NO_CHANGE,
    .data_in_num = I2S_SD
  };

  i2s_set_pin(I2S_PORT, &pin_config);
}

void initDisplay()
{
  u8g2.begin();
  u8g2.setFont(u8g2_font_6x10_tf);
  u8g2.setDrawColor(1);
  u8g2.setFontPosTop();     // Upper left is the character position
  u8g2.clearBuffer();
  u8g2.drawStr( 0, 0, "Start FFT v0.4");
  u8g2.sendBuffer();
}

void displayError(const char* msg)
{
  u8g2.clearBuffer();   // Screen buffer clear (22us)
  u8g2.setFont(u8g2_font_crox1cb_tf); // With a larger font
  u8g2.drawStr( 0, 0, "Error:");
  u8g2.setFont(u8g2_font_6x10_tf);
  u8g2.drawStr( 0, 20, msg);
  u8g2.sendBuffer();    // (30ms)
  delay(1);             // Magic against write failure
}

#define PX2 0  // screen origin (left side edge)
#define PY1 16 // Bottom edge of waveform screen (counting from the top edge) - also yellow zone
#define PY2 55 // lower edge of spectrum screen (-50db)

void showWaveform() {   // Input waveform display
  int offset = PY1/2;
  int factor = round(maxWave * 1.2 / offset);
  for (int i = 0; i < 128; i++) {
    int x = PX2 + i;
    int y1 = PY1 - wave[i] / factor - offset;
    int y2 = PY1 - wave[i + 1] / factor - offset;
    //u8g2.drawLine(PX2 + i, PY1 - (wave[i * 2]) / 256, PX2 + i + 1, 16 - (wave[i * 2 + 1] / 256)); // waveform plot
    u8g2.drawLine(x, y1, x + 1, y2); // waveform plot
  }
}
 
void showSpectrum() {     // Spectrum display
  int d;
  static int peak[128];    // past peak value
 
  for (int xi = 1; xi < 128; xi++) {       // Display spectrum (skip 0)
    d = barLength(vReal[xi]);
    u8g2.drawVLine(xi + PX2, PY2 - d, d);         // spectrum
    u8g2.drawVLine(xi + PX2, PY2 - peak[xi], 1);  // peak
    if (peak[xi] < d) {   // if the latest value is greater than or equal to the peak value
      peak[xi] = d;       // Update peak value
    }
    if (peak[xi] > 0) {
      peak[xi] --; // Decay the peak value
    }
  }
}

int barLength(double d)
{
  float fy;
  int y;
  fy = 14.0 * (log10(d) + 1.5); // 14 pixels at 10x (20dB)
  y = fy;
  y = constrain(y, 0, 56);
  return y;
}

void showOthers()
{
  //u8g2.drawVLine(PX2, 0, 64);         // screen origin line (vertical axis)
  u8g2.drawHLine(0, PY2, 128);          // Spectrum bottom line
 
  // frequency scale (horizontal axis)
  for (int xp = PX2; xp < 127; xp += 5) { // 1kHz interval scale
    u8g2.drawVLine(xp, PY2 + 1, 1);
  }
  u8g2.drawVLine(PX2 + 25, PY2 + 1, 2);   // 5k ticks
  u8g2.drawVLine(PX2 + 50, PY2 + 1, 2);   // 10k ticks
 
  u8g2.setFont(u8g2_font_micro_tr);       // Small font (3x5),
  u8g2.setCursor(0, 58); u8g2.print("0"); // R side frequency display
  u8g2.setCursor(62, 58); u8g2.print("1k");
  u8g2.setCursor(120, 58); u8g2.print("2k");
 
  // Spectrum level scale (vertical axis)
  for (int y = PY2 - 7; y > 16; y -= 14) { // dB scale (horizontal dotted line)
    for (int x = 0; x < 108; x += 5) {
      u8g2.drawHLine(x, y, 2);
    }
  }
  u8g2.setFont(u8g2_font_6x10_tf); // larger font
  u8g2.setCursor(110, 17); u8g2.print("0dB"); // spectral sensitivity
  u8g2.setCursor(110, 30); u8g2.print("-20"); //
  u8g2.setCursor(110, 45); u8g2.print("-40"); //
 
  // LR display
  //u8g2.setFont(u8g2_font_crox1cb_tf); // With a slightly gorgeous font
  //u8g2.setCursor(0, 3); u8g2.print("R"); //
}

 void initMicrophone() 
{
  Serial.println("Setup I2S Microphone...");

  delay(1000);
  i2s_install();
  i2s_setpin();
  i2s_start(I2S_PORT);
  delay(500);
}

void displayAll()
{
  u8g2.clearBuffer();   // Screen buffer clear (22us)
  showWaveform();       // Waveform display (6ms)
  showSpectrum();       // Spectrum display (9.4ms)
  showOthers();         // Show other gridlines (1.6ms)
  u8g2.sendBuffer();    // (30ms)
  delay(1);             // Magic against write failure
}

void setup()
{

 // Wire.setClock(400000);     // this has no effect
  Serial. begin(115200);

  initMicrophone();

  initDisplay();

  delay(1000);
}

void loop()
{
  if (getWave() != ESP_OK)
  {
    Serial.println("Error: i2s_read() failed");
    displayError("i2s_read() failed");
    delay(100);
    return;
  }
  performFFT();
 
  displayAll(); 
} 