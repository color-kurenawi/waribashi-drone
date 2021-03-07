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
    
    // デバッグ用関数
    void print_command();

    private:
    uint8_t receive_command[RECIEVE_DATA_SIZE] = {'C', UINT8_MAX/2, UINT8_MAX/2, UINT8_MAX/2, 0}; // Flag(C:Control), Roll(deg), Pitch(deg), Yaw speed(deg/SAMPLING_INTERVAL), throttol([0, 255])
    int translated_command[RECIEVE_DATA_SIZE] = {'C', 0, 0, 0, 0};

};

#endif