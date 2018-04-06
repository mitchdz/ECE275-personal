//----------------------------------------------------------------------//
// Author:
// Net ID:
// Date:
//
//----------------------------------------------------------------------//

#ifndef TESTSTATE_H
#define TESTSTATE_H

#ifndef _USE_MATH_DEFINES
    #define _USE_MATH_DEFINES
#endif

#include <math.h>
#include <sstream>

class StateTester{
private:

public:
    void RunTests();
    bool testSetTireAngleAboveMaximum();
    bool testSetTireAngleBelowMinimum();
    bool testSetHeadingAboveTwoPi();
    bool testSetHeadingBelowTwoPi();
};

#endif // TESTSTATE_H
