// Coin vibration motor — transistor + flyback diode recommended
#define VIBE_PIN 8

void setup() {
  Serial.begin(9600);
  pinMode(VIBE_PIN, OUTPUT);
  digitalWrite(VIBE_PIN, LOW);
  Serial.println("Mini Vibration Motor Ready");
}

void loop() {
  digitalWrite(VIBE_PIN, HIGH);
  delay(300);
  digitalWrite(VIBE_PIN, LOW);
  delay(1500);
}
