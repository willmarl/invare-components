#define POT_PIN A0

void setup() {
  Serial.begin(9600);
}

void loop() {
  int raw = analogRead(POT_PIN);          // 0–1023
  float voltage = raw * (5.0 / 1023.0);  // Convert to volts
  int mapped = map(raw, 0, 1023, 0, 255); // Map to 0–255 range

  Serial.print("Raw: ");
  Serial.print(raw);
  Serial.print("  Voltage: ");
  Serial.print(voltage, 2);
  Serial.print("V  Mapped: ");
  Serial.println(mapped);

  delay(100);
}
