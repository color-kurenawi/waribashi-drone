#ifndef WARIBASHI_DRONE_H
#define WARIBASHI_DRONE_H

#define SAMPLING_INTERVAL 100 // milli seconds

#define TRANSMIT_DATA_SIZE 5

#define LEFT_X_PIN 34
#define LEFT_Y_PIN 35
#define RIGHT_X_PIN 36
#define RIGHT_Y_PIN 39

#define READ_MIN 0
#define READ_MAX 4095

#define ROLL_MIN -30
#define ROLL_MAX 30
#define PITCH_MIN -30
#define PITCH_MAX 30

#define YAW_SPEED_MIN -30
#define YAW_SPEED_MAX 30
#define YAW_SPEED_DIFF_MIN -10
#define YAW_SPEED_DIFF_MAX 10

#define THROTTOL_MIN 0
#define THROTTOL_MAX 255
#define THROTTOL_DIFF_MIN -50
#define THROTTOL_DIFF_MAX 50


#endif