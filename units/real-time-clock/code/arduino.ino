// use `RTClib` lib by adafruit
#include <Wire.h>
#include <RTClib.h>

RTC_DS1307 rtc;

void setup() {
  Serial.begin(9600);
  
  if (!rtc.begin()) {
    Serial.println("RTC not found!");
    while (1);
  }
  
  // Set time once (then comment out)
  // rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  
  Serial.println("DS1307 Ready");
}

void loop() {
  DateTime now = rtc.now();
  
  Serial.print(now.year(), DEC);
  Serial.print('-');
  if (now.month() < 10) Serial.print('0');
  Serial.print(now.month(), DEC);
  Serial.print('-');
  if (now.day() < 10) Serial.print('0');
  Serial.print(now.day(), DEC);
  
  Serial.print(" ");
  
  if (now.hour() < 10) Serial.print('0');
  Serial.print(now.hour(), DEC);
  Serial.print(':');
  if (now.minute() < 10) Serial.print('0');
  Serial.print(now.minute(), DEC);
  Serial.print(':');
  if (now.second() < 10) Serial.print('0');
  Serial.println(now.second(), DEC);
  
  delay(1000);
}