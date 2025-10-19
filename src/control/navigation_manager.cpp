#include "control/navigation_manager.hpp"
#include "sensors/gps_receiver.hpp"
#include "sensors/co2_analyzer.hpp"
#include "comms/emergency_channel.hpp"
#include "services/return_to_base.hpp"
#include "actuators/powder_dispersal.hpp"
#include <iostream>
#include <vector>

NavigationManager::NavigationManager(GPSReceiver& gps, CO2Analyzer& co2Analyzer, EmergencyChannel& emergencyChannel, PowderDispersal& powderDispersal)
    : gpsReceiver(gps), co2Analyzer(co2Analyzer), emergencyChannel(emergencyChannel), powderDispersal(powderDispersal), currentState(Idle) {}

void NavigationManager::update() {
    switch (currentState) {
        case Idle:
            // Check for CO2 levels and GPS position
            if (co2Analyzer.getCO2Level() > CO2_THRESHOLD) {
                currentState = DetectingFire;
            }
            break;

        case DetectingFire:
            // Locate potential fires using GPS and CO2 data
            if (locateFire()) {
                currentState = Extinguishing;
            } else {
                currentState = ReturningToBase;
            }
            break;

        case Extinguishing:
            // Activate powder dispersal mechanism
            powderDispersal.activate();
            currentState = ReturningToBase;
            break;

        case ReturningToBase:
            returnToBase();
            break;
    }
}

bool NavigationManager::locateFire() {
    // Logic to locate fire based on CO2 levels and GPS coordinates
    std::cout << "Locating fire based on CO2 levels and GPS data..." << std::endl;
    // Simulated logic for fire detection
    return true; // Assume fire is detected for this example
}

void NavigationManager::returnToBase() {
    std::cout << "Returning to base for recharging..." << std::endl;
    // Logic to navigate back to the base station
    emergencyChannel.notifyEmergencyServices("Fire detected, returning to base.");
    currentState = Idle; // Reset state after returning
}