#include "core/app_context.hpp"
#include "sensors/co2_analyzer.hpp"
#include "sensors/gps_receiver.hpp"
#include "sensors/thermal_scanner.hpp"
#include "services/battery_manager.hpp"
#include "services/return_to_base.hpp"
#include "comms/emergency_channel.hpp"
#include "comms/telemetry_link.hpp"
#include "actuators/powder_dispersal.hpp"
#include "control/manual_interface.hpp"
#include "control/navigation_manager.hpp"

AppContext::AppContext()
    : batteryManager(new BatteryManager()),
      co2Analyzer(new CO2Analyzer()),
      gpsReceiver(new GPSReceiver()),
      thermalScanner(new ThermalScanner()),
      emergencyChannel(new EmergencyChannel()),
      telemetryLink(new TelemetryLink()),
      powderDispersal(new PowderDispersal()),
      manualInterface(new ManualInterface()),
      navigationManager(new NavigationManager()),
      returnToBase(new ReturnToBase()),
      currentState(DroneState::Idle) {}

AppContext::~AppContext() {
    delete batteryManager;
    delete co2Analyzer;
    delete gpsReceiver;
    delete thermalScanner;
    delete emergencyChannel;
    delete telemetryLink;
    delete powderDispersal;
    delete manualInterface;
    delete navigationManager;
    delete returnToBase;
}

void AppContext::initialize() {
    batteryManager->initialize();
    co2Analyzer->initialize();
    gpsReceiver->initialize();
    thermalScanner->initialize();
    emergencyChannel->initialize();
    telemetryLink->initialize();
    powderDispersal->initialize();
    manualInterface->initialize();
    navigationManager->initialize();
    returnToBase->initialize();
}

void AppContext::update() {
    batteryManager->update();
    co2Analyzer->update();
    gpsReceiver->update();
    thermalScanner->update();
    emergencyChannel->update();
    telemetryLink->update();
    powderDispersal->update();
    manualInterface->update();
    navigationManager->update();
    returnToBase->update();
}

DroneState AppContext::getCurrentState() const {
    return currentState;
}

void AppContext::setCurrentState(DroneState state) {
    currentState = state;
}