#define LDR_PIN A0

void setup() {
  Serial.begin(9600);
  Serial.println("Photoresistor Ready");
}

void loop() {
  delay(500);
  
  int lightLevel = analogRead(LDR_PIN);
  
  Serial.print("Light Level: ");
  Serial.println(lightLevel);
}