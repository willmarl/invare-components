// use encoder library by paul stroggregen
#include <Encoder.h>

const int rotarySW = 4;

Encoder rotary(2, 3);  // CLK, DT pins

void setup() {
  Serial.begin(9600);
  pinMode(rotarySW, INPUT_PULLUP);
}

void loop() {
  long rotaryPosition = rotary.read();
  Serial.println(rotaryPosition);
  
  // Button handling - you still do this manually
  if (digitalRead(rotarySW) == LOW) {
    delay(20);
    if (digitalRead(rotarySW) == LOW) {
      Serial.println("Button Pressed!");
      while (digitalRead(rotarySW) == LOW);
      delay(20);
    }
  }
  
  delay(100);
}


////////////////////////////
// Manual way without lib
////////////////////////////
// const int rotaryCLK = 2;
// const int rotaryDT = 3;
// const int rotarySW = 4;

// volatile int rotaryPosition = 0;
// volatile int lastRotaryPosition = 0;

// void setup() {
//   Serial.begin(9600);
  
//   pinMode(rotaryCLK, INPUT_PULLUP);
//   pinMode(rotaryDT, INPUT_PULLUP);
//   pinMode(rotarySW, INPUT_PULLUP);
  
//   // Attach interrupt to CLK pin (detects state changes)
//   attachInterrupt(digitalPinToInterrupt(rotaryCLK), handleEncoder, CHANGE);
// }

// void loop() {
//   if (rotaryPosition != lastRotaryPosition) {
//     Serial.print("Rotary Position: ");
//     Serial.println(rotaryPosition);
//     lastRotaryPosition = rotaryPosition;
//   }
  
//   if (digitalRead(rotarySW) == LOW) {
//     delay(20);
//     if (digitalRead(rotarySW) == LOW) {
//       Serial.println("Button Pressed!");
//       while (digitalRead(rotarySW) == LOW);
//       delay(20);
//     }
//   }
// }

// void handleEncoder() {
//   if (digitalRead(rotaryCLK) == digitalRead(rotaryDT)) {
//     rotaryPosition++;
//   } else {
//     rotaryPosition--;
//   }
// }