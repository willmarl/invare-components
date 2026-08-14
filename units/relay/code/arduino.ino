#define RELAY_PIN 7

void setup() {
  Serial.begin(9600);
  pinMode(RELAY_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, LOW);
  Serial.println("Relay Ready");
}

void loop() {
  digitalWrite(RELAY_PIN, HIGH);
  Serial.println("ON");
  delay(2000);

  digitalWrite(RELAY_PIN, LOW);
  Serial.println("OFF");
  delay(2000);
}
