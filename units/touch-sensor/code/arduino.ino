#define TOUCH_PIN 7

void setup() {
  Serial.begin(9600);
  pinMode(TOUCH_PIN, INPUT);
  Serial.println("TTP223 Touch Sensor Ready");
}

void loop() {
  delay(50);

  if (digitalRead(TOUCH_PIN) == HIGH) {
    Serial.println("Touched!");
  }
}
