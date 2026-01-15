#include <MPU6050.h>  // install this from the library manager (MPU-6050 by Electric cats)
#include "math.h"     // include this library for the atan() function
// #include "I2CDev.h"

MPU6050 mpu;              // "mpu" is our sensor object of the type MPU6050
float accX, accZ, angle;  // global variables for storing the accelerometer readings and angle

void setup() {
  // put your setup code here, to run once:
  mpu.initialize();       // turn on the accel/gyro
  Serial.begin(9600);     // start serial communication
}

void loop() {
  accX = mpu.getAccelerationX();  // read the X acceleration
  accZ = mpu.getAccelerationZ();  // read the Z acceleration
  angle = 57.3*atan(accX/accZ);   // compute the angle of the sensor
  Serial.println(angle);          // print out the angle on serial monitor
  delay(100);
}
