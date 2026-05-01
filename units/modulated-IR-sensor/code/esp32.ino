const int irReceiverPin = 2; // Pin for the IR receiver output

void setup() {
  pinMode(irReceiverPin, INPUT);
  Serial.begin(115200);
}

void loop() {
  int sensorValue = digitalRead(irReceiverPin);
  if (sensorValue == LOW) {
    Serial.println("Object Detected!");
  } else {
    Serial.println("Clear");
  }
  delay(100);
}