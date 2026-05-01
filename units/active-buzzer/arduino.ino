#define BUZZER_PIN 9

void setup() {
  Serial.begin(9600);
  pinMode(BUZZER_PIN, OUTPUT);
  
  Serial.println("Active Buzzer Ready");
}

void buzz(int times, int duration) {
  for (int i = 0; i < times; i++) {
    digitalWrite(BUZZER_PIN, HIGH);
    delay(duration);
    digitalWrite(BUZZER_PIN, LOW);
    delay(duration);
  }
}

void loop() {
  buzz(3, 200);  // 3 short beeps
  delay(2000);
  
  buzz(1, 500);  // 1 long beep
  delay(2000);
}