#ifndef CO2_ANALYZER_HPP
#define CO2_ANALYZER_HPP

#include <Arduino.h>

class CO2Analyzer {
public:
    CO2Analyzer(int sensorPin);
    void begin();
    float readCO2Level();
    bool isHighCO2Level(float threshold);

private:
    int sensorPin;
    float readAnalogValue();
};

#endif // CO2_ANALYZER_HPP