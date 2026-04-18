#define RELAY_PIN 8

void setup() {
  pinMode(RELAY_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, HIGH); // Most relay modules are active LOW; HIGH = off
}

void loop() {
  digitalWrite(RELAY_PIN, LOW);  // Turn relay ON
  delay(2000);
  digitalWrite(RELAY_PIN, HIGH); // Turn relay OFF
  delay(2000);
}
