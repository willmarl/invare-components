#define BUTTON_PIN 2
#define LED_PIN    13

void setup() {
  pinMode(BUTTON_PIN, INPUT_PULLUP); // Use internal pull-up; button connects pin to GND
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  // INPUT_PULLUP: LOW when pressed, HIGH when released
  if (digitalRead(BUTTON_PIN) == LOW) {
    digitalWrite(LED_PIN, HIGH);
  } else {
    digitalWrite(LED_PIN, LOW);
  }
}
