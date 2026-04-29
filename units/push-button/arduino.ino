const int LED_PIN = 2;
const int BUTTON_PIN = 3;

void setup() {
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT_PULLUP);  // Enable internal pull-up
}

void loop() {
  // INPUT_PULLUP inverts logic: LOW means pressed
  int buttonState = digitalRead(BUTTON_PIN);
  
  if (buttonState == LOW) {  // Button pressed
    digitalWrite(LED_PIN, HIGH);
  } else {
    digitalWrite(LED_PIN, LOW);
  }
}