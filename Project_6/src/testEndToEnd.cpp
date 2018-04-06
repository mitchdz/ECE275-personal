//----------------------------------------------------------------------//
// Author:
// Net ID:
// Date:
//
//----------------------------------------------------------------------//

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include "testEndToEnd.h"
#include "chars.h"

using namespace std;

void EndToEndTester::RunTests(){
    for(unsigned int i = 0; i < 10; ++i)
        testFile(i);
    // run all tests on the files in test_files directory.
}


/*
 * @requirement pass if all lines in files are the exact same AND output files can be opened properly
 * @return pass: 1, fail: 0
 */
bool EndToEndTester::testFile(int testNum){
    
    // create file paths for inputWords, inputCards, myOutput, and output files
    // These are all found in the test_files directory which, if you cloned this project
    // should have a file path close to TEST_FILE_RELATIVE_PATH/inputWords[testNum].txt
    
    // initialize the Chars object with the correct file strings
    // 1. Read Cards
    // 2. Read Words
    // 3. Process the cards
    // 4. Write the processed cards
    
    //check to see if any line is different between myOutput file or output file


    ostringstream inputPathOSS;
    ostringstream inputPath2OSS;
    ostringstream outputPathOSS;
    ostringstream myOutPutPathOSS;
    string inputPath;
    string inputPath2;
    string outputPath;
    string myOutPutPath;

    // Create filepaths for the input, myOutput, and output text files.
    // input and output files are provided in the test_files folder.
    // myOutput is what is produced by the program being run
    inputPathOSS << TEST_FILE_RELATIVE_PATH << "/inputCards" << testNum << ".txt";
    inputPath2OSS << TEST_FILE_RELATIVE_PATH << "/inputWords" << testNum << ".txt";
    outputPathOSS << TEST_FILE_RELATIVE_PATH << "/output" << testNum << ".txt";
    myOutPutPathOSS << TEST_FILE_RELATIVE_PATH << "/myOutput" << testNum << ".txt";

    inputPath = inputPathOSS.str();
    inputPath2 = inputPath2OSS.str();
    outputPath = outputPathOSS.str();
    myOutPutPath = myOutPutPathOSS.str();

    // run the CarSimulator which involved 3 steps.
    // 1. read commands
    // 2. run the commands
    // 3. output state history
//
//    CarSimulator* newCarObjectSimulator;
//
//    newCarObjectSimulator = new CarSimulator(inputPath, myOutPutPath);
//
//    newCarObjectSimulator->ReadCommandsFromFile();
//    newCarObjectSimulator->RunAllCommands();
//    newCarObjectSimulator->WriteStateHistoryToFile();



    Chars newChars = Chars(inputPath2, inputPath, myOutPutPath);

    newChars.ReadCardsFromFile();
    newChars.ReadWordsFromFile();
    newChars.ProcessCards();
    newChars.WriteCardsToFile();




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

    while(!myOutput1.eof() || !output1.eof())  {

//        output1 >> buffer1;
//        myOutput1 >> buffer2;

        getline(output1, buffer1);
        getline(myOutput1, buffer2);


        if (buffer1 != buffer2) {
            cout << "String1  : " << buffer1 << endl;
            cout << ">String2 : " << buffer2 << endl;
            output1.close();
            myOutput1.close();
            return false;
        }
    }
    output1.close();
    myOutput1.close();
    return true;
}

