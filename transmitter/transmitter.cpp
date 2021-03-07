#include "transmitter.h"
#include "private-address.h"

BluetoothSerial SerialBT;

Transmitter::Transmitter() {}

void Transmitter::setup(){
    SerialBT.begin("ESP32TRANSMITTER", true);

    connected = SerialBT.connect(reciever_address);
    if (connected) {
        Serial.println("Connected Succesfully!");
    } else {
        while (!SerialBT.connected(10000)) {
            Serial.println(
                "Failed to connect. Make sure remote device is available and "
                "in range, then restart app.");
        }
    }
}

void Transmitter::set_command(int8_t command_data[4]){
    transmit_command[0] = 'C';
    for (int i = 0; i < 4; ++i) {
        transmit_command[i+1] = command_data[i];
    }
}

void Transmitter::transmit(){
    SerialBT.write(transmit_command, TRANSMIT_DATA_SIZE);
}
