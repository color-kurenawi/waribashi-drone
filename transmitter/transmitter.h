#ifndef TRANSMIT_H
#define TRANSMIT_H

#include <BluetoothSerial.h>
#include <Arduino.h>
#include "waribashi-drone.h"
#include "private-address.h"

class Transmitter{
    public:
    Transmitter();

    void setup();
    void set_command(int8_t command_data[4]);
    void transmit();

    private:
    bool connected;
    int8_t transmit_command[TRANSMIT_DATA_SIZE] {'C', 0, 0, 0, 0};
};

#endif