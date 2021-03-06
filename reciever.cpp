#include "reciever.h"

BluetoothSerial SerialBT;

Reciever::Reciever() {}

void Reciever::setup(){
    Serial.begin(1152000);
    SerialBT.begin("ESP32RECIEVER");
}

void Reciever::update_command() {
    if (SerialBT.available()) {
        SerialBT.readBytes(receive_command, RECIEVE_DATA_SIZE);
    }
}

void Reciever::get_command(int command_var[4]){
    command_var[0] = receive_command[1];
    command_var[1] = receive_command[2];
    command_var[2] = receive_command[3];
    command_var[3] = receive_command[4];
}