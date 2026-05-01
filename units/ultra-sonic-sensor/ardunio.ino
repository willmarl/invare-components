// use `NewPing` lib by Tim Eckel
#include <NewPing.h>

#define TRIGGER_PIN 12
#define ECHO_PIN 11
#define MAX_DISTANCE 200  // Maximum distance (cm)

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

void setup() {
  Serial.begin(9600);
  Serial.println("HC-SR04 Ultrasonic Sensor Ready");
}

void loop() {
  delay(50);
  
  int distance = sonar.ping_cm();
  
  if (distance == 0) {
    Serial.println("Out of range");
  } else {
    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.println(" cm");
  }
}