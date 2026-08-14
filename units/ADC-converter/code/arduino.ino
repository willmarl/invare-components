// use `Adafruit MCP3008` lib by adafruit
#include <SPI.h>
#include <Adafruit_MCP3008.h>

Adafruit_MCP3008 adc;

#define CS_PIN 10

void setup() {
  Serial.begin(9600);

  if (!adc.begin(CS_PIN)) {
    Serial.println("MCP3008 not found");
    while (1);
  }

  Serial.println("MCP3008 Ready");
}

void loop() {
  delay(200);

  for (int ch = 0; ch < 8; ch++) {
    int value = adc.readADC(ch);  // 0-1023
    Serial.print("CH");
    Serial.print(ch);
    Serial.print(": ");
    Serial.print(value);
    Serial.print("  ");
  }
  Serial.println();
}
