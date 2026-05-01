// use TM1637 lib by avishay orpaz
#include <TM1637Display.h>

#define CLK 11
#define DIO 10

TM1637Display display(CLK, DIO);

void setup() {
  Serial.begin(9600);
  display.setBrightness(7);
  
  Serial.println("TM1637 Display Ready");
}

void loop() {
  // Display time-like format with ":"
  display.showNumberDecEx(1234, 0b01000000, false);
  // 0b01000000 = turn on the colon (middle segment)
  delay(1000);
  
  display.showNumberDec(5678);
  delay(1000);
  
  // Display time format (HH:MM style)
  display.showNumberDecEx(1530, 0b01000000, false);  // 15:30
  delay(1000);
}