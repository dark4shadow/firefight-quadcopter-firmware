#include "sensors/co2_analyzer.hpp"
#include <Wire.h>
#include <Arduino.h>

CO2Analyzer::CO2Analyzer(int sensorPin) : sensorPin(sensorPin) {
    pinMode(sensorPin, INPUT);
}

float CO2Analyzer::readCO2Level() {
    // Simulate reading from a CO2 sensor
    int sensorValue = analogRead(sensorPin);
    float voltage = sensorValue * (5.0 / 1023.0); // Convert to voltage
    float co2Level = (voltage - 0.4) * (5000.0 / (2.0 - 0.4)); // Convert voltage to CO2 level in ppm
    return constrain(co2Level, 0.0, 5000.0); // Constrain to valid range
}

void CO2Analyzer::begin() {
    // Initialize the sensor if needed
    Serial.begin(9600);
}

void CO2Analyzer::update() {
    // Read and log CO2 levels periodically
    float co2Level = readCO2Level();
    Serial.print("CO2 Level: ");
    Serial.println(co2Level);
}