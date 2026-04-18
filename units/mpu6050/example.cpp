// Requires: Adafruit MPU6050 + Adafruit Unified Sensor libraries
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>

Adafruit_MPU6050 mpu;

void setup() {
  Serial.begin(9600);
  if (!mpu.begin()) {
    Serial.println("MPU6050 not found!");
    while (1);
  }
  mpu.setAccelerometerRange(MPU6050_RANGE_8_G);
  mpu.setGyroRange(MPU6050_RANGE_500_DEG);
}

void loop() {
  sensors_event_t accel, gyro, temp;
  mpu.getEvent(&accel, &gyro, &temp);

  Serial.print("Accel X: "); Serial.print(accel.acceleration.x);
  Serial.print("  Y: ");     Serial.print(accel.acceleration.y);
  Serial.print("  Z: ");     Serial.println(accel.acceleration.z);

  Serial.print("Gyro X: ");  Serial.print(gyro.gyro.x);
  Serial.print("  Y: ");     Serial.print(gyro.gyro.y);
  Serial.print("  Z: ");     Serial.println(gyro.gyro.z);

  delay(500);
}
