#include "motor.h"

Motor::Motor() {}

void Motor::setup(){
    pinMode(MOTOR_PIN_00, OUTPUT);
    pinMode(MOTOR_PIN_01, OUTPUT);
    pinMode(MOTOR_PIN_02, OUTPUT);
    pinMode(MOTOR_PIN_03, OUTPUT);

    ledcSetup(0, 12800, 8);
    ledcSetup(1, 12800, 8);
    ledcSetup(2, 12800, 8);
    ledcSetup(3, 12800, 8);

    ledcAttachPin(MOTOR_PIN_00, 0);
    ledcAttachPin(MOTOR_PIN_01, 1);
    ledcAttachPin(MOTOR_PIN_02, 2);
    ledcAttachPin(MOTOR_PIN_03, 3);
}

void Motor::update_signal(float pid_res[3], int throttol){
    motor_signal[0] = - pid_res[0] - pid_res[1] - pid_res[2] + throttol;
    motor_signal[1] = + pid_res[0] - pid_res[1] + pid_res[2] + throttol;
    motor_signal[2] = + pid_res[0] + pid_res[1] - pid_res[2] + throttol;
    motor_signal[3] = - pid_res[0] + pid_res[1] + pid_res[2] + throttol;

    for (int i=0; i<4; ++i) {constrain(motor_signal[i], 0, 255);}
}

void Motor::control(){
    for (int i=0; i < 4; ++i) {
        ledcWrite(i, motor_signal[i]);
    }
}

void Motor::stop(){
    for (int i=0; i < 4; ++i) {
        ledcWrite(i, 0);
    }
}

