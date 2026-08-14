// use `AccelStepper` lib by Mike McCauley
#include <AccelStepper.h>

// ULN2003 + 28BYJ-48 — IN1..IN4
AccelStepper stepper(AccelStepper::HALF4WIRE, 8, 10, 9, 11);

void setup() {
  Serial.begin(9600);
  stepper.setMaxSpeed(500);
  stepper.setAcceleration(100);
  Serial.println("ULN2003 Stepper Driver Ready");
}

void loop() {
  stepper.moveTo(2048);  // ~1 rev for 28BYJ-48 half-step
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
