#define LASER_PIN 8

void setup() {
  Serial.begin(9600);
  pinMode(LASER_PIN, OUTPUT);
  digitalWrite(LASER_PIN, LOW);
  Serial.println("650nm Laser Ready — never point at eyes");
}

void loop() {
  digitalWrite(LASER_PIN, HIGH);
  delay(1000);
  digitalWrite(LASER_PIN, LOW);
  delay(1000);
}
