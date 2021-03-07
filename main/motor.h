#ifndef MOTOR_H
#define MOTOR_H

#include <Arduino.h>
#include "waribashi-drone.h"

class Motor{
    public:
    Motor();
    
    void setup();
    void update_signal(float pid_res[3], int throttle);
    void control();
    void stop();

    // デバッグ用関数
    void print_signal();

    private:
    float motor_signal[4] = {0, 0, 0, 0};

};

#endif