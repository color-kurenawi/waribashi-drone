#include "pid.h"
#include "waribashi-drone.h"

PID::PID() {}

float PID::calc_angular_velocity(float yaw){
    return (yaw - old_yaw) / ((float)SAMPLING_INTERVAL/1000);
}

void PID::calc_pid_elm(){
    for (int i=0; i<4; i++) {
        pid_d[i] = (pid_p[i] - old_pid_p[i]) / ((float)SAMPLING_INTERVAL/1000);
        pid_i[i] += pid_p[i];
        old_pid_p[i] = pid_p[i];
    }
}

void PID::get_pid_res(float data[4]){
    for (int i = 0; i < 4; ++i) data[i] = pid_res[i];
}

void PID::update_pid(float RPY_data[3], float v_vel, float command_var[4]){
    for(int i=0; i<2; i++) pid_p[i] = command_var[i] - RPY_data[i];
    float a_vel = calc_angular_velocity(RPY_data[2]);
    pid_p[2] = command_var[2] - a_vel;
    pid_p[3] = command_var[3] - v_vel;

    calc_pid_elm();
    for (int i = 0; i < 4; ++i) pid_res[i] = Kp[i]*pid_p[i] + Ki[i]*pid_i[i] + Kd[i]*pid_d[i];
}