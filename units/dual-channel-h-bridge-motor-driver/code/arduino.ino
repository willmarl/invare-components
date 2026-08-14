// L293D dual H-bridge — external motor supply on VCC2 / Vs
#define ENA 9   // PWM
#define IN1 8
#define IN2 7
#define ENB 10  // PWM
#define IN3 6
#define IN4 5

void setup() {
  Serial.begin(9600);
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  Serial.println("L293D Ready");
}

void loop() {
  motorA(200, true);
  motorB(200, true);
  delay(2000);

  stopAll();
  delay(500);

  motorA(200, false);
  motorB(200, false);
  delay(2000);

  stopAll();
  delay(1000);
}

void motorA(int speed, bool forward) {
  digitalWrite(IN1, forward ? HIGH : LOW);
  digitalWrite(IN2, forward ? LOW : HIGH);
  analogWrite(ENA, speed);
}

void motorB(int speed, bool forward) {
  digitalWrite(IN3, forward ? HIGH : LOW);
  digitalWrite(IN4, forward ? LOW : HIGH);
  analogWrite(ENB, speed);
}

void stopAll() {
  analogWrite(ENA, 0);
  analogWrite(ENB, 0);
}
