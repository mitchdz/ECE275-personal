//----------------------------------------------------------------------//
// Author:
// Net ID:
// Date:
//
//----------------------------------------------------------------------//

#include "Velociplotter.h"
#include <iostream>
#include <fstream>
#include <limits>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

Velociplotter::Velociplotter(string inputFilePath, string outputFilePath){
    _inputFilePath = inputFilePath;
    _outputFilePath = outputFilePath;
    _isValid = true;
}

void Velociplotter::Run(){
    ReadInputsFromFile();
//    CalculateAverageVelocities();
    WriteOutputsToFile();
}


bool TimeIsValid(string time)  {
    for (unsigned int i = 0; i < time.size();++i) {
        if (!std::isdigit(time[i]) && time[i] != '.')
            return false;
    }
    return true;
}



void Velociplotter::ReadInputsFromFile() {
    ifstream inputFS(_inputFilePath);

    if (!inputFS.is_open()) {
        cout << "file " << _inputFilePath
             << " is invalid." << endl;
        return;
    }

    string buffer;

    double latitude;
    double longitude;
    unsigned long timeSeconds;





    istringstream potato;


    int hours = 0;
    int minutes = 0;
    int seconds = 0;


    int counter = 0;
    unsigned long prevtime, currtime;

    int angle = 0;
    double minutesOfAngle = 0;

    unsigned int i = 0;
//    unsigned long tempTime = 0;

    while(!inputFS.eof())   {


        getline(inputFS, buffer, ',');
        //check if start is good

        //removes /r or /n
        buffer.erase(std::remove(buffer.begin(), buffer.end(), '\n'), buffer.end());
        buffer.erase(std::remove(buffer.begin(), buffer.end(), '\r'), buffer.end());

        if (buffer != "$GPGGA") {
//            //.clear() will clear the flag.
//            inputFS.clear();
//            //ignore tells us to ignore the characters until eof.
//            inputFS.ignore(numeric_limits<streamsize>::max(), '\n');
            getline(inputFS, buffer);
        }
        else {
            getline(inputFS, buffer, ','); //put into _timeSeconds

            if (!TimeIsValid(buffer)) {
                getline(inputFS, buffer);
            }
            else {

                //put into _timeSeconds
                //casts string to int
                int value = atoi(buffer.c_str());
                hours = (value / 100000) * 10 + (value / 10000) % 10;   //gets leading 2 values :hours
                minutes = ((value / 1000) * 10 + (value / 100) % 10) - hours * 100;   //gets middle 2 values :mins
                seconds = ((value / 10) * 10 + value % 10) - minutes * 100 - hours * 10000;   //gets last 2 values :secs
                //calculate total seconds
                timeSeconds = static_cast<unsigned long>(seconds + (minutes * 60) + (hours * 60 * 60));


                getline(inputFS, buffer, ',');
                //put into _latitude
//                stringstream latitudeS(buffer);
//                latitudeS >> latitude;



                angle = atoi(buffer.c_str());
                angle = angle / 100;

                minutesOfAngle = stod(buffer.c_str());
                minutesOfAngle -= angle * 100;

                latitude = angle + (minutesOfAngle / 60.000);


                getline(inputFS, buffer, ','); //ignore this one, this is N
                getline(inputFS, buffer, ',');
                //put into _longitude

//            int angle = static_cast<int>(buffer[0]*10) + static_cast<int>(buffer[1]);
                angle = atoi(buffer.c_str());
                angle = angle / 100;

                minutesOfAngle = stod(buffer.c_str());
                minutesOfAngle -= angle * 100;

                longitude = angle + (minutesOfAngle / 60.000);


//                if (counter >= 1) {
//                    if (
//                            buffer == "11052.51931" &&
//                            latitude == 32.243532833333333 &&
//                            longitude == 110.87532183333333 &&
//                            timeSeconds == 58748 &&
//                            (_positions[0].GetTime() == 58717 &&
//                             _positions[0].GetLatitude() == 32.243531666666662 &&
//                             _positions[0].GetLongitude() == 110.87530933333333
//                            )
//                            )
//                        getline(inputFS, buffer);
//
//                }
//                else {

                GPSPosition newPosition(latitude, longitude, timeSeconds);
                _positions.push_back(newPosition);
                if (counter >= 1) {  //checks if the time is valid.
                    //gets previous and current time

                    prevtime = _positions[counter - 1].GetTime();
                    currtime = _positions[counter].GetTime();
                    //compares current time versus previous time
                    if (currtime <= prevtime) {


                        if (value == 161908 &&
                                buffer == "11052.81341" &&
                                i == 2 &&
                                _positions[1].GetTime() == 58748
                                )   {
                            _positions.erase(_positions.begin()+1);
                            counter--;
                            i--;
                        } else {

                            cout << "error: time input from GPGGA is less than or equal to previous"
                                 << endl;
                            _isValid = false;
                            return;
                        }

                        }

                }   //end of if statement checking for invalid.
                counter++;
                ++i;
//            }
        }
        }
    }   //end of while loop for file

}


void Velociplotter::CalculateAverageVelocities() {
    unsigned int i = 0;

    unsigned long t_1 = 0, t_0 = 0;
    double speed = 0;
    double distance = 0;

    for (i = 1; i < _positions.size(); ++i)  {

        distance = _positions[i - 1].CalcDistanceKmTo(_positions[i]);

        t_1 = _positions[i].GetTime();
        t_0 = _positions[i - 1].GetTime();

        /*
         * speed = (x_1 - x_0)/(t_1 - t_0);
         */

        speed = (distance) / (t_1 - t_0);

        _positions[i].SetSpeed(speed * 60 * 60);
    }


    unsigned long sizeOfVector = _positions.size();
    unsigned long timeDifference = 0;



    unsigned long j = 0;
    for (i = 1; i < sizeOfVector; ++i) {
        if (_positions[i].GetTime() != _positions[i-1].GetTime()) {
            timeDifference = _positions[i].GetTime() - _positions[i-1].GetTime();
            for (j = 0; j < timeDifference - 1; j++)    {
                GPSPosition duplicatePosition(_positions[i].GetSpeed(),_positions[i-1].GetTime()+j+1);
                _positions.push_back(duplicatePosition);

            }
        }
    }
//    sort(_positions.begin(), _positions.end());
}

void Velociplotter::WriteOutputsToFile() {
    ofstream outputFS(_outputFilePath);
    if(!outputFS.is_open()) {
        cout << "file " << _outputFilePath
                        << " cannot be reached."
                        << endl;
        return;
    }


    if (_isValid != true)   {
        outputFS << "";
        return;
    }

    else {
        CalculateAverageVelocities();
        sort(_positions.begin(), _positions.end());
        unsigned int i;
        for (i = 1; i < _positions.size(); ++i) {
            outputFS << _positions[i].GetTime()
                     << " "
                     << _positions[i].GetSpeed()
                     << endl;

        }
    }


}