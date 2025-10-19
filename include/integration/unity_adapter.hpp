#ifndef UNITY_ADAPTER_HPP
#define UNITY_ADAPTER_HPP

#include <string>
#include "gps_receiver.hpp"
#include "co2_analyzer.hpp"
#include "thermal_scanner.hpp"
#include "manual_interface.hpp"
#include "navigation_manager.hpp"
#include "powder_dispersal.hpp"
#include "emergency_channel.hpp"
#include "telemetry_link.hpp"

class UnityAdapter {
public:
    UnityAdapter(GPSReceiver& gps, CO2Analyzer& co2Analyzer, ThermalScanner& thermalScanner,
                 ManualInterface& manualInterface, NavigationManager& navigationManager,
                 PowderDispersal& powderDispersal, EmergencyChannel& emergencyChannel,
                 TelemetryLink& telemetryLink);

    void update();
    void sendTelemetryData();
    void receiveCommands();
    void notifyEmergencyServices(const std::string& message);
    void extinguishFire();

private:
    GPSReceiver& gpsReceiver;
    CO2Analyzer& co2Analyzer;
    ThermalScanner& thermalScanner;
    ManualInterface& manualInterface;
    NavigationManager& navigationManager;
    PowderDispersal& powderDispersal;
    EmergencyChannel& emergencyChannel;
    TelemetryLink& telemetryLink;

    void handleFireDetection();
    void handleCO2Level();
};

#endif // UNITY_ADAPTER_HPP