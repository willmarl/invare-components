// Motor A pins
#define ENA 5  // PWM speed control
#define IN1 6
#define IN2 7

void setup() {
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
}

void setMotorA(int speed) {
  // speed: -255 to 255 (negative = reverse)
  if (speed >= 0) {
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
  } else {
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    speed = -speed;
  }
  analogWrite(ENA, constrain(speed, 0, 255));
}

void loop() {
  setMotorA(200);   // Forward at ~78% speed
  delay(2000);
  setMotorA(0);     // Stop
  delay(500);
  setMotorA(-200);  // Reverse
  delay(2000);
  setMotorA(0);
  delay(500);
}
