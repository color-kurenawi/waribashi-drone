#include "transmitter.h"
#include "controller.h"

Transmitter transmitter;
Controller controller;

void setup() {
    // put your setup code here, to run once:
    Serial.begin(115200);
    transmitter.setup();
}

void loop() {
    int8_t command_data[4];
    
    controller.update_command();
    controller.get_command(command_data);

    transmitter.set_command(command_data);
    transmitter.transmit();
}
