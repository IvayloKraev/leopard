#include <Arduino.h>

#include <IRremote.hpp>

#include "actions.hpp"
#include "rcCommands.hpp"

#define IR_RECEIVE_PIN 2

void stop(void*){
    Serial.println("stop");
}

void forward(void*) {
    Serial.println("forward");
}

void backward(void*) {
    Serial.println("backward");
}

void leftspin(void*) {
    Serial.println("leftspin");
}

void rightspin(void*) {
    Serial.println("rightspin");
}

Actions actions(stop);

void setup() {
    Serial.begin(115200);
    actions.resizeTo(8);
    actions.registerCommandAction(RC_CMD_FORWARD, forward);
    actions.registerCommandAction(RC_CMD_BACKWARD, backward);
    actions.registerCommandAction(RC_CMD_LEFTSPIN, leftspin);
    actions.registerCommandAction(RC_CMD_RIGHTSPIN, rightspin);
    
    IrReceiver.begin(IR_RECEIVE_PIN);
}

void loop() {
    if (IrReceiver.decode()) {
        IrReceiver.resume();
        Serial.println(IrReceiver.decodedIRData.command);
        actions.executeCommandAction(IrReceiver.decodedIRData.command, nullptr);
    }
}