#ifndef NAVIGATION_MANAGER_HPP
#define NAVIGATION_MANAGER_HPP

#include <vector>
#include "gps_receiver.hpp"
#include "co2_analyzer.hpp"
#include "thermal_scanner.hpp"
#include "drone_state_machine.hpp"

class NavigationManager {
public:
    NavigationManager(GPSReceiver& gps, CO2Analyzer& co2Analyzer, ThermalScanner& thermalScanner, DroneStateMachine& stateMachine);
    
    void updateNavigation();
    void setFlightPath(const std::vector<GPSCoordinates>& waypoints);
    void startPatrol();
    void returnToBase();
    void manualControl();

private:
    GPSReceiver& gpsReceiver;
    CO2Analyzer& co2Analyzer;
    ThermalScanner& thermalScanner;
    DroneStateMachine& stateMachine;

    std::vector<GPSCoordinates> flightPath;
    size_t currentWaypointIndex;

    void detectFires();
    void handleEmergencyCommunications();
    void manageReturnToBase();
};

#endif // NAVIGATION_MANAGER_HPP