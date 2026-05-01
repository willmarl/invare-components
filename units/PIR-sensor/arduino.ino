#define PIR_PIN 7

int lastMotionState = LOW;
unsigned long lastMotionTime = 0;
const unsigned long DEBOUNCE_DELAY = 500;  // 500ms debounce

void setup() {
  Serial.begin(9600);
  pinMode(PIR_PIN, INPUT);
  
  Serial.println("HC-SR501 PIR Sensor");
  delay(30000);
  Serial.println("Ready!");
}

void loop() {
  delay(50);
  
  int motionState = digitalRead(PIR_PIN);
  
  if (motionState != lastMotionState) {
    if (millis() - lastMotionTime > DEBOUNCE_DELAY) {
      if (motionState == HIGH) {
        Serial.println(">> MOTION DETECTED");
      } else {
        Serial.println(">> Motion stopped");
      }
      lastMotionState = motionState;
      lastMotionTime = millis();
    }
  }
}