#include "comms/telemetry_link.hpp"
#include "core/app_context.hpp"
#include "sensors/co2_analyzer.hpp"
#include "sensors/gps_receiver.hpp"
#include "sensors/thermal_scanner.hpp"
#include "services/battery_manager.hpp"
#include <WiFi.h>
#include <HTTPClient.h>

TelemetryLink::TelemetryLink(AppContext& appContext)
    : appContext(appContext) {}

void TelemetryLink::initialize() {
    WiFi.begin(appContext.network.ssid.c_str(), appContext.network.password.c_str());
    while (WiFi.status() != WL_CONNECTED) {
        delay(1000);
    }
}

void TelemetryLink::sendTelemetryData() {
    if (WiFi.status() == WL_CONNECTED) {
        HTTPClient http;
        http.begin(appContext.network.serverUrl);

        http.addHeader("Content-Type", "application/json");

        String payload = createPayload();
        int httpResponseCode = http.POST(payload);

        if (httpResponseCode > 0) {
            String response = http.getString();
            Serial.println(httpResponseCode);
            Serial.println(response);
        } else {
            Serial.print("Error on sending POST: ");
            Serial.println(httpResponseCode);
        }

        http.end();
    }
}

String TelemetryLink::createPayload() {
    String payload = "{";
    payload += "\"gps\": {\"latitude\": " + String(appContext.gpsReceiver.getLatitude()) + 
              ", \"longitude\": " + String(appContext.gpsReceiver.getLongitude()) + "},";
    payload += "\"co2\": " + String(appContext.co2Analyzer.getCO2Level()) + ",";
    payload += "\"battery\": " + String(appContext.batteryManager.getBatteryLevel()) + ",";
    payload += "\"fire_detected\": " + String(appContext.thermalScanner.isFireDetected()) + 
              "}";
    return payload;
}