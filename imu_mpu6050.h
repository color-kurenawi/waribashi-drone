#ifndef IMU_MPU6050_H
#define IMU_MPU6050_H

#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>
#include <Arduino.h>

#define GRAVITY 9.80665

class MPU6050 : public Adafruit_MPU6050 {
    public:
    MPU6050();

    void setup();
    void update_sensor();
    void update_offset(int);

    float get_aX();
    float get_aY();
    float get_aZ();

    float get_gX();
    float get_gY();
    float get_gZ();

    void get_accel(float accel_data[3]);
    void get_gyro(float gyro_data[3]);
    void get_sensor_value(float accel_data[3], float gyro_data[3]);

    private:
    Adafruit_Sensor *mpu_accel, *mpu_gyro;
    sensors_event_t accel;
    sensors_event_t gyro;
    sensors_event_t temp;
    float aXOffset=0;
    float aYOffset=0;
    float aZOffset=0;
    float gXOffset=0;
    float gYOffset=0;
    float gZOffset=0;

    float accel_val[3] = {0.0f, 0.0f, 0.0f};
    float gyro_val[3] = {0.0f, 0.0f, 0.0f};
};

#endif