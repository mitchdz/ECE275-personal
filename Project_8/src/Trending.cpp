//----------------------------------------------------------------------//
// Author:
// Net ID:
// Date:
//
//----------------------------------------------------------------------//


#include "Trending.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <array>
#include <functional>

using namespace std;

Trending::Trending(string startHashtagFilePath, string endHashtagFilePath, string outputHashtagFilePath){
    _startHashtagFilePath = startHashtagFilePath;
    _endHashtagFilePath = endHashtagFilePath;
    _outputHashtagFilePath = outputHashtagFilePath;
}

void Trending::Run(){   //runs the 3 functions for this program.
    ReadHashtagsFromFile();
    ProcessHashtags();
    WriteHashTagsToFile();
}

void Trending::ReadHashtagsFromFile() {

    ifstream startHashtagFS(_startHashtagFilePath);
    ifstream endHashtagFS(_endHashtagFilePath);
    string line;

    if (!startHashtagFS.is_open())  {
        cout << "Yo we done got ourselves a problem here.";
        cout << " File " << _startHashtagFilePath << " will not open. :(" << endl;
        return;
    }

    if (!endHashtagFS.is_open())    {
        cout << "Yo we done got ourselves a problem here.";
        cout << " File " << _endHashtagFilePath << " will not open. :(" << endl;
        return;
    }

    unsigned int i = 0;
    int enable;
        //iterates through the text file
    while (!startHashtagFS.eof()) {
        startHashtagFS >> line; //inserts a string from the file into line
            //transform function to make all of the characters of a string
            //lowercase
        std::transform(line.begin(), line.end(), line.begin(), ::tolower);
        enable = 0; //enable signal to make a new hashtag object
        for (i = 0; i < _Hashtags.size(); ++i) {
            if (line == _Hashtags[i].GetWord()) {
                    /*
                     * edge case where the last word counts twice.
                     * I'm not exactly sure why this happens,
                     * but decrementing it fixed it.
                     */
                if (startHashtagFS.eof()) {
                    _Hashtags[i].DecrementStartCount();
                }
                _Hashtags[i].IncrementStartCount();
                enable = 1;
                break;
            }
        }   //creates a new hashtag for the vector.
        if (enable == 0) {
            Hashtag tempTag(line);
            tempTag.IncrementStartCount();
            _Hashtags.push_back(tempTag);
        }
    }

    while (!endHashtagFS.eof()) {
        endHashtagFS >> line;
        std::transform(line.begin(), line.end(), line.begin(), ::tolower);

        enable = 0;
        for (i = 0; i < _Hashtags.size(); ++i)  {
            if (line == _Hashtags[i].GetWord()) {
                    //edge case for end word
                if (endHashtagFS.eof()) {
                    _Hashtags[i].DecrementEndCount();
                }


                _Hashtags[i].IncrementEndCount();
                enable = 1;
                break;
            }
        }       //creates a new Hashtag for the vector.
        if (enable == 0) {
            Hashtag tempTag(line);
            tempTag.IncrementEndCount();
            _Hashtags.push_back(tempTag);
        }
    }
    startHashtagFS.close(); //closes both files.
    endHashtagFS.close();
}

void Trending::CalculateSum() {
        //iterates through the vector
    for (unsigned int i = 0; i < _Hashtags.size(); ++i) {
            //Finds the difference between the start and rank rank
        int newRank = _Hashtags[i].GetStartRank() - _Hashtags[i].GetEndRank();
            //Sets the new rank to the private member.
        _Hashtags[i].SetSumRank(newRank);
    }
}
bool sortStart(Hashtag a, Hashtag b)  {return (a.GetStartCount() < b.GetStartCount());}
void Trending::ProcessHashtags()  {
        //sorts using the sortStart function for the startRank
    sort(_Hashtags.begin(), _Hashtags.end(), sortStart);
        //Reverses the string, so that it is from largest to smallest.
    reverse(_Hashtags.begin(), _Hashtags.end());
    int rank = 1;
    unsigned int i = 0;

    while(i < _Hashtags.size()) {
                //compares startCounts, to see if there is a tie for rank
        if  (_Hashtags[i+1].GetStartCount() == _Hashtags[i].GetStartCount())    {
            while (_Hashtags[i+1].GetStartCount() == _Hashtags[i].GetStartCount()) {
                _Hashtags[i].SetStartRank(rank);
                ++i;
                    //edge case if the last two or more are a tie
                if (i >= _Hashtags.size() - 1 ) {
                    break;
                }
            }
                //edge case if the last two or more are a tie
            if (i >= _Hashtags.size() - 1) {
                break;
            }
            _Hashtags[i].SetStartRank(rank);
            ++i;
        }
        else    //Case for if there is no tie for the rank
        {
            _Hashtags[i].SetStartRank(rank);
            ++i;
        }
        ++rank;
    }
        //sorts using the overloaded operator.
    sort(_Hashtags.begin(), _Hashtags.end());
        //resets the values to count the endRank
    i = 0;
    rank = 1;
        //Same as the above while loop, but is for the EndCount
    while(i < _Hashtags.size()) {
        if  (_Hashtags[i+1].GetEndCount() == _Hashtags[i].GetEndCount())    {
            while (_Hashtags[i+1].GetEndCount() == _Hashtags[i].GetEndCount()) {
                _Hashtags[i].SetEndRank(rank);
                ++i;
                if (i >= _Hashtags.size() -1 ) {
                    break;
                }
            }
            if (i >= _Hashtags.size() - 1) {
                break;
            }

            _Hashtags[i].SetEndRank(rank);
            ++i;
        }
        else
        {
            _Hashtags[i].SetEndRank(rank);
            ++i;
        }
        ++rank;
    }
        //Uses the CalculateSum Function to find
        //StartSum - EndSum
    CalculateSum();
}
void Trending::WriteHashTagsToFile()    {
        //opens files.
    ofstream outputFS;
    outputFS.open(_outputHashtagFilePath);

    if (!outputFS.is_open()) {
        cout << "Yo my man, we got a problem up in this hood";
        cout << " file " << _outputHashtagFilePath << " Won't open." << endl;
        return;
    }
    unsigned int i = 0;
    unsigned int currRank = 1;
    unsigned int numHashtags = _Hashtags.size();
    i = 0;
        //increments through the vector.
    while ( i < _Hashtags.size())   {
       while (_Hashtags[i].GetEndCount() == 0)  {
           ++i;
           if (i == numHashtags)    //edge case for if the last hashtags are a tie
               break;
       }

        if (i == numHashtags)    {  //edge case
            break;
        }
                //if statement to determine if there is a tie.
        if  ((_Hashtags[i].GetEndRank() == _Hashtags[i+1].GetEndRank())
                && _Hashtags[i+1].GetEndRank() != 0)   {
            while (_Hashtags[i].GetEndRank() == _Hashtags[i+1].GetEndRank()) {
                if (_Hashtags[i].GetStartCount() == 0) { //Case for new
                    outputFS << "T" << currRank << ": " << _Hashtags[i].GetWord()
                             << " (new)" << endl;
                }
                else {  //default case
                    outputFS << "T" << currRank << ": " << _Hashtags[i].GetWord()
                             << " ("
                             << std::showpos
                             << _Hashtags[i].GetSumRank()
                             << ")" << endl;
                }
                ++i;
            }
            if (_Hashtags[i].GetStartCount() == 0) {    //case for new
                outputFS << "T" << currRank << ": " << _Hashtags[i].GetWord()
                         << " (new)" << endl;
            }
            else {  //default case
                outputFS << "T" << currRank << ": " << _Hashtags[i].GetWord()
                         << " ("
                         << std::showpos
                         << _Hashtags[i].GetSumRank()
                         << ")" << endl;
            }
            ++i;
        }

        else if (_Hashtags[i].GetStartCount() == 0 && i != _Hashtags.size()) {
            outputFS << currRank << ": " << _Hashtags[i].GetWord()
                     << " (new)" << endl;
            ++i;
        }

        else if (i != _Hashtags.size()){
            outputFS << currRank << ": " << _Hashtags[i].GetWord()
                     << " ("
                     << std::showpos
                     << _Hashtags[i].GetSumRank()
                     << ")" << endl;
            ++i;
        }

        currRank++;
    }
    outputFS.close();   //closes the file
}

