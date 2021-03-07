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

    translated_command[0] = receive_command[0];
    for (int i=1; i<4; ++i) translated_command[i] = receive_command[i] - UINT8_MAX;
    translated_command[4] = receive_command[4];
}

void Reciever::get_command(int command_var[4]){
    command_var[0] = translated_command[1];
    command_var[1] = translated_command[2];
    command_var[2] = translated_command[3];
    command_var[3] = translated_command[4];
}