//----------------------------------------------------------------------//
// Author:
// Net ID:
// Date:
//
//----------------------------------------------------------------------//

#ifndef COMMAND_H
#define COMMAND_H

// M_PI and other variables are defined in here
#ifndef _USE_MATH_DEFINES
     #define _USE_MATH_DEFINES
#endif
#include <math.h>

// the MAX and MIN values for tire angle are used
// in the setTireAngle method
#define MAX_TIRE_ANGLE_RATE 0.5236
#define MIN_TIRE_ANGLE_RATE -0.5236

class Command{
private:
    double _velocity;           // commanded vehicle velocity
    double _tire_angle_rate;    // commanded tire angle rate
    double _timestamp;          // time stamp at which this command is valid
    
public:
    Command(double vel, double tireAngleRate, double timestamp);
    Command();
        bool IsValid();
    
    double GetVelocity() const;
    void SetVelocity(double vel);
    double GetTireAngleRate() const;
    void SetTireAngleRate(double angle);
    double GetTimeStamp() const;
    void SetTimeStamp(double timestamp);
};

#endif // INPUT_H
