#define LIMIT_PIN 7

void setup() {
  Serial.begin(9600);
  pinMode(LIMIT_PIN, INPUT_PULLUP);
  Serial.println("KW12 Limit Switch Ready");
}

void loop() {
  delay(50);

  if (digitalRead(LIMIT_PIN) == LOW) {
    Serial.println("Triggered!");
  }
}
