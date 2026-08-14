// TT motor via H-bridge (L9110S / L293D style pins)
#define IN1 8
#define IN2 9
#define EN 10  // PWM

void setup() {
  Serial.begin(9600);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(EN, OUTPUT);
  Serial.println("TT Motor Ready");
}

void loop() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  analogWrite(EN, 200);
  delay(2000);

  analogWrite(EN, 0);
  delay(500);

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  analogWrite(EN, 200);
  delay(2000);

  analogWrite(EN, 0);
  delay(1000);
}
