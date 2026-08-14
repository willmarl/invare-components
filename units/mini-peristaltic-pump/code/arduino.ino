// Peristaltic pump via MOSFET/H-bridge — reverse polarity to reverse flow
#define PUMP_PIN 8

void setup() {
  Serial.begin(9600);
  pinMode(PUMP_PIN, OUTPUT);
  digitalWrite(PUMP_PIN, LOW);
  Serial.println("Mini Peristaltic Pump Ready");
}

void loop() {
  digitalWrite(PUMP_PIN, HIGH);
  Serial.println("Dose ON");
  delay(1500);

  digitalWrite(PUMP_PIN, LOW);
  Serial.println("Dose OFF");
  delay(3000);
}
