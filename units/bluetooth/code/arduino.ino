#include <SoftwareSerial.h>

SoftwareSerial bt(10, 11);  // RX, TX — HC-05 TX->10, RX<-11 (voltage divider on RX if 5V MCU)

void setup() {
  Serial.begin(9600);
  bt.begin(9600);  // default AT/baud often 9600 (some HC-05 AT mode is 38400)
  Serial.println("HC-05/HC-06 Ready — type in Serial Monitor");
}

void loop() {
  if (Serial.available()) {
    bt.write(Serial.read());
  }
  if (bt.available()) {
    Serial.write(bt.read());
  }
}
