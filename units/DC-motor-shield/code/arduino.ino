// use `Adafruit Motor Shield library` lib by adafruit
#include <AFMotor.h>

AF_DCMotor motor1(1);  // M1
AF_DCMotor motor2(2);  // M2

void setup() {
  Serial.begin(9600);
  Serial.println("L293D Motor Shield Ready");

  motor1.setSpeed(200);  // 0-255
  motor2.setSpeed(200);
}

void loop() {
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  delay(2000);

  motor1.run(RELEASE);
  motor2.run(RELEASE);
  delay(500);

  motor1.run(BACKWARD);
  motor2.run(BACKWARD);
  delay(2000);

  motor1.run(RELEASE);
  motor2.run(RELEASE);
  delay(1000);
}
