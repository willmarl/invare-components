#define BTN1 2
#define BTN2 3
#define BTN3 4
#define BTN4 5

void setup() {
  Serial.begin(9600);
  pinMode(BTN1, INPUT_PULLUP);
  pinMode(BTN2, INPUT_PULLUP);
  pinMode(BTN3, INPUT_PULLUP);
  pinMode(BTN4, INPUT_PULLUP);
  Serial.println("1x4 Button Keypad Ready");
}

void loop() {
  if (digitalRead(BTN1) == LOW) Serial.println("1");
  if (digitalRead(BTN2) == LOW) Serial.println("2");
  if (digitalRead(BTN3) == LOW) Serial.println("3");
  if (digitalRead(BTN4) == LOW) Serial.println("4");
  delay(50);
}
