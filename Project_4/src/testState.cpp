//----------------------------------------------------------------------//
// Author:
// Net ID:
// Date:
//
//----------------------------------------------------------------------//

#include "testState.h"
#include "State.h"
#include <iostream>

using namespace std;

void StateTester::RunTests(){
    testSetTireAngleAboveMaximum();
    testSetTireAngleBelowMinimum();
    testSetHeadingAboveTwoPi();
    testSetHeadingBelowTwoPi();
}

/*
 * @requirement pass if _tire_angle returns is MAX_TIRE_ANGLE when SetTireAngle is provided an angle greater than MAX_TIRE_ANGLE
 * @return pass: true, fail: false
 */
bool StateTester::testSetTireAngleAboveMaximum(){
    State _tire_angle;  //declare _tire_angle

    _tire_angle.SetTireAngle(5.0);  //initialize _tire_angle to 5.0
    return _tire_angle.GetTireAngle() == MAX_TIRE_ANGLE;    //Test
}

/*
 * @requirement pass if _tire_angle returns is MIN_TIRE_ANGLE when SetTireAngle is provided an angle less than MIN_TIRE_ANGLE
 * @return pass: true, fail: false
 */
bool StateTester::testSetTireAngleBelowMinimum(){
    State _tire_angle;
    _tire_angle.SetTireAngle(-5.0);
    return _tire_angle.GetTireAngle() == MIN_TIRE_ANGLE;
}

/*
 * @requirement pass if _tire_angle returns an equivalent angle when SetHeading is provided an angle greater than than 2*pi
 * @return pass: true, fail: false
 */
bool StateTester::testSetHeadingAboveTwoPi(){
    State _heading;
    _heading.SetHeading(3*M_PI);
    return _heading.GetHeading() == M_PI;
}

/*
 * @requirement pass if _tire_angle returns an equivalent angle when SetHeading is provided an angle less than than 2*pi
 * @return pass: true, fail: false
 */
bool StateTester::testSetHeadingBelowTwoPi(){
    State _heading;
    _heading.SetHeading(-1);
    return _heading.GetHeading() == M_TWO_TIMES_PI - 1;
}
