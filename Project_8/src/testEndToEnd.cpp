//----------------------------------------------------------------------//
// Author:
// Net ID:
// Date:
//
//----------------------------------------------------------------------//

#include "testEndToEnd.h"
#include "Trending.h"
#include <algorithm>

using namespace std;

void EndToEndTester::RunTests(){
    for(int i = 0; i < 10; i++){
        cout << "Running file test " << i << endl;
        TestFile(i);
    }
}


/*
 * @requirement pass if all lines in files are the exact same (strcmp returns 0) AND output files can be opened properly
 * @return pass: 1, fail: 0
 */
bool EndToEndTester::TestFile(int testNum){
    int myFileIsFinished = 0;
    
    ostringstream startHashtagsPath;
    ostringstream endHashtagsPath;
    ostringstream myOutputFilePath;
    ostringstream correctOutputFilePath;
    startHashtagsPath << TEST_FILE_RELATIVE_PATH << "/startHashtags" << testNum + 1 << ".txt";
    endHashtagsPath << TEST_FILE_RELATIVE_PATH << "/endHashtags" << testNum + 1 << ".txt";
    myOutputFilePath << TEST_FILE_RELATIVE_PATH << "/myOutput" << testNum + 1 << ".txt";
    correctOutputFilePath << TEST_FILE_RELATIVE_PATH << "/output" << testNum + 1 << ".txt";
    
    Trending trending(startHashtagsPath.str(), endHashtagsPath.str(), myOutputFilePath.str());
    trending.Run();
    
    ifstream myOutputFile(myOutputFilePath.str());
    ifstream correctOutputFile(correctOutputFilePath.str());
    
    if(!myOutputFile.is_open() || !correctOutputFile.is_open()){
        cout << "Could not open output files.\n" << endl;
        return false;
    }
    
    //check to see if any line is different
    string correctLineBuffer;
    string myLineBuffer;
    istringstream myLineStream;
    istringstream correctLineStream;
    int lineNumber = 0;
    while(!correctOutputFile.eof()){
        getline(myOutputFile, myLineBuffer);
        getline(correctOutputFile, correctLineBuffer);
        correctLineBuffer.erase( std::remove(correctLineBuffer.begin(), correctLineBuffer.end(), '\r'), correctLineBuffer.end() );
        if(myLineBuffer.compare(correctLineBuffer) != 0){
            cout << "Line Number " << lineNumber << endl
            << "Correct Line: " << correctLineBuffer << endl
            << "Your line: " << myLineBuffer << endl;
            myOutputFile.close();
            correctOutputFile.close();
            return false;
        }
        lineNumber++;
    }
    
    myFileIsFinished = myOutputFile.eof();
    myOutputFile.close();
    correctOutputFile.close();
    return myFileIsFinished;
}
