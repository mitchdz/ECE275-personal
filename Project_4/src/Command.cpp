//----------------------------------------------------------------------//
// Author:
// Net ID:
// Date:
//
//----------------------------------------------------------------------//

#include "Command.h"

/**
 * Creates Command object with provided parameters
 *
 * @requirement all data members are set to corresponding provided parameters
 */
Command::Command(double vel, double tireAngleRate, double timestamp){
    _velocity = vel;
    _tire_angle_rate = tireAngleRate;
    _timestamp = timestamp;

}

/**
 * Creates Command object
 *
 * @requirement _velocity, _tire_angle_rate, and _timestamp are all set to 0.0
 */
Command::Command(){
    _velocity = 0.0;  //sets all values to 0.0
    _tire_angle_rate = 0.0;
    _timestamp = 0.0;
}

/**
 * Validates a Command object
 *
 * @requirement Velocity is less than or equal to 30
 * @requirement Velocity is not negative
 * @requirement Tire angle rate is within bounds of MAX and MIN tire angle rate defines
 * @requirement timestamp is not negative
 */
bool Command::IsValid(){
    return this->_velocity <= 30 && this->_velocity >= 0.0
           && this->_tire_angle_rate >= MIN_TIRE_ANGLE_RATE
           && this->_tire_angle_rate <= MAX_TIRE_ANGLE_RATE
           && this->_timestamp >= 0.0;
}

/**
 * Getter for _velocity
 *
 * @requirement gets _velocity data member
 */
double Command::GetVelocity() const {
    return _velocity;
}

/**
 * Setter for _velocity
 *
 * @requirement sets _velocity data member
 */
void Command::SetVelocity(double vel) {
    _velocity = vel;
}

/**
 * Getter for _tire_angle_rate
 *
 * @requirement gets _tire_angle_rate data member
 */
double Command::GetTireAngleRate() const {
    return _tire_angle_rate;
}

/**
 * Setter for _tire_angle_rate
 *
 * @requirement sets _tire_angle_rate data member
 */
void Command::SetTireAngleRate(double angle) {
    _tire_angle_rate = angle;
}

/**
 * Getter for _timestamp
 *
 * @requirement gets _timestamp data member
 */
double Command::GetTimeStamp() const {
    return _timestamp;
}

/**
 * Setter for _timestamp
 *
 * @requirement sets _timestamp data member
 */
void Command::SetTimeStamp(double timestamp) {
    _timestamp = timestamp;
}
