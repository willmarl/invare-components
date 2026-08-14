const int potPin = A0;

void setup() {
  Serial.begin(9600);
  Serial.println("WH148 Rotary Potentiometer Ready");
}

void loop() {
  int potValue = analogRead(potPin);
  float voltage = (potValue / 1023.0) * 5.0;

  Serial.println("Raw: " + String(potValue) + " | Voltage: " + String(voltage) + " V");
  delay(100);
}
