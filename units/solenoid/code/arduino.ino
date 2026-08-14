// Drive via transistor/MOSFET + flyback diode — not directly from GPIO for long on-times
#define SOLENOID_PIN 8

void setup() {
  Serial.begin(9600);
  pinMode(SOLENOID_PIN, OUTPUT);
  digitalWrite(SOLENOID_PIN, LOW);
  Serial.println("Solenoid Ready");
}

void loop() {
  digitalWrite(SOLENOID_PIN, HIGH);
  Serial.println("Pull");
  delay(300);  // short pulse — coils heat up if left on

  digitalWrite(SOLENOID_PIN, LOW);
  Serial.println("Release");
  delay(2000);
}
