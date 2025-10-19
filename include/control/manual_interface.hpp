#ifndef MANUAL_INTERFACE_HPP
#define MANUAL_INTERFACE_HPP

#include <iostream>
#include <string>

class ManualInterface {
public:
    ManualInterface();
    void enableManualControl();
    void disableManualControl();
    void setThrottle(float value);
    void setYaw(float value);
    void setPitch(float value);
    void setRoll(float value);
    void sendEmergencySignal(const std::string& message);

private:
    bool manualControlEnabled;
    float throttle;
    float yaw;
    float pitch;
    float roll;
};

#endif // MANUAL_INTERFACE_HPP