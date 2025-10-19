#ifndef POWDER_DISPERSAL_HPP
#define POWDER_DISPERSAL_HPP

#include <Arduino.h>

class PowderDispersal {
public:
    PowderDispersal(int controlPin);
    void begin();
    void disperse(float amount);
    void stop();

private:
    int controlPin;
    bool isActive;
};

#endif // POWDER_DISPERSAL_HPP