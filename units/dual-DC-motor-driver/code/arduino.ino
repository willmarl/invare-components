// L9110S dual DC motor driver — IA/IB style pins (PWM ok on speed pin)
#define A_IA 5   // PWM
#define A_IB 6
#define B_IA 9   // PWM
#define B_IB 10

void setup() {
  Serial.begin(9600);
  pinMode(A_IA, OUTPUT);
  pinMode(A_IB, OUTPUT);
  pinMode(B_IA, OUTPUT);
  pinMode(B_IB, OUTPUT);
  Serial.println("L9110S Dual Motor Driver Ready");
}

void loop() {
  motorA(200, true);
  motorB(200, true);
  delay(2000);

  motorA(0, true);
  motorB(0, true);
  delay(500);

  motorA(200, false);
  motorB(200, false);
  delay(2000);

  motorA(0, true);
  motorB(0, true);
  delay(1000);
}

void motorA(int speed, bool forward) {
  if (forward) {
    analogWrite(A_IA, speed);
    digitalWrite(A_IB, LOW);
  } else {
    digitalWrite(A_IA, LOW);
    analogWrite(A_IB, speed);
  }
}

void motorB(int speed, bool forward) {
  if (forward) {
    analogWrite(B_IA, speed);
    digitalWrite(B_IB, LOW);
  } else {
    digitalWrite(B_IA, LOW);
    analogWrite(B_IB, speed);
  }
}
