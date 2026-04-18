#define BUZZER_PIN 8

// Plays a simple melody using tone()
int notes[] = {262, 294, 330, 349, 392, 440, 494, 523}; // C4 to C5
int durations[] = {200, 200, 200, 200, 200, 200, 200, 400};

void setup() {
  pinMode(BUZZER_PIN, OUTPUT);
}

void loop() {
  for (int i = 0; i < 8; i++) {
    tone(BUZZER_PIN, notes[i], durations[i]);
    delay(durations[i] + 50);
    noTone(BUZZER_PIN);
  }
  delay(1000);
}
