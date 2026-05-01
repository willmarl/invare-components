// use MPU6050 lib by Electronic Cats
#include <Wire.h>
#include <MPU6050.h>

MPU6050 mpu;

void setup() {
  Serial.begin(9600);
  Wire.begin();
  
  delay(100);
  mpu.initialize();
  
  if (mpu.testConnection()) {
    Serial.println("MPU6050 Connected!");
  } else {
    Serial.println("MPU6050 connection failed");
  }
}

void loop() {
  delay(1000);
  
  int16_t ax, ay, az;
  int16_t gx, gy, gz;
  int16_t temp;
  
  mpu.getAcceleration(&ax, &ay, &az);
  mpu.getRotation(&gx, &gy, &gz);
  temp = mpu.getTemperature();  // Raw temperature value
  
  Serial.print("Accel - X: ");
  Serial.print(ax);
  Serial.print(" Y: ");
  Serial.print(ay);
  Serial.print(" Z: ");
  Serial.println(az);
  
  Serial.print("Gyro - X: ");
  Serial.print(gx);
  Serial.print(" Y: ");
  Serial.print(gy);
  Serial.print(" Z: ");
  Serial.println(gz);
  
  // Convert raw temp to Celsius
  float tempC = (temp / 340.0) + 36.53;
  Serial.print("Temperature: ");
  Serial.print(tempC);
  Serial.println("°C");
  
  Serial.println("---");
}