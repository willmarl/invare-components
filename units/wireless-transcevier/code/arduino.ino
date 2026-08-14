// use `RF24` lib by TMRh20
#include <SPI.h>
#include <RF24.h>

#define CE_PIN 9
#define CSN_PIN 10

RF24 radio(CE_PIN, CSN_PIN);
const byte address[6] = "00001";

void setup() {
  Serial.begin(9600);

  if (!radio.begin()) {
    Serial.println("NRF24L01 not responding — check 3.3V power + wiring");
    while (1);
  }

  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_LOW);
  radio.stopListening();

  Serial.println("NRF24L01 TX Ready");
}

void loop() {
  const char text[] = "hello";
  bool ok = radio.write(&text, sizeof(text));

  Serial.println(ok ? "Sent" : "Send failed");
  delay(1000);
}

////////////////////////////
// RX sketch (flash to other board)
////////////////////////////
// RF24 radio(9, 10);
// const byte address[6] = "00001";
// void setup() {
//   Serial.begin(9600);
//   radio.begin();
//   radio.openReadingPipe(0, address);
//   radio.setPALevel(RF24_PA_LOW);
//   radio.startListening();
// }
// void loop() {
//   if (radio.available()) {
//     char text[32] = "";
//     radio.read(&text, sizeof(text));
//     Serial.println(text);
//   }
// }
