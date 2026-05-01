const int potPin = A4;  // Potentiometer connected to A0

void setup() {
  Serial.begin(9600);  // Start serial communication
}

void loop() {
  int potValue = analogRead(potPin);  // Read analog value (0-1023)
  float voltage = (potValue / 1023.0) * 5.0;  // Convert to voltage (0-5V)
  
  Serial.println("Raw: " + String(potValue) + " | Voltage: " + String(voltage) + " V");
  
  delay(100);  // Wait 100ms before next read
}