#define MOTOR_IN1 8
#define MOTOR_IN2 9
#define MOTOR_EN 10  // PWM pin (3, 5, 6, 9, 10, 11 on Nano)

void setup() {
  Serial.begin(9600);
  pinMode(MOTOR_IN1, OUTPUT);
  pinMode(MOTOR_IN2, OUTPUT);
  pinMode(MOTOR_EN, OUTPUT);
  
  Serial.println("DC Motor Control Ready");
}

void loop() {
  // Full speed forward
  motorForward(255);
  delay(2000);
  
  // Half speed forward
  motorForward(128);
  delay(2000);
  
  // Stop
  motorStop();
  delay(1000);
  
  // Full speed reverse
  motorBackward(255);
  delay(2000);
  
  // Stop
  motorStop();
  delay(1000);
}

void motorForward(int speed) {
  digitalWrite(MOTOR_IN1, HIGH);
  digitalWrite(MOTOR_IN2, LOW);
  analogWrite(MOTOR_EN, speed);  // 0-255
}

void motorBackward(int speed) {
  digitalWrite(MOTOR_IN1, LOW);
  digitalWrite(MOTOR_IN2, HIGH);
  analogWrite(MOTOR_EN, speed);  // 0-255
}

void motorStop() {
  digitalWrite(MOTOR_IN1, LOW);
  digitalWrite(MOTOR_IN2, LOW);
  analogWrite(MOTOR_EN, 0);
}