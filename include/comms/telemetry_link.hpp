#ifndef TELEMETRY_LINK_HPP
#define TELEMETRY_LINK_HPP

#include <string>
#include <vector>

class TelemetryLink {
public:
    TelemetryLink(const std::string& baseStationAddress, int port);
    void sendTelemetryData(const std::vector<float>& data);
    void receiveCommands();
    bool isConnected() const;

private:
    std::string baseStationAddress;
    int port;
    bool connected;

    void connect();
    void disconnect();
    void handleReceivedData(const std::string& data);
};

#endif // TELEMETRY_LINK_HPP