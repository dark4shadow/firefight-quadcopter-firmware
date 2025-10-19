#include "comms/emergency_channel.hpp"
#include <WiFi.h>
#include <HTTPClient.h>

EmergencyChannel::EmergencyChannel(const String& emergencyServiceUrl)
    : serviceUrl(emergencyServiceUrl) {}

void EmergencyChannel::init() {
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED) {
        delay(1000);
    }
}

void EmergencyChannel::sendEmergencyAlert(const String& location, float co2Level) {
    if (WiFi.status() == WL_CONNECTED) {
        HTTPClient http;
        http.begin(serviceUrl);
        http.addHeader("Content-Type", "application/json");

        String jsonPayload = "{\"location\":\"" + location + "\",\"co2Level\":" + String(co2Level) + "}";
        int httpResponseCode = http.POST(jsonPayload);

        if (httpResponseCode > 0) {
            String response = http.getString();
            Serial.println("Response: " + response);
        } else {
            Serial.println("Error sending alert: " + String(httpResponseCode));
        }

        http.end();
    } else {
        Serial.println("WiFi not connected. Unable to send alert.");
    }
}