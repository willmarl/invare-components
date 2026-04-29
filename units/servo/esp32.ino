// requires `esp32servo` library installed

#include <ESP32Servo.h>

Servo myServo;
int servoPin = 15;  // GPIO 16

void setup() {
  Serial.begin(115200);
  myServo.attach(servoPin);
}

void loop() {
  myServo.write(0);
  delay(1000);
  
  myServo.write(90);
  delay(1000);
  
  myServo.write(180);
  delay(1000);
}