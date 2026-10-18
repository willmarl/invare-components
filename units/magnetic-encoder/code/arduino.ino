// use `Adafruit AS5600 Library` lib by adafruit
#include <Adafruit_AS5600.h>
#include <Wire.h>

Adafruit_AS5600 encoder;

void setup() {
  Serial.begin(9600);
  Wire.begin();
  if (!encoder.begin()) {
    Serial.println("AS5600 not found");
    while (1);
  }
  Serial.println("AS5600 Ready");
}

void loop() {
  if (!encoder.isMagnetDetected()) {
    Serial.println("no magnet");
  } else {
    uint16_t raw = encoder.getAngle();  // 0–4095
    float degrees = raw * 360.0 / 4096.0;
    Serial.print(degrees);
    Serial.println(" deg");
  }
  delay(200);
}
