#include "integration/unity_adapter.hpp"
#include "sensors/co2_analyzer.hpp"
#include "sensors/gps_receiver.hpp"
#include "sensors/thermal_scanner.hpp"
#include "comms/emergency_channel.hpp"
#include "services/battery_manager.hpp"
#include "control/manual_interface.hpp"
#include "control/navigation_manager.hpp"
#include "core/drone_state_machine.hpp"

UnityAdapter::UnityAdapter(CO2Analyzer& co2Analyzer, GPSReceiver& gpsReceiver, 
                           ThermalScanner& thermalScanner, EmergencyChannel& emergencyChannel,
                           BatteryManager& batteryManager, ManualInterface& manualInterface,
                           NavigationManager& navigationManager, DroneStateMachine& stateMachine)
    : co2Analyzer(co2Analyzer), gpsReceiver(gpsReceiver), thermalScanner(thermalScanner),
      emergencyChannel(emergencyChannel), batteryManager(batteryManager),
      manualInterface(manualInterface), navigationManager(navigationManager),
      stateMachine(stateMachine) {}

void UnityAdapter::initialize() {
    // Initialize sensors and communication channels
    co2Analyzer.initialize();
    gpsReceiver.initialize();
    thermalScanner.initialize();
    emergencyChannel.initialize();
    batteryManager.initialize();
    manualInterface.initialize();
    navigationManager.initialize();
    stateMachine.initialize();
}

void UnityAdapter::update() {
    // Update sensor readings
    co2Analyzer.update();
    gpsReceiver.update();
    thermalScanner.update();

    // Check for high CO2 levels
    if (co2Analyzer.getCO2Level() > CO2_THRESHOLD) {
        // Locate potential fire
        if (thermalScanner.detectFire()) {
            // Notify emergency services
            emergencyChannel.notifyEmergencyServices(gpsReceiver.getCurrentLocation());
            // Activate powder dispersal
            manualInterface.activatePowderDispersal();
        }
    }

    // Manage battery status
    if (batteryManager.isLowBattery()) {
        stateMachine.transitionToReturnToBase();
    }

    // Handle manual control inputs
    manualInterface.handleInput();
}

void UnityAdapter::shutdown() {
    // Shutdown all components
    co2Analyzer.shutdown();
    gpsReceiver.shutdown();
    thermalScanner.shutdown();
    emergencyChannel.shutdown();
    batteryManager.shutdown();
    manualInterface.shutdown();
    navigationManager.shutdown();
    stateMachine.shutdown();
}