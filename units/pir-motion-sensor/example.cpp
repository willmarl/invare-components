#define PIR_PIN   2
#define LED_PIN   13

void setup() {
  Serial.begin(9600);
  pinMode(PIR_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
  delay(2000); // Allow PIR to calibrate on startup
  Serial.println("PIR ready");
}

void loop() {
  if (digitalRead(PIR_PIN) == HIGH) {
    digitalWrite(LED_PIN, HIGH);
    Serial.println("Motion detected!");
  } else {
    digitalWrite(LED_PIN, LOW);
  }
  delay(100);
}
