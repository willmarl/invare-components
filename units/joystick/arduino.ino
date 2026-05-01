const int joystickX = A0;
const int joystickY = A1;
const int joystickSW = 5;

void setup() {
  Serial.begin(9600);
  pinMode(joystickSW, INPUT_PULLUP);
}

void loop() {
  int xValue = analogRead(joystickX);  // 0-1023
  int yValue = analogRead(joystickY);  // 0-1023
  
  Serial.print("X: ");
  Serial.print(xValue);
  Serial.print(" Y: ");
  Serial.println(yValue);
  
  // Button press
  if (digitalRead(joystickSW) == LOW) {
    delay(20);
    if (digitalRead(joystickSW) == LOW) {
      Serial.println("Joystick Clicked!");
      while (digitalRead(joystickSW) == LOW);
      delay(20);
    }
  }
  
  delay(100);
}