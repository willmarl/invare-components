// Water pump via MOSFET/relay — do not run dry
#define PUMP_PIN 8

void setup() {
  Serial.begin(9600);
  pinMode(PUMP_PIN, OUTPUT);
  digitalWrite(PUMP_PIN, LOW);
  Serial.println("Water Pump Ready");
}

void loop() {
  digitalWrite(PUMP_PIN, HIGH);
  Serial.println("Pump ON");
  delay(3000);

  digitalWrite(PUMP_PIN, LOW);
  Serial.println("Pump OFF");
  delay(3000);
}
