//----------------------------------------------------------------------//
// Author:
// Net ID:
// Date:
//
//----------------------------------------------------------------------//

#include "testCommand.h"
#include "Command.h"
#include <iostream>

using namespace std;

void CommandTester::RunTests(){
    testNegativeVelocity();
    testVelocityTooHigh();
    testTireAngleTooLow();
    testTireAngleTooHigh();
    testNegativeTimeStamp();
}

/*
 * @requirement pass IsValid() returns false when all data members are valid except it has a negative velocity
 * @return pass: true, fail: false
 */
bool CommandTester::testNegativeVelocity(){


   Command testCommand;


    testCommand.SetVelocity(-1);
    testCommand.SetTireAngleRate(0);
    testCommand.SetTimeStamp(1);

    return !testCommand.IsValid();

    /**
     * Validates a Command object
     *
     * @requirement Velocity is less than or equal to 30
     * @requirement Velocity is not negative
     * @requirement Tire angle rate is within bounds of MAX and MIN tire angle rate defines
     * @requirement timestamp is not negative
     */
}

/*
 * @requirement pass IsValid() returns false when all data members are valid except it has a velocity above 30.0
 * @return pass: true, fail: false
 */
bool CommandTester::testVelocityTooHigh(){
    Command testCommand;

    testCommand.SetVelocity(423);
    testCommand.SetTireAngleRate(0);
    testCommand.SetTimeStamp(1);

    return !testCommand.IsValid();
}

/*
 * @requirement pass IsValid() returns false when all data members are valid except it has a tire_angle_rate below the range [0, 2*pi)
 * @return pass: true, fail: false
 */
bool CommandTester::testTireAngleTooLow(){
    Command testCommand;

    testCommand.SetVelocity(0);
    testCommand.SetTireAngleRate(-673);
    testCommand.SetTimeStamp(1);

    return !testCommand.IsValid();
}

/*
 * @requirement pass IsValid() returns false when all data members are valid except it has a tire_angle_rate above the range [0, 2*pi)
 * @return pass: true, fail: false
 */
bool CommandTester::testTireAngleTooHigh(){
    Command testCommand;

    testCommand.SetVelocity(0);
    testCommand.SetTireAngleRate(-673);
    testCommand.SetTimeStamp(1);

    return !testCommand.IsValid();

}

/*
 * @requirement pass IsValid() returns false when all data members are valid except it has a negative timestamp
 * @return pass: true, fail: false
 */
bool CommandTester::testNegativeTimeStamp(){
    Command testCommand;

    testCommand.SetVelocity(0);
    testCommand.SetTireAngleRate(0);
    testCommand.SetTimeStamp(-1);

    return !testCommand.IsValid();
}
