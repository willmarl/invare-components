// use `Adafruit MLX90614 Library` lib by adafruit
#include <Wire.h>
#include <Adafruit_MLX90614.h>

Adafruit_MLX90614 mlx = Adafruit_MLX90614();

void setup() {
  Serial.begin(9600);
  Wire.begin();

  if (!mlx.begin()) {
    Serial.println("MLX90614 not found");
    while (1);
  }

  Serial.println("GY-906 / MLX90614 Ready");
}

void loop() {
  delay(500);

  Serial.print("Ambient: ");
  Serial.print(mlx.readAmbientTempC());
  Serial.print(" C | Object: ");
  Serial.print(mlx.readObjectTempC());
  Serial.println(" C");
}
