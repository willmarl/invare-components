// use `AccelStepper` lib by Mike McCauley
#include <AccelStepper.h>

#define STEP_PIN 3
#define DIR_PIN 2
#define EN_PIN 8

AccelStepper stepper(AccelStepper::DRIVER, STEP_PIN, DIR_PIN);

void setup() {
  Serial.begin(9600);
  pinMode(EN_PIN, OUTPUT);
  digitalWrite(EN_PIN, LOW);  // enable (active low)

  // Set Vref pot BEFORE powering the motor — too high cooks the driver
  stepper.setMaxSpeed(800);
  stepper.setAcceleration(400);
  Serial.println("A4988 Ready");
}

void loop() {
  stepper.move(1600);
  while (stepper.distanceToGo() != 0) {
    stepper.run();
  }
  delay(500);

  stepper.move(-1600);
  while (stepper.distanceToGo() != 0) {
    stepper.run();
  }
  delay(500);
}
