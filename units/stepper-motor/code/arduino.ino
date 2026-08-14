// use `AccelStepper` lib by Mike McCauley
// NEMA 17 with step/dir driver (A4988 / TMC2208 / etc.)
#include <AccelStepper.h>

#define STEP_PIN 3
#define DIR_PIN 2
#define EN_PIN 8

AccelStepper stepper(AccelStepper::DRIVER, STEP_PIN, DIR_PIN);

void setup() {
  Serial.begin(9600);
  pinMode(EN_PIN, OUTPUT);
  digitalWrite(EN_PIN, LOW);

  stepper.setMaxSpeed(1000);
  stepper.setAcceleration(500);
  Serial.println("NEMA 17 Stepper Ready");
}

void loop() {
  stepper.moveTo(200);  // 1 full rev at 1.8° full-step (adjust for microstepping)
  while (stepper.distanceToGo() != 0) {
    stepper.run();
  }
  delay(500);

  stepper.moveTo(0);
  while (stepper.distanceToGo() != 0) {
    stepper.run();
  }
  delay(500);
}
