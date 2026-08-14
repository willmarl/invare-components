// IRLZ44N N-channel MOSFET as low-side switch — load between +V and drain, source to GND
#define GATE_PIN 9  // PWM ok for speed control

void setup() {
  Serial.begin(9600);
  pinMode(GATE_PIN, OUTPUT);
  digitalWrite(GATE_PIN, LOW);
  Serial.println("IRLZ44N MOSFET Ready");
}

void loop() {
  analogWrite(GATE_PIN, 255);
  delay(1000);

  analogWrite(GATE_PIN, 128);
  delay(1000);

  analogWrite(GATE_PIN, 0);
  delay(1000);
}
