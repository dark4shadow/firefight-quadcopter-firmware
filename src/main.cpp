#include <iostream>
#include <thread>
#include <chrono>
#include "core/app_context.hpp"
#include "core/drone_state_machine.hpp"
#include "comms/telemetry_link.hpp"
#include "comms/emergency_channel.hpp"
#include "sensors/co2_analyzer.hpp"
#include "sensors/gps_receiver.hpp"
#include "sensors/thermal_scanner.hpp"
#include "actuators/motor_controller.hpp"
#include "actuators/powder_dispersal.hpp"
#include "services/battery_manager.hpp"
#include "services/return_to_base.hpp"
#include "control/manual_interface.hpp"
#include "control/navigation_manager.hpp"

int main() {
    AppContext appContext;
    DroneStateMachine droneStateMachine(appContext);
    TelemetryLink telemetryLink;
    EmergencyChannel emergencyChannel;
    CO2Analyzer co2Analyzer;
    GPSReceiver gpsReceiver;
    ThermalScanner thermalScanner;
    MotorController motorController;
    PowderDispersal powderDispersal;
    BatteryManager batteryManager;
    ReturnToBase returnToBase;
    ManualInterface manualInterface;
    NavigationManager navigationManager;

    appContext.initialize();
    droneStateMachine.initialize();
    telemetryLink.initialize();
    emergencyChannel.initialize();
    co2Analyzer.initialize();
    gpsReceiver.initialize();
    thermalScanner.initialize();
    motorController.initialize();
    powderDispersal.initialize();
    batteryManager.initialize();
    returnToBase.initialize();
    manualInterface.initialize();
    navigationManager.initialize();

    while (true) {
        droneStateMachine.update();
        telemetryLink.sendTelemetryData();
        co2Analyzer.checkCO2Levels();
        thermalScanner.scanForHeatSources();
        gpsReceiver.updateGPSData();
        batteryManager.updateBatteryStatus();

        if (manualInterface.isManualControlActive()) {
            manualInterface.handleManualInput();
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }

    return 0;
}