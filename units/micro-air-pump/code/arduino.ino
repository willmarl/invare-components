// Micro air pump via MOSFET/transistor + flyback diode
#define PUMP_PIN 8

void setup() {
  Serial.begin(9600);
  pinMode(PUMP_PIN, OUTPUT);
  digitalWrite(PUMP_PIN, LOW);
  Serial.println("Micro Air Pump Ready");
}

void loop() {
  digitalWrite(PUMP_PIN, HIGH);
  Serial.println("Pump ON");
  delay(2000);

  digitalWrite(PUMP_PIN, LOW);
  Serial.println("Pump OFF");
  delay(2000);
}
