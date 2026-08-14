#include <Servo.h>

Servo myServo;
int servoPin = 9;

void setup() {
  Serial.begin(9600);
  myServo.attach(servoPin);
  Serial.println("DS3218MG Digital Servo Ready");
}

void loop() {
  myServo.write(0);
  delay(1000);

  myServo.write(90);
  delay(1000);

  myServo.write(180);
  delay(1000);
}
