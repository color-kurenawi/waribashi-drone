#ifndef RECIEVER_H
#define RECIEVER_H

#include <Arduino.h>
#include <BluetoothSerial.h>
#include "waribashi-drone.h"

class Reciever {
    public:
    Reciever();

    void setup();
    void update_command();
    void get_command(int command_var[4]);

    private:
    int8_t receive_command[RECIEVE_DATA_SIZE] = {'C', 0, 0, 0, 0}; // Flag(C:Control), Roll(deg), Pitch(deg), Yaw speed(deg/SAMPLING_INTERVAL), throttol([0, 255])

};

#endif