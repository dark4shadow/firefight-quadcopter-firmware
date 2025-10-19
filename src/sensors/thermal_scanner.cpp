#include "sensors/thermal_scanner.hpp"
#include <Arduino.h>

ThermalScanner::ThermalScanner(int sensorPin) : sensorPin(sensorPin) {
    pinMode(sensorPin, INPUT);
}

float ThermalScanner::readTemperature() {
    // Simulate reading temperature from a thermal sensor
    int rawValue = analogRead(sensorPin);
    float voltage = rawValue * (5.0 / 1023.0);
    float temperature = (voltage - 0.5) * 100; // Convert voltage to temperature
    return temperature;
}

bool ThermalScanner::detectFire(float threshold) {
    float temperature = readTemperature();
    return temperature > threshold;
}

void ThermalScanner::initialize() {
    // Initialization code for the thermal scanner
    Serial.println("Thermal Scanner initialized.");
}

void ThermalScanner::update() {
    // Update logic for the thermal scanner
    if (detectFire(50.0)) { // Example threshold for fire detection
        Serial.println("Fire detected!");
    }
}