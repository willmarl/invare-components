#define RED_PIN 9
#define GREEN_PIN 10
#define BLUE_PIN 11

// Common cathode: PWM HIGH = brighter. Common anode: invert values.
void setup() {
  Serial.begin(9600);
  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);
  Serial.println("5mm RGB LED Ready");
}

void loop() {
  setColor(255, 0, 0);
  delay(500);
  setColor(0, 255, 0);
  delay(500);
  setColor(0, 0, 255);
  delay(500);
  setColor(255, 255, 255);
  delay(500);
  setColor(0, 0, 0);
  delay(500);
}

void setColor(int r, int g, int b) {
  analogWrite(RED_PIN, r);
  analogWrite(GREEN_PIN, g);
  analogWrite(BLUE_PIN, b);
}
