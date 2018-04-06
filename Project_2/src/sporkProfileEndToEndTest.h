//----------------------------------------------------------------------//
// Author:
// Net ID:
// Date:
//
//----------------------------------------------------------------------//


#ifndef SPORKPROFILEENDTOEND_H
#define SPORKPROFILEENDTOEND_H

#include <stdio.h>
#include <string.h>
#include "sporkprofile.h"

#ifdef __linux__
// definitely do not modify this, this will cause trouble
    #define TEST_FILE_RELATIVE_PATH "../../test_files"
#elif __APPLE__
    #define TEST_FILE_RELATIVE_PATH "../../test_files"
#else
    #define TEST_FILE_RELATIVE_PATH "../test_files"
#endif

typedef struct testDescription_struct{
    float userLocX;
    float userLocY;
    float minAvgRating;
    float maxDist;
} testDescription;

testDescription createDescription(double userLocX, double userLocY, double maxDist, double minAvgRating);
void testEndToEndSporkProfile();
int testFile(testDescription test, int testNum);

#endif /* sporkProfileEndToEnd_h */
