// use `DFRobotDFPlayerMini` lib by DFRobot
#include <SoftwareSerial.h>
#include <DFRobotDFPlayerMini.h>

SoftwareSerial softSerial(10, 11);  // RX, TX — module TX->10, RX<-11 (1k series on RX if 5V MCU)
DFRobotDFPlayerMini player;

void setup() {
  Serial.begin(9600);
  softSerial.begin(9600);

  if (!player.begin(softSerial)) {
    Serial.println("DFPlayer not found — check wiring / SD card");
    while (1);
  }

  player.volume(20);  // 0-30
  Serial.println("MP3-TF-16P Ready");
  player.play(1);     // play 0001.mp3 in root or /mp3/
}

void loop() {
  delay(5000);
  player.next();
}
