// use tcs3200 lib by Panjkrc
#include <tcs3200.h>

#define S0 2
#define S1 3
#define S2 4
#define S3 5
#define OUT 6

tcs3200 tcs(S0, S1, S2, S3, OUT);

void setup() {
  Serial.begin(9600);
  Serial.println("TCS3200 Color Sensor Ready");
}

void loop() {
  delay(500);
  
  // Read frequency for each color using character parameters
  int red = tcs.colorRead('r');     // Use 'r' instead of TCS3200_RED
  int green = tcs.colorRead('g');   // Use 'g' instead of TCS3200_GREEN
  int blue = tcs.colorRead('b');    // Use 'b' instead of TCS3200_BLUE
  
  Serial.print("Red: ");
  Serial.print(red);
  Serial.print(" | Green: ");
  Serial.print(green);
  Serial.print(" | Blue: ");
  Serial.println(blue);
}