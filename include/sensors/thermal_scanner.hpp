#ifndef THERMAL_SCANNER_HPP
#define THERMAL_SCANNER_HPP

#include <Arduino.h>
#include <Wire.h>

class ThermalScanner {
public:
    ThermalScanner(int sensorPin);
    void begin();
    float readTemperature();
    bool detectFire(float threshold);

private:
    int sensorPin;
    float convertToCelsius(int rawValue);
};

#endif // THERMAL_SCANNER_HPP