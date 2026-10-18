// use `AccelStepper` lib by Mike McCauley
// CNC Shield V3 on an Uno — X axis. Seat a step/dir driver (A4988 / DRV8825 / TMC) in the X socket.
#include <AccelStepper.h>

#define STEP_PIN 2  // X.STEP
#define DIR_PIN 5   // X.DIR
#define EN_PIN 8    // shared enable, active low

AccelStepper stepper(AccelStepper::DRIVER, STEP_PIN, DIR_PIN);

void setup() {
  Serial.begin(9600);
  pinMode(EN_PIN, OUTPUT);
  digitalWrite(EN_PIN, LOW);

  stepper.setMaxSpeed(1000);
  stepper.setAcceleration(500);
  Serial.println("CNC Shield Ready");
}

void loop() {
  stepper.move(200);
  while (stepper.distanceToGo() != 0) {
    stepper.run();
  }
  delay(500);

  stepper.move(-200);
  while (stepper.distanceToGo() != 0) {
    stepper.run();
  }
  delay(500);
}
