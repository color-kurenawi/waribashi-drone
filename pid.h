#ifndef PID_H
#define PID_H

#include <Arduino.h>

class PID{
    public:
    PID();

    // v_vel = vertical velocity
    // a_vel = angular velocity
    void update_pid(float RPY_data[3], float v_vel, float command_var[4]);
    void calc_pid();
    void get_pid_res(float data[4]);

    private:
    float Kp[4] = {10.0f, 10.0f, 10.0f, 10.0f};
    float Ki[4] = {0.1f, 0.1f, 0.1f, 0.1f};
    float Kd[4] = {1.0f, 1.0f, 1.0f, 1.0f};
    
    float pid_p[4] = {0.0f, 0.0f, 0.0f, 0.0f};
    float pid_i[4] = {0.0f, 0.0f, 0.0f, 0.0f};
    float pid_d[4] = {0.0f, 0.0f, 0.0f, 0.0f};
    float old_pid_p[4] = {0.0f, 0.0f, 0.0f, 0.0f};

    float pid_res[4] = {0.0f, 0.0f, 0.0f, 0.0f};

    float old_yaw = 0.0f;
    float calc_angular_velocity(float yaw);
    void calc_pid_elm();
};

#endif