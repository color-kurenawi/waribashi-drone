#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <Arduino.h>
#include "waribashi-drone.h"

class Controller{
    public:
    Controller();

    void setup();
    void update_command();
    void get_command(int8_t command_data[4]);

    // debug用関数
    void print_input();
    void print_command();

    private:
    void input_command();
    void translate_command();
    int left_x;
    int left_y;
    int right_x;
    int right_y;

    int throttol = 0;
    int angular_speed = 0;

    uint8_t translated_command[4];
};

#endif