#include "return_to_base.hpp"
#include "gps_receiver.hpp"
#include "battery_manager.hpp"
#include "navigation_manager.hpp"
#include "emergency_channel.hpp"

ReturnToBase::ReturnToBase(GPSReceiver& gps, BatteryManager& battery, NavigationManager& navigation, EmergencyChannel& emergency)
    : gpsReceiver(gps), batteryManager(battery), navigationManager(navigation), emergencyChannel(emergency) {}

void ReturnToBase::init() {
    // Initialize return to base parameters
    isReturning = false;
}

void ReturnToBase::startReturn() {
    if (isReturning) return;

    isReturning = true;
    emergencyChannel.notifyEmergencyServices("Returning to base for recharge.");
    navigationManager.setDestination(gpsReceiver.getBaseStationLocation());
}

void ReturnToBase::update() {
    if (!isReturning) return;

    if (batteryManager.isBatteryLow()) {
        navigationManager.setDestination(gpsReceiver.getBaseStationLocation());
    }

    if (navigationManager.hasArrived()) {
        isReturning = false;
        batteryManager.recharge();
    }
}

bool ReturnToBase::isActive() const {
    return isReturning;
}