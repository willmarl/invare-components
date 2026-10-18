# Examples

## desc.md

```markdown
TMC2208 stepper driver — quieter than A4988 when StealthChop is on. Drop-in step/dir pinout. Set current with the Vref pot (or UART). Needs a heatsink if you push much current. Logic and motor supplies are separate.

- Logic Voltage : 3.3V – 5V
- Load Voltage : 4.75V – 36V (12V / 24V typical)
- Current : ~1.2A RMS typical on modules, ~2A peak with cooling
- Microstepping : up to 1/256 (interpolated)

> AI created desc
```

## info.json

```json
{
  "name": "Stepper Motor Driver",
  "model": "TMC2208",
  "exampleIdeas": [
    "Quiet stepper axis",
    "3D printer driver",
    "CNC motion"
  ],
  "tags": [
    "stepper",
    "driver",
    "motor",
    "tmc"
  ]
}
```

## code/arduino.ino

```cpp
// use `AccelStepper` lib by Mike McCauley
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
```
