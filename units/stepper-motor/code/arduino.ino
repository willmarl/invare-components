// use `AccelStepper` lib by Mike McCauley
#include <AccelStepper.h>

#define STEPS_PER_REVOLUTION 2048

AccelStepper stepper(AccelStepper::HALF4WIRE, 8, 10, 9, 11);

void setup() {
  Serial.begin(9600);
  stepper.setMaxSpeed(1000);
  stepper.setAcceleration(500);
  
  Serial.println("Stepper Ready");
}

void loop() {
  // Move 2048 steps
  stepper.moveTo(2048);
  while (stepper.distanceToGo() != 0) {
    stepper.run();
  }
  
  delay(1000);
  
  // Move back to 0
  stepper.moveTo(0);
  while (stepper.distanceToGo() != 0) {
    stepper.run();
  }
  
  delay(1000);
}