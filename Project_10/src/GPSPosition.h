//----------------------------------------------------------------------//
// Author:
// Net ID:
// Date:
//
//----------------------------------------------------------------------//

#ifndef GPSPOSITION_H
#define GPSPOSITION_H

class GPSPosition {
private:
    double _latitude;
    double _longitude;
    unsigned long _timeSeconds;
    double _speed;
    bool _doesExist;
public:
    GPSPosition(double latitude, double longitude, unsigned long timeSeconds);
    GPSPosition(bool exist, unsigned long time);
    GPSPosition(double speed, unsigned long time);
    double GetLatitude() const { return _latitude; };
    double GetLongitude() const { return _longitude; };
    unsigned long GetTime() const { return _timeSeconds; };
    void SetLatitude(double latitude) { _latitude = latitude; };
    void SetLongitude(double longitude) { _longitude = longitude; };
    void SetTime(double timeSeconds) { _timeSeconds = timeSeconds; };
    double CalcDistanceKmTo(GPSPosition toPosition);
    double GetSpeed();
    void SetSpeed(double speed);
    bool GetDoesExist();

    bool operator<(const GPSPosition& rhs) const;
};
#endif
