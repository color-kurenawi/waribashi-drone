#include "imu_mpu6050.h"

Madgwick MadgwickFilter

MPU6050::MPU6050() {}

void MPU6050::update_attitude() {
    MadgwickFilter.updateIMU(
        accel_val[0], accel_val[1], accel_val[2],
        gyro_val[0], gyro_val[1], gyro_val[2]
    );
    rpy_val[0] = MadgwickFilter.getRoll();
    rpy_val[1] = MadgwickFilter.getPitch();
    rpy_val[2] = MadgwickFilter.getYaw();
}

void MPU6050::update_sensor(){ 
    getEvent(&accel, &gyro, &temp); 

    accel_val[0] = get_aX();
    accel_val[1] = get_aY();
    accel_val[2] = get_aZ();

    gyro_val[0] = get_gX();
    gyro_val[1] = get_gY();
    gyro_val[2] = get_gZ();
}

void MPU6050::update_offset(int offset_seconds=2){
    float aXsum = 0;
    float aYsum = 0;
    float aZsum = 0;
    float gXsum = 0;
    float gYsum = 0;
    float gZsum = 0;

    unsigned long start_time = millis();
    int times = 0;

    while (true){
        update_sensor();
        aXsum += accel.acceleration.x; 
        aYsum += accel.acceleration.y; 
        aZsum += accel.acceleration.z; 

        gXsum += gyro.gyro.x;
        gYsum += gyro.gyro.y;
        gZsum += gyro.gyro.z;

        times++;
        unsigned long elapsed_time = millis() - start_time;
        if (times >= 1 && elapsed_time > offset_seconds * 1000) break;
    }

    float aXmean = aXsum / times;
    float aYmean = aYsum / times;
    float aZmean = aZsum / times;
    float gXmean = gXsum / times;
    float gYmean = gYsum / times;
    float gZmean = gZsum / times;

    aXOffset = aXmean;
    aYOffset = aYmean;
    aZOffset = aZmean;
    gXOffset = gXmean;
    gYOffset = gYmean;
    gZOffset = gZmean;
}


float MPU6050::get_aX(){return accel.acceleration.x - aXOffset;}
float MPU6050::get_aY(){return accel.acceleration.y - aYOffset;}
float MPU6050::get_aZ(){return GRAVITY + accel.acceleration.z - aZOffset;}

float MPU6050::get_gX(){return gyro.gyro.x - gXOffset;}
float MPU6050::get_gY(){return gyro.gyro.y - gYOffset;}
float MPU6050::get_gZ(){return gyro.gyro.z - gZOffset;}

void MPU6050::get_accel(float accel_data[3]){
    accel_data[0] = accel_val[0];
    accel_data[1] = accel_val[1];
    accel_data[2] = accel_val[2];
}

void MPU6050::get_gyro(float gyro_data[3]){
    gyro_data[0] = gyro_val[0];
    gyro_data[1] = gyro_val[1];
    gyro_data[2] = gyro_val[2];
}

void MPU6050::get_sensor_value(float accel_data[3], float gyro_data[3]){
    get_accel(accel_data);
    get_gyro(gyro_data);
}

void MPU6050::get_attitude(float RPY_data[3]){
    RPY_data[0] = rpy_val[0];
    RPY_data[1] = rpy_val[1];
    RPY_data[2] = rpy_val[2];
}

void MPU6050::setup(){
    begin();
    setAccelerometerRange(MPU6050_RANGE_4_G);
    setGyroRange(MPU6050_RANGE_500_DEG);
    setFilterBandwidth(MPU6050_BAND_44_HZ);
    update_offset();

    sampling_rate = 1.0 / ((float)SAMPLING_INTERVAL / 1000);
    MadgwickFilter.begin(sampling_rate);
}