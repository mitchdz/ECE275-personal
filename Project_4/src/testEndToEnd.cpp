//----------------------------------------------------------------------//
// Author:
// Net ID:
// Date:
//
//----------------------------------------------------------------------//

#include "testEndToEnd.h"
#include "CarSimulator.h"

using namespace std;

void EndToEndTester::RunTests(){

    for(int i = 0; i < 10; ++i)
            TestFile(i);
    // call TestFile for all inputFiles in the test_files folder
}


/*
 * @requirement pass if all lines output[testNum + 1] are the exact same (strcmp returns 0) as myOutput[testNum + 1] AND output files can be opened properly
 * @return pass: true, fail: false
 */
int EndToEndTester::TestFile(int testNum){
    ostringstream inputPathOSS;
    ostringstream outputPathOSS;
    ostringstream myOutPutPathOSS;
    string inputPath;
    string outputPath;
    string myOutPutPath;

    // Create filepaths for the input, myOutput, and output text files.
    // input and output files are provided in the test_files folder.
    // myOutput is what is produced by the program being run
    inputPathOSS << TEST_FILE_RELATIVE_PATH << "/input" << testNum +1 << ".txt";
    outputPathOSS << TEST_FILE_RELATIVE_PATH << "/output" << testNum + 1 << ".txt";
    myOutPutPathOSS << TEST_FILE_RELATIVE_PATH << "/myOutput" << testNum + 1 << ".txt";

    inputPath = inputPathOSS.str();
    outputPath = outputPathOSS.str();
    myOutPutPath = myOutPutPathOSS.str();

    // run the CarSimulator which involved 3 steps.
    // 1. read commands
    // 2. run the commands
    // 3. output state history

    CarSimulator* newCarObjectSimulator;

    newCarObjectSimulator = new CarSimulator(inputPath, myOutPutPath);

    newCarObjectSimulator->ReadCommandsFromFile();
    newCarObjectSimulator->RunAllCommands();
    newCarObjectSimulator->WriteStateHistoryToFile();


    // compare myOutput and corresponding output file line by line
    // if they differ on even one line, the test should fail



    ifstream output1;
    ifstream myOutput1;
    output1.open(outputPath);
    myOutput1.open(myOutPutPath);

    string buffer1;
    string buffer2;


    if (!output1.is_open())   {
        cout << "Could not open file " << outputPath << endl;
        return 0;
    }
    if (!myOutput1.is_open()) {
        cout << "Could not open file " << myOutPutPath << endl;
        return 0;
    }

    while(!myOutput1.eof())  {

        output1 >> buffer1;
        myOutput1 >> buffer2;

        if (buffer1 != buffer2) {
            cout << "String1  : " << buffer1 << endl;
            cout << ">String2 : " << buffer2 << endl;
            output1.close();
            myOutput1.close();
            return 0;
        }
    }
    output1.close();
    myOutput1.close();
    return 1;
}
