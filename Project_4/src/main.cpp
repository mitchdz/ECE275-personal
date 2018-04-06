//----------------------------------------------------------------------//
// Author:  Mitchell Dzurick
// Net ID:
// Date:
//
//----------------------------------------------------------------------//

#include "testEndToEnd.h"
#include "testCommand.h"
#include "testState.h"

using namespace std;

int main() {
    
    StateTester testState;
    testState.RunTests();
    
    CommandTester testCommand;
    testCommand.RunTests();
    
    EndToEndTester test;
    test.RunTests();
    
    return EXIT_SUCCESS;
}
