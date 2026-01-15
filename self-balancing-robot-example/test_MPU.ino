#include "I2Cdev.h"
#include "MPU6050.h"
#include "math.h"

MPU6050 IMU;

int16_t accY, accZ;
float accAngle;

void setup() 
{  
  IMU.initialize();
  // IMU.setIntDataReadyEnabled(true);
  Serial.begin(9600);
}

void loop() 
{  
  accY = IMU.getAccelerationY();
  accZ = IMU.getAccelerationZ();
  
  accAngle = atan2(accY, accZ)*RAD_TO_DEG;
  
  if(isnan(accAngle))
    Serial.println("NaN angle reading");
  else
    Serial.println(accAngle);

  delay(100);
}