#ifndef EMERGENCY_CHANNEL_HPP
#define EMERGENCY_CHANNEL_HPP

#include <string>

class EmergencyChannel {
public:
    EmergencyChannel(const std::string& serviceEndpoint);
    void notifyEmergencyServices(const std::string& message);
    void setServiceEndpoint(const std::string& endpoint);
    std::string getServiceEndpoint() const;

private:
    std::string serviceEndpoint;
};

#endif // EMERGENCY_CHANNEL_HPP