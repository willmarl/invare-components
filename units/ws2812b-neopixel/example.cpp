// Requires: Adafruit NeoPixel library
#include <Adafruit_NeoPixel.h>

#define LED_PIN   6
#define NUM_LEDS  8

Adafruit_NeoPixel strip(NUM_LEDS, LED_PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  strip.begin();
  strip.setBrightness(50); // 0–255
  strip.show();
}

void loop() {
  // Cycle through red, green, blue
  for (int i = 0; i < NUM_LEDS; i++) {
    strip.setPixelColor(i, strip.Color(255, 0, 0)); // Red
  }
  strip.show();
  delay(500);

  for (int i = 0; i < NUM_LEDS; i++) {
    strip.setPixelColor(i, strip.Color(0, 255, 0)); // Green
  }
  strip.show();
  delay(500);

  for (int i = 0; i < NUM_LEDS; i++) {
    strip.setPixelColor(i, strip.Color(0, 0, 255)); // Blue
  }
  strip.show();
  delay(500);
}
