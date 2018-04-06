//----------------------------------------------------------------------//
// Author:
// Net ID:
// Date:
//
//----------------------------------------------------------------------//

#include "State.h"

using namespace std;

/**
 * Creates State object with provided parameters
 *
 * @requirement all data members are set to corresponding provided parameters
 */
State::State(double x1, double x2, double x3, double x4, double timestamp) {
//    this->SetXPos(x1);
//    this->SetYPos(x2);
//    this->SetTireAngle(x3);
//    this->SetHeading(x4);
//    this->SetTimeStamp(timestamp);
    _xpos = x1;
    _ypos = x2;
    _tire_angle = x3;
    _heading = x4;
    _timestamp = timestamp;


}

/**
 * Creates State object
 *
 * @requirement all data members are set to 0.0
 */
State::State() {
    _xpos = 0.0;
    _ypos = 0.0;
    _tire_angle = 0.0;
    _heading = 0.0;
    _timestamp = 0.0;
}

/**
 * Getter for _tire_angle
 *
 * @requirement gets _tire_angle data member
 */
double State::GetTireAngle() const {
    return _tire_angle;
}

/**
 * Setter for _tire_angle
 *
 * @requirement sets _tire_angle data member
 * @requirement _tire_angle is set to MAX_TIRE_ANGLE if provided angle is greater than MAX_TIRE_ANGLE
 * @requirement _tire_angle is set to MIN_TIRE_ANGLE if provided angle is less than MIN_TIRE_ANGLE
 */
void State::SetTireAngle(double angle){
    if (angle > MAX_TIRE_ANGLE)
        this->_tire_angle = MAX_TIRE_ANGLE;
    else if (angle < MIN_TIRE_ANGLE)
        this->_tire_angle = MIN_TIRE_ANGLE;
    else
        this->_tire_angle = angle;
}

/**
 * Getter for _heading
 *
 * @requirement gets _heading data member
 */
double State::GetHeading() const {
    return _heading;
}

/**
 * Setter for _heading
 *
 * @requirement sets _heading data member
 * @requirement _heading is set to an equivalent angle (in radians) between [0, 2*pi).
 * An angle is equivalent for any addition or subtraction of 2*pi
 * Example: and angle of -pi is equivalent to -pi + 2*pi = pi
 */
void State::SetHeading(double heading){


        while (heading < 0.0) {
            heading += M_TWO_TIMES_PI;
        }

        while (heading >= M_TWO_TIMES_PI) {
            heading -= M_TWO_TIMES_PI;
        }

        _heading = heading;   //if the value is within bounds, then return the original value.

}

/**
 * Getter for _xpos
 *
 * @requirement gets _xpos data member
 */
double State::GetXPos() const {
    return _xpos;
}

/**
 * Setter for _xpos
 *
 * @requirement sets _xpos data member
 */
void State::SetXPos(double xpos) {
    this->_xpos = xpos;
}

/**
 * Getter for _ypos
 *
 * @requirement gets _ypos data member
 */
double State::GetYPos() const {
    return this->_ypos;
}

/**
 * Setter for _ypos
 *
 * @requirement sets _ypos data member
 */
void State::SetYPos(double ypos) {
    this->_ypos = ypos;
}

/**
 * Getter for _timestamp
 *
 * @requirement gets _timestamp data member
 */
double State::GetTimeStamp() const {
    return _timestamp;
}

/**
 * Setter for _timestamp
 *
 * @requirement sets _timestamp data member
 */
void State::SetTimeStamp(double timestamp) {
    _timestamp = timestamp;
}
