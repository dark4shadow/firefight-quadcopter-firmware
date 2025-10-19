#include "gps_receiver.hpp"
#include <Wire.h>
#include <Adafruit_GPS.h>

class GPSReceiver {
public:
    GPSReceiver(int8_t rxPin, int8_t txPin) : gps(&Serial1) {
        Serial1.begin(9600);
        gps.begin(9600);
    }

    void update() {
        while (gps.available()) {
            char c = gps.read();
            if (gps.parse(c)) {
                latitude = gps.latitude;
                longitude = gps.longitude;
                altitude = gps.altitude;
                fixQuality = gps.fixquality;
            }
        }
    }

    float getLatitude() const {
        return latitude;
    }

    float getLongitude() const {
        return longitude;
    }

    float getAltitude() const {
        return altitude;
    }

    int getFixQuality() const {
        return fixQuality;
    }

private:
    Adafruit_GPS gps;
    float latitude = 0.0;
    float longitude = 0.0;
    float altitude = 0.0;
    int fixQuality = 0;
};