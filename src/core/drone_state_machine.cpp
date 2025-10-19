#include "core/drone_state_machine.hpp"
#include "sensors/co2_analyzer.hpp"
#include "sensors/gps_receiver.hpp"
#include "sensors/thermal_scanner.hpp"
#include "actuators/powder_dispersal.hpp"
#include "services/battery_manager.hpp"
#include "services/return_to_base.hpp"
#include "comms/emergency_channel.hpp"
#include "control/manual_interface.hpp"
#include "control/navigation_manager.hpp"

DroneStateMachine::DroneStateMachine()
    : state(DroneState::Idle), batteryManager(new BatteryManager()), 
      co2Analyzer(new CO2Analyzer()), gpsReceiver(new GPSReceiver()), 
      thermalScanner(new ThermalScanner()), powderDispersal(new PowderDispersal()), 
      emergencyChannel(new EmergencyChannel()), manualInterface(new ManualInterface()), 
      navigationManager(new NavigationManager()) {}

void DroneStateMachine::update() {
    switch (state) {
        case DroneState::Idle:
            handleIdleState();
            break;
        case DroneState::Patrol:
            handlePatrolState();
            break;
        case DroneState::Investigate:
            handleInvestigateState();
            break;
        case DroneState::Extinguish:
            handleExtinguishState();
            break;
        case DroneState::Return:
            handleReturnState();
            break;
        case DroneState::Manual:
            handleManualState();
            break;
    }
}

void DroneStateMachine::handleIdleState() {
    if (co2Analyzer->detectHighCO2Levels()) {
        state = DroneState::Investigate;
    } else if (manualInterface->isManualControlActive()) {
        state = DroneState::Manual;
    }
}

void DroneStateMachine::handlePatrolState() {
    navigationManager->navigateToNextWaypoint();
    if (co2Analyzer->detectHighCO2Levels()) {
        state = DroneState::Investigate;
    } else if (batteryManager->isBatteryLow()) {
        state = DroneState::Return;
    }
}

void DroneStateMachine::handleInvestigateState() {
    if (thermalScanner->detectFire()) {
        state = DroneState::Extinguish;
    } else if (batteryManager->isBatteryLow()) {
        state = DroneState::Return;
    } else {
        navigationManager->navigateToFireLocation();
    }
}

void DroneStateMachine::handleExtinguishState() {
    powderDispersal->activate();
    if (!thermalScanner->isFireActive()) {
        state = DroneState::Return;
    }
}

void DroneStateMachine::handleReturnState() {
    if (batteryManager->isBatteryCritical()) {
        emergencyChannel->notifyEmergencyServices();
    }
    navigationManager->returnToBase();
    if (navigationManager->hasArrivedAtBase()) {
        batteryManager->recharge();
        state = DroneState::Idle;
    }
}

void DroneStateMachine::handleManualState() {
    manualInterface->controlDrone();
    if (!manualInterface->isManualControlActive()) {
        state = DroneState::Return;
    }
}