// use `HX711 Arduino Library` lib by Bogdan Necula
#include <HX711.h>

#define DOUT_PIN 3
#define SCK_PIN 2

HX711 scale;

void setup() {
  Serial.begin(9600);
  scale.begin(DOUT_PIN, SCK_PIN);

  Serial.println("HX711 Ready — remove weight then taring...");
  delay(1000);
  scale.tare();

  // Calibrate: put a known weight on, then set_scale(raw / known_grams)
  // scale.set_scale(2280.f);  // example — measure yours
  Serial.println("Tare done. Set scale factor after calibration.");
}

void loop() {
  if (scale.is_ready()) {
    long raw = scale.read();
    float units = scale.get_units(5);

    Serial.print("Raw: ");
    Serial.print(raw);
    Serial.print(" | Units: ");
    Serial.println(units);
  } else {
    Serial.println("HX711 not ready");
  }

  delay(500);
}
