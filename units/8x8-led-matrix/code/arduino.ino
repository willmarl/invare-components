// use LedControl lib by Eberhard fahle
#include <LedControl.h>

// MAX7219 pins: DIN (MOSI), CLK (SCK), CS (SS)
#define DIN_PIN 11
#define CLK_PIN 13
#define CS_PIN 10

LedControl lc = LedControl(DIN_PIN, CLK_PIN, CS_PIN, 1);  // 1 = number of MAX7219 chips

void setup() {
  Serial.begin(9600);
  
  lc.shutdown(0, false);      // Wake up
  lc.setIntensity(0, 8);      // Brightness (0-15)
  lc.clearDisplay(0);         // Clear display
  
  Serial.println("MAX7219 8x8 Matrix Ready");
}

void loop() {
  // Display a pattern
  byte pattern[8] = {
    0b00111100,
    0b01000010,
    0b10000001,
    0b10000001,
    0b10000001,
    0b10000001,
    0b01000010,
    0b00111100
  };
  
  for (int row = 0; row < 8; row++) {
    lc.setRow(0, row, pattern[row]);
  }
  
  delay(500);
  lc.clearDisplay(0);
  delay(500);
}