// Requires: IRremote library by shirriff/z3t0
#include <IRremote.h>

#define IR_PIN 11

IRrecv irrecv(IR_PIN);
decode_results results;

void setup() {
  Serial.begin(9600);
  irrecv.enableIRIn();
  Serial.println("IR receiver ready");
}

void loop() {
  if (irrecv.decode(&results)) {
    Serial.print("Received: 0x");
    Serial.println(results.value, HEX);
    irrecv.resume(); // Ready for next signal
  }
}
