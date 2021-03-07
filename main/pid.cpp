#include "pid.h"
#include "waribashi-drone.h"

PID::PID() {}

float PID::calc_angular_velocity(float yaw){
    float a_vel = (yaw - old_yaw) / (float)SAMPLING_INTERVAL;
    if (a_vel <= -180) a_vel += 360;
    if (a_vel >= 180) a_vel -= 360;
    old_yaw = yaw;
    return a_vel;
}

void PID::calc_pid_elm(){
    for (int i=0; i<3; i++) {
        pid_d[i] = (pid_p[i] - old_pid_p[i]) / ((float)SAMPLING_INTERVAL/1000);
        pid_i[i] += pid_p[i];
        old_pid_p[i] = pid_p[i];
    }
}

void PID::get_pid_res(float data[3]){
    for (int i = 0; i < 3; ++i) data[i] = pid_res[i];
}

void PID::update_pid(float RPY_data[3], int command_var[4]){
    for(int i=0; i<2; i++) pid_p[i] = RPY_data[i] - command_var[i];
    float a_vel = calc_angular_velocity(RPY_data[2]);
    pid_p[2] = a_vel - command_var[2];

    calc_pid_elm();
    for (int i = 0; i < 3; ++i) pid_res[i] = Kp[i]*pid_p[i] + Ki[i]*pid_i[i] + Kd[i]*pid_d[i];
}

void PID::print_pid_elements(){
    Serial.println(
    (String)"pid Roll elem: "
    + (String)pid_p[0] + (String)","
    + (String)pid_i[0] + (String)","
    + (String)pid_d[0] + (String)","
    );

    Serial.println(
    (String)"pid Pitch elem: "
    + (String)pid_p[1] + (String)","
    + (String)pid_i[1] + (String)","
    + (String)pid_d[1] + (String)","
    );

    Serial.println(
    (String)"pid Yaw Speed elem: "
    + (String)pid_p[2] + (String)","
    + (String)pid_i[2] + (String)","
    + (String)pid_d[2] + (String)","
    );
}

void PID::print_pid_res(){
    Serial.println(
    (String)"pid Rall, Pitch, Yaw speed: "
    + (String)pid_res[0] + (String)","
    + (String)pid_res[1] + (String)","
    + (String)pid_res[2] + (String)","
    );
}