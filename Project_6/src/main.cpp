//----------------------------------------------------------------------//
// Author:
// Net ID:
// Date:
//
//----------------------------------------------------------------------//

#include "testEndToEnd.h"
#include "testChars.h"
#include <fstream>
#include <iostream>

using namespace std;

int main() {
    
    CharsTester test2;
    test2.RunTests();
    
    EndToEndTester test;
    test.RunTests();

    return 0;
}

