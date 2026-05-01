#include <math.h>

const int THERMISTOR_PIN = A0;
const float RT0 = 10000.0;    // R₂₅ from your datasheet
const float B = 3950.0;       // β-value from your datasheet
const float T0 = 298.15;      // 25°C in Kelvin

void setup() {
  Serial.begin(9600);
}

void loop() {
  int adc = analogRead(THERMISTOR_PIN);
  float voltage = (adc / 1023.0) * 5.0;
  float rt = 10000.0 * voltage / (5.0 - voltage);
  
  float tempK = 1.0 / (log(rt / RT0) / B + 1.0 / T0);
  float tempC = tempK - 273.15;
  float tempF = (tempC * 9.0 / 5.0) + 32.0;
  
  Serial.print("Temperature: ");
  Serial.print(tempC, 1);
  Serial.print("C / ");
  Serial.print(tempF, 1);
  Serial.println("F");
  
  delay(1000);
}