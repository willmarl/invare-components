// use `Adafruit PWM Servo Driver Library` lib by adafruit
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

#define SERVO_MIN 150
#define SERVO_MAX 600

void setup() {
  Serial.begin(9600);
  pwm.begin();
  pwm.setPWMFreq(60);
  
  Serial.println("Dual Servo Ready");
}

void loop() {
  // Servo 1: Stepped motion
  pwm.setPWM(0, 0, map(0, 0, 180, SERVO_MIN, SERVO_MAX));
  delay(1000);
  
  pwm.setPWM(0, 0, map(90, 0, 180, SERVO_MIN, SERVO_MAX));
  delay(1000);
  
  pwm.setPWM(0, 0, map(180, 0, 180, SERVO_MIN, SERVO_MAX));
  delay(1000);
  
  // Servo 2: Smooth motion
  smoothServo(1, 0, 180, 1000);
  delay(500);
  
  smoothServo(1, 180, 0, 1000);
  delay(500);
}

void smoothServo(uint8_t channel, int startAngle, int endAngle, int duration) {
  int steps = 50;
  int delayTime = duration / steps;
  
  for (int i = 0; i <= steps; i++) {
    int angle = startAngle + ((endAngle - startAngle) * i / steps);
    int pwmValue = map(angle, 0, 180, SERVO_MIN, SERVO_MAX);
    pwm.setPWM(channel, 0, pwmValue);
    delay(delayTime);
  }
}