// Micro 716 DC motor — drive with transistor/MOSFET or H-bridge, not raw GPIO for stall
#define MOTOR_PIN 9  // PWM via transistor

void setup() {
  Serial.begin(9600);
  pinMode(MOTOR_PIN, OUTPUT);
  Serial.println("Micro DC Motor Ready");
}

void loop() {
  analogWrite(MOTOR_PIN, 200);
  delay(2000);

  analogWrite(MOTOR_PIN, 100);
  delay(2000);

  analogWrite(MOTOR_PIN, 0);
  delay(1000);
}
