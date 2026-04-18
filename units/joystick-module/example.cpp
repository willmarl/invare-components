#define VRX_PIN  A0
#define VRY_PIN  A1
#define SW_PIN   2   // Push button (active LOW)

void setup() {
  Serial.begin(9600);
  pinMode(SW_PIN, INPUT_PULLUP);
}

void loop() {
  int x = analogRead(VRX_PIN); // 0–1023, center ≈ 512
  int y = analogRead(VRY_PIN);
  bool pressed = digitalRead(SW_PIN) == LOW;

  Serial.print("X: ");
  Serial.print(x);
  Serial.print("  Y: ");
  Serial.print(y);
  Serial.print("  Button: ");
  Serial.println(pressed ? "PRESSED" : "released");

  delay(100);
}
