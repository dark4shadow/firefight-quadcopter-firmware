#ifndef BATTERY_MANAGER_HPP
#define BATTERY_MANAGER_HPP

#include <cstdint>

class BatteryManager {
public:
    BatteryManager(float capacity, float lowThreshold, float criticalThreshold);
    
    void updateBatteryStatus(float deltaTime);
    float getBatteryLevel() const;
    bool isBatteryLow() const;
    bool isBatteryCritical() const;
    void recharge();

private:
    float batteryCapacity;
    float batteryLevel;
    float lowBatteryThreshold;
    float criticalBatteryThreshold;
    float idleDrainPerSecond;
    float flightDrainPerSecond;

    void drainBattery(float deltaTime);
};

#endif // BATTERY_MANAGER_HPP