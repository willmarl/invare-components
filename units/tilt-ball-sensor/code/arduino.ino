#define TILT_PIN 6

void setup() {
  Serial.begin(9600);
  pinMode(TILT_PIN, INPUT_PULLUP);
  
  Serial.println("Tilt Sensor Ready");
}

void loop() {
  delay(100);
  
  int tiltState = digitalRead(TILT_PIN);
  
  if (tiltState == LOW) {
    Serial.println("Tilted!");
  } else {
    Serial.println("Level");
  }
}