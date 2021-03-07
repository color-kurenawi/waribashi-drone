#include "controller.h"

Controller::Controller() {}

void Controller::update_command(){
    input_command();
    translate_command();
}

void Controller::input_command(){
    left_x = analogRead(LEFT_X_PIN);
    left_y = analogRead(LEFT_Y_PIN);
    right_x = analogRead(RIGHT_X_PIN);
    right_y = analogRead(RIGHT_Y_PIN);
}

void Controller::translate_command(){
    translated_command[0] = map(right_x, READ_MIN, READ_MAX, ROLL_MIN, ROLL_MAX);

    translated_command[1] = map(right_y, READ_MIN, READ_MAX, PITCH_MIN, PITCH_MAX);

    translated_command[2] = angular_speed + map(left_y, READ_MIN, READ_MAX, YAW_SPEED_DIFF_MIN, YAW_SPEED_DIFF_MAX);
    translated_command[2] = constrain(translated_command[2], YAW_SPEED_MIN, YAW_SPEED_MAX);

    translated_command[3] = throttol + map(left_x, READ_MIN, READ_MAX, THROTTOL_DIFF_MIN, THROTTOL_DIFF_MAX);
    translated_command[3] = constrain(translated_command[3], THROTTOL_MIN, THROTTOL_MAX);
}

void Controller::get_command(int8_t command_data[4]){
    for (int i = 0; i < 4; ++i ) command_data[i] = translated_command[i];
}