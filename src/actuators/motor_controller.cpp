#include "motor_controller.hpp"
#include <Arduino.h>

MotorController::MotorController(int motorPins[4]) {
    for (int i = 0; i < 4; i++) {
        this->motorPins[i] = motorPins[i];
        pinMode(motorPins[i], OUTPUT);
        motorSpeeds[i] = 0;
    }
}

void MotorController::setMotorSpeed(int motorIndex, int speed) {
    if (motorIndex < 0 || motorIndex >= 4) return;
    motorSpeeds[motorIndex] = constrain(speed, 0, 255);
    analogWrite(motorPins[motorIndex], motorSpeeds[motorIndex]);
}

void MotorController::setAllMotorsSpeed(int speed) {
    for (int i = 0; i < 4; i++) {
        setMotorSpeed(i, speed);
    }
}

void MotorController::stopMotors() {
    setAllMotorsSpeed(0);
}

void MotorController::increaseSpeed(int increment) {
    for (int i = 0; i < 4; i++) {
        setMotorSpeed(i, motorSpeeds[i] + increment);
    }
}

void MotorController::decreaseSpeed(int decrement) {
    for (int i = 0; i < 4; i++) {
        setMotorSpeed(i, motorSpeeds[i] - decrement);
    }
}