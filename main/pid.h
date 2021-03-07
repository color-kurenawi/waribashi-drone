#ifndef PID_H
#define PID_H

#include <Arduino.h>

class PID{
    public:
    PID();

    // v_vel = vertical velocity
    // a_vel = angular velocity
    void update_pid(float RPY_data[3], int command_var[4]);
    void calc_pid();
    void get_pid_res(float data[3]);

    private:
    float Kp[3] = {10.0f, 10.0f, 10.0f};
    float Ki[3] = {0.1f, 0.1f, 0.1f};
    float Kd[3] = {1.0f, 1.0f, 1.0f};
    
    float pid_p[3] = {0.0f, 0.0f, 0.0f};
    float pid_i[3] = {0.0f, 0.0f, 0.0f};
    float pid_d[3] = {0.0f, 0.0f, 0.0f};
    float old_pid_p[3] = {0.0f, 0.0f, 0.0f};

    float pid_res[3] = {0.0f, 0.0f, 0.0f};

    float old_yaw = 0.0f;
    float calc_angular_velocity(float yaw);
    void calc_pid_elm();
};

#endif