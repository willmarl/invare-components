// use IRremote library by sherrif, z3t0, arminjo
#include <IRremote.h>

#define IR_RECEIVE_PIN 11

void setup() {
  Serial.begin(9600);
  IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK);
  
  Serial.println("IR Receiver Ready");
}

void loop() {
  if (IrReceiver.decode()) {
    Serial.print("Protocol: ");
    Serial.println(IrReceiver.decodedIRData.protocol);
    
    Serial.print("Command: ");
    Serial.println(IrReceiver.decodedIRData.command, HEX);
    
    Serial.println("---");
    
    IrReceiver.resume();
  }
}