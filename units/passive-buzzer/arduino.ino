#define BUZZER_PIN 9

void setup() {
  Serial.begin(9600);
  pinMode(BUZZER_PIN, OUTPUT);
  
  Serial.println("Passive Buzzer Ready");
}

void playTone(int frequency, int duration) {
  tone(BUZZER_PIN, frequency);
  delay(duration);
  noTone(BUZZER_PIN);
}

void loop() {
  playTone(1000, 200);  // 1000 Hz for 200ms
  delay(100);
  playTone(1500, 200);  // 1500 Hz for 200ms
  delay(100);
  playTone(2000, 200);  // 2000 Hz for 200ms
  delay(2000);
}