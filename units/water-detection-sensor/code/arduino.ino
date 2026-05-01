#define WATER_ANALOG_PIN A0

void setup() {
  Serial.begin(9600);
  Serial.println("HW-038 Water Sensor Ready");
}

void loop() {
  delay(500);
  
  int waterLevel = analogRead(WATER_ANALOG_PIN);
  
  Serial.print("Water Level: ");
  Serial.println(waterLevel);
  
  // Simple threshold
  if (waterLevel > 500) {
    Serial.println("Water detected!");
  }
}