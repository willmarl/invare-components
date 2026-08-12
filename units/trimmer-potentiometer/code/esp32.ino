const int potPin = 36;

void setup() {
  Serial.begin(115200);  // ESP32 default baud rate is 115200
}

void loop() {
  int potValue = analogRead(potPin);  // Read analog value (0-4095 on ESP32)
  float voltage = (potValue / 4095.0) * 3.3;  // Convert to voltage (0-3.3V for ESP32)
  
  Serial.println("Raw: " + String(potValue) + " | Voltage: " + String(voltage) + " V");
  
  delay(100);  // Wait 100ms before next read
}