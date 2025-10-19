#include "actuators/powder_dispersal.hpp"
#include <Arduino.h>

PowderDispersal::PowderDispersal(int motorPin) : motorPin(motorPin) {
    pinMode(motorPin, OUTPUT);
    digitalWrite(motorPin, LOW);
}

void PowderDispersal::activate() {
    digitalWrite(motorPin, HIGH);
}

void PowderDispersal::deactivate() {
    digitalWrite(motorPin, LOW);
}

void PowderDispersal::dispense(float duration) {
    activate();
    delay(duration * 1000); // Convert seconds to milliseconds
    deactivate();
}