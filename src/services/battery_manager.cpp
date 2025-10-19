#include "services/battery_manager.hpp"

BatteryManager::BatteryManager(float capacity, float lowThreshold, float criticalThreshold)
    : batteryCapacity(capacity), lowBatteryThreshold(lowThreshold), criticalBatteryThreshold(criticalThreshold), batteryLevel(capacity) {}

void BatteryManager::Update(float deltaTime) {
    if (batteryLevel <= 0.0f) {
        batteryLevel = 0.0f;
        // Trigger return to base logic if battery is depleted
        NotifyBatteryDepleted();
        return;
    }

    float drain = idleDrainPerSecond;
    // Add flight drain if the drone is in active states
    if (isActive) {
        drain += flightDrainPerSecond;
    }

    batteryLevel = std::max(0.0f, batteryLevel - drain * deltaTime);

    if (batteryLevel <= criticalBatteryThreshold) {
        NotifyCriticalBattery();
    } else if (batteryLevel <= lowBatteryThreshold) {
        NotifyLowBattery();
    }
}

void BatteryManager::Recharge() {
    batteryLevel = batteryCapacity;
}

float BatteryManager::GetBatteryLevel() const {
    return batteryLevel;
}

bool BatteryManager::IsBatteryLow() const {
    return batteryLevel <= lowBatteryThreshold;
}

bool BatteryManager::IsBatteryCritical() const {
    return batteryLevel <= criticalBatteryThreshold;
}

void BatteryManager::NotifyBatteryDepleted() {
    // Logic to handle battery depletion
}

void BatteryManager::NotifyLowBattery() {
    // Logic to handle low battery warning
}

void BatteryManager::NotifyCriticalBattery() {
    // Logic to handle critical battery warning
}