//----------------------------------------------------------------------//
// Author:
// Net ID:
// Date:
//
//----------------------------------------------------------------------//

#ifndef STATE_H
#define STATE_H

#ifndef _USE_MATH_DEFINES
    #define _USE_MATH_DEFINES
#endif

#include <math.h>
#include <sstream>

// the MAX and MIN values for tire angle are used
// in the setTireAngle method
#define MAX_TIRE_ANGLE 0.5236
#define MIN_TIRE_ANGLE -0.5236

// 2PI is important for values of heading
#define M_TWO_TIMES_PI (2*M_PI)


class State{
private:
    double _xpos; // vehicle position, forward (x1)
    double _ypos; // vehicle position, left/right (x2)
    double _tire_angle; // tire angle (radians) (x3)
    double _heading; // heading (radians) (x4)
    double _timestamp; // time stamp at which this state is measured

public:
    State(double x1, double x2, double x3, double x4, double timestamp);
    State();
    double GetXPos() const;
    void SetXPos(double xpos);
    double GetYPos() const;
    void SetYPos(double ypos);
    double GetTireAngle() const;
    void SetTireAngle(double angle);
    double GetHeading() const;
    void SetHeading(double heading);
    double GetTimeStamp() const;
    void SetTimeStamp(double timestamp);
};

#endif // STATE_H
