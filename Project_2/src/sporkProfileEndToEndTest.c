//----------------------------------------------------------------------//
// Author:
// Net ID:
// Date:
//
//----------------------------------------------------------------------//

#include "sporkProfileEndToEndTest.h"

/*
 * This is a utility function created so that running a test with various parameters is made more easy.
*/

testDescription createDescription(double userLocX, double userLocY, double maxDist, double minAvgRating){
    testDescription newDesc;
    newDesc.userLocX = userLocX;
    newDesc.userLocY = userLocY;
    newDesc.minAvgRating = minAvgRating;
    newDesc.maxDist = maxDist;
    return newDesc;
}

/*
 * This function is meant to run all tests that are pre-populated here. But it is your responsibility to finish it
*/

void testEndToEndSporkProfile(){
    testDescription tests[10];
    tests[0] = createDescription(40.41, -80.00, .07, 5.00);
    tests[1] = createDescription(35.56, -100, 0.0, 1.00);
    tests[2] = createDescription(-35.09, -80.83, 4.00, 2.00);
    tests[3] = createDescription(35.15, -80.85, .5, 4.50);
    tests[4] = createDescription(40.47, -79.97, 1.11, 5.00);
    tests[5] = createDescription(33.38, -111.74, 100.0, 0.00);
    tests[6] = createDescription(33.72, -111.93, 1.00, 3.5);
    tests[7] = createDescription(33.30, -111.50, .80, 1.50);
    tests[8] = createDescription(40.46, -79.90, .04, 2.00);
    tests[9] = createDescription(0.0, 0.0, 0.0, 0.0);
    
    // TODO: Call testFile with each testDescription in the tests array
    // TODO: POTATO


    int i = 0;  // k = 0, result = 0


    for(i = 0; i <10; ++i)  {
        testFile(tests[i], i);
    //    if (result == 0)    {
    //        k = 1;
    //    }
    }
}

/* This function effectively tests your program from beginning to end with parameters
 * that are specified in the parameter test
 *
 * The program is meant to run in the following sequence:
 * 
 * 1. Get all profiles from an input file
 * 2. Find all the "nearby" and "good" businesses according to the description
 * 3. Write the results to an output file
 *
 * To test your results, you simply need to compare the output file your program
 * produced to the output file provided to you that is correct
 *
 * @requirement pass if all lines in files are the exact same (strcmp returns 0)
 * @return pass: 1, fail: 0
 */

int testFile(testDescription test, int testNum){
    // create string buffers to create file paths
    char testFilePath[250];
    char myOutputFilePath[250];
    char correctOutputFilePath[250];
    sprintf(testFilePath, "%s/test%d.txt", TEST_FILE_RELATIVE_PATH, testNum);
    sprintf(myOutputFilePath, "%s/myOutput%d.txt", TEST_FILE_RELATIVE_PATH,testNum);
    sprintf(correctOutputFilePath, "%s/output%d.txt", TEST_FILE_RELATIVE_PATH,testNum);
    // create testProfiles with the max number of profiles
    // read data from the file
    // find nearby and good businesses
    // write spork results to file

    //SporkProfile* profile = (SporkProfile*)malloc(sizeof(MAX_SPORK_PROFILES * (SporkProfile)));

    SporkProfile testProfiles[MAX_SPORK_PROFILES];

    readSporkDataFromFile(testProfiles, testFilePath);
    findNearbyBusinesses(testProfiles, MAX_SPORK_PROFILES, test.userLocX, test.userLocY, test.maxDist);
    writeSporkResultsToFile(testProfiles, MAX_SPORK_PROFILES, myOutputFilePath);

    // open the correct output file and the file you just created


    FILE *file1, *file2;
    int num1, num2;

    file1 = fopen(myOutputFilePath, "r");
    file2 = fopen(correctOutputFilePath, "r");

    printf("Testing file #%d...\n", testNum);


    if(file1 == NULL) {
        printf("Cannot open %s to read\n", myOutputFilePath);
    }

    if(file2 == NULL)   {
        printf("Cannot open %s to read\n", correctOutputFilePath);
    }
    //else {
        num1 = getc(file1);
        num2 = getc(file2);

        while ((num1 != EOF) && (num2 != EOF) && (num1 == num2)) {
            num1 = getc(file1);
            num2 = getc(file2);
        }
        if (num1 == num2) {
            printf("The output files are the same!\n");
            return 1;
        } else
        {
            printf("The files are not the same.\n");
            return 0;
        }
    //}

  /*
   *fopen(myOutputFilePath, "r");
    fopen(correctOutputFilePath, "r");

    int k = 0;

    while(fscanf(myOutputFilePath) != EOF)  {
        if (strcmp(myOutputFilePath, correctOutputFilePath) == 1)   {
            k = 1;
        }
    }

    // check to see i`f any line is different. If they are different, this should fail.return 0;

    return k == 1 ? 1 : 0;
    */
}
