#ifndef APP_CONTEXT_HPP
#define APP_CONTEXT_HPP

#include <string>
#include "sensors/co2_analyzer.hpp"
#include "sensors/gps_receiver.hpp"
#include "services/battery_manager.hpp"
#include "comms/emergency_channel.hpp"
#include "control/manual_interface.hpp"
#include "control/navigation_manager.hpp"

class AppContext {
public:
    AppContext();

    void initialize();
    void update();
    void handleEmergencyCommunication();
    void returnToBase();

    CO2Analyzer& getCO2Analyzer();
    GPSReceiver& getGPSReceiver();
    BatteryManager& getBatteryManager();
    EmergencyChannel& getEmergencyChannel();
    ManualInterface& getManualInterface();
    NavigationManager& getNavigationManager();

private:
    CO2Analyzer co2Analyzer;
    GPSReceiver gpsReceiver;
    BatteryManager batteryManager;
    EmergencyChannel emergencyChannel;
    ManualInterface manualInterface;
    NavigationManager navigationManager;

    std::string currentState;
};

#endif // APP_CONTEXT_HPP