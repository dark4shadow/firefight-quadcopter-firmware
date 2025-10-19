#ifndef MOTOR_CONTROLLER_HPP
#define MOTOR_CONTROLLER_HPP

#include <Arduino.h>

class MotorController {
public:
    MotorController(int motorPin1, int motorPin2, int motorPin3, int motorPin4);
    void initialize();
    void setMotorSpeed(int motorIndex, int speed);
    void stopMotors();
    void setAllMotorsSpeed(int speed);
    
private:
    int motorPins[4];
};

#endif // MOTOR_CONTROLLER_HPP