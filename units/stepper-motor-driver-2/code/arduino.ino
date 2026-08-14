// use `AccelStepper` lib by Mike McCauley
// TMC2208 in step/dir (standalone) mode — quieter than A4988 with StealthChop default
#include <AccelStepper.h>

#define STEP_PIN 3
#define DIR_PIN 2
#define EN_PIN 8

AccelStepper stepper(AccelStepper::DRIVER, STEP_PIN, DIR_PIN);

void setup() {
  Serial.begin(9600);
  pinMode(EN_PIN, OUTPUT);
  digitalWrite(EN_PIN, LOW);  // enable (active low on most carriers)

  stepper.setMaxSpeed(1000);
  stepper.setAcceleration(500);
  Serial.println("TMC2208 Ready");
}

void loop() {
  stepper.move(1600);  // 200 steps * 8 microsteps example
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
