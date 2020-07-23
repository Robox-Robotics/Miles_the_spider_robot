#include <MPU6050_tockn.h>
#include <Wire.h>
#include <Servo.h>
MPU6050 mpu6050(Wire);
int val1;
int prevVal1;
int val2,val3;
int prevVal2,prevVal3;
Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;
void setup() {
  Serial.begin(9600);
  Wire.begin();
  mpu6050.begin();
  mpu6050.calcGyroOffsets(true);
  servo1.attach(2);
  servo2.attach(4);
  servo3.attach(6);
  servo4.attach(8);
}

void loop() {
  mpu6050.update();
  val1=mpu6050.getAngleX();
    val2=mpu6050.getAngleY();
    val3=mpu6050.getAngleZ();
  if(val1>50) val1=50;
  if(val1<-50) val1=-50;
    if(val2>20) val2=20;
  if(val2<-20) val2=-20;
 val1 = map(val1, -50, 50, 0, 179);
  val2 = map(val2, -20, 20, 0, 179);
  val3 = map(val3, -180, 180, 0, 179);
if (val1 != prevVal1 && val2 != prevVal2 && val3 != prevVal3)
{
 yaw(val3);
prevVal1 = val1;
prevVal2=val2;
prevVal3=val3;
}
}

void yaw(int val3){
  servo1.write(val3);
servo2.write(val3);
servo3.write(val3);
servo4.write(val3);
}

void savey(){//Serial.print(mpu6050.getAngleX());
servo1.write(val2);
servo2.write(180-val2);
servo3.write(180-val2);
servo4.write(val2);
}
void savex(){//Serial.print(mpu6050.getAngleX());
servo1.write(val1);
servo2.write(val1);
servo3.write(180-val1);
servo4.write(180-val1);
}
