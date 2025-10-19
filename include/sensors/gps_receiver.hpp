#ifndef GPS_RECEIVER_HPP
#define GPS_RECEIVER_HPP

#include <string>
#include <utility>

class GPSReceiver {
public:
    GPSReceiver();
    ~GPSReceiver();

    bool initialize();
    std::pair<double, double> getCoordinates(); // Returns latitude and longitude
    double getAltitude();
    bool isFixAvailable();

private:
    // Internal state variables for GPS data
    double latitude;
    double longitude;
    double altitude;
    bool fixAvailable;

    void updateGPSData(); // Updates the internal GPS data
};

#endif // GPS_RECEIVER_HPP