#include <Servo.h>

Servo myServo;
int servoPin = 9;  // PWM pin

void setup() {
  Serial.begin(9600);
  myServo.attach(servoPin);  // Attach servo to pin 9
}

void loop() {
  // Move to 0 degrees
  myServo.write(0);
  delay(1000);
  
  // Move to 90 degrees (middle)
  myServo.write(90);
  delay(1000);
  
  // Move to 180 degrees
  myServo.write(180);
  delay(1000);
}