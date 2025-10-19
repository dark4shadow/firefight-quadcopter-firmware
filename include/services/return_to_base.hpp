#ifndef RETURN_TO_BASE_HPP
#define RETURN_TO_BASE_HPP

#include "gps_receiver.hpp"
#include "battery_manager.hpp"
#include "navigation_manager.hpp"
#include "emergency_channel.hpp"

class ReturnToBase {
public:
    ReturnToBase(GPSReceiver& gps, BatteryManager& battery, NavigationManager& navigation, EmergencyChannel& emergencyChannel);
    
    void initiateReturn();
    void update();
    bool isReturning() const;

private:
    GPSReceiver& gpsReceiver;
    BatteryManager& batteryManager;
    NavigationManager& navigationManager;
    EmergencyChannel& emergencyChannel;

    bool returning;
    void handleEmergencyCommunication();
};

#endif // RETURN_TO_BASE_HPP