#define DATA_PIN 2
#define CLOCK_PIN 3
#define LATCH_PIN 4

void setup() {
  Serial.begin(9600);
  pinMode(DATA_PIN, OUTPUT);
  pinMode(CLOCK_PIN, OUTPUT);
  pinMode(LATCH_PIN, OUTPUT);
  Serial.println("74HC595 Shift Register Ready");
}

void loop() {
  for (int i = 0; i < 8; i++) {
    writeBits(1 << i);
    delay(150);
  }

  writeBits(0b11111111);
  delay(500);
  writeBits(0);
  delay(500);
}

void writeBits(byte value) {
  digitalWrite(LATCH_PIN, LOW);
  shiftOut(DATA_PIN, CLOCK_PIN, MSBFIRST, value);
  digitalWrite(LATCH_PIN, HIGH);
}
