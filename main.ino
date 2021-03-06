
#include "imu_mpu6050.h"
#include "reciever.h"
#include "pid.h"
#include "motor.h"


Reciever reciever;
MPU6050 myMPU;
PID pid;
Motor motor;

void setup() {
    // put your setup code here, to run once:
    Serial.begin(115200);
    reciever.setup();
    myMPU.setup();
    motor.setup();
}

void loop() {
    // put your main code here, to run repeatedly:
    int command_var[4];
    int throttol;
    float RPY_data[3];
    float pid_res[3];

    reciever.update_command();
    reciever.get_command(command_var);

    myMPU.update_sensor();
    myMPU.update_attitude();
    myMPU.get_attitude(RPY_data);

    pid.update_pid(RPY_data, command_var);
    pid.get_pid_res(pid_res);

    throttol = command_var[3];
    motor.update_signal(pid_res, throttol);
    motor.control();

    delay(SAMPLING_INTERVAL);
}
