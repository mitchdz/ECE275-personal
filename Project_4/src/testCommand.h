//----------------------------------------------------------------------//
// Author:
// Net ID:
// Date:
//
//----------------------------------------------------------------------//

#ifndef TESTCOMMAND_H
#define TESTCOMMAND_H

class CommandTester{
private:
    
public:
    void RunTests();
    bool testNegativeVelocity();
    bool testVelocityTooHigh();
    bool testTireAngleTooLow();
    bool testTireAngleTooHigh();
    bool testNegativeTimeStamp();
};

#endif // TESTCOMMAND_H
