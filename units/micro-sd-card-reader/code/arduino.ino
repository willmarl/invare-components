#include <SPI.h>
#include <SD.h>

#define CS_PIN 10

void setup() {
  Serial.begin(9600);

  if (!SD.begin(CS_PIN)) {
    Serial.println("SD init failed — check CS pin / card format (FAT32)");
    while (1);
  }

  Serial.println("MicroSD Ready");

  File file = SD.open("test.txt", FILE_WRITE);
  if (file) {
    file.println("hello sd");
    file.close();
    Serial.println("Wrote test.txt");
  } else {
    Serial.println("Write failed");
  }
}

void loop() {
  delay(2000);

  File file = SD.open("test.txt");
  if (file) {
    while (file.available()) {
      Serial.write(file.read());
    }
    file.close();
  }
}
