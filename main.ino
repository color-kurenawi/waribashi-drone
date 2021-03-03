
#include "imu_mpu6050.h"

MPU6050 myMPU;

void setup() {
    // put your setup code here, to run once:
    Serial.begin(115200);
    myMPU.sensor_setup();
}

void loop() {
    // put your main code here, to run repeatedly:
    myMPU.sensor_update();
    float aX = myMPU.get_aX();
    float aY = myMPU.get_aY();
    float aZ = myMPU.get_aZ();
    float gX = myMPU.get_gX();
    float gY = myMPU.get_gY();
    float gZ = myMPU.get_gZ();
    Serial.println(aX);
    Serial.println(aY);
    Serial.println(aZ);
}
