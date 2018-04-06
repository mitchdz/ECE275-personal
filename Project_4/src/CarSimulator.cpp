//----------------------------------------------------------------------//
// Author:
// Net ID:
// Date:
//
//----------------------------------------------------------------------//

#include "CarSimulator.h"
#include <limits>

using namespace std;

/**
 * Creates CarSimulator object
 *
 * @requirement assigns _inputFileName to object data members _inputFileName
 * @requirement assigns _outputFileName to object data members _outputFileName
 */
CarSimulator::CarSimulator(std::string _inputFileName, std::string _outputFileName){
    this->_inputFileName = _inputFileName;
    this->_outputFileName = _outputFileName;
}

/**
 * Populates object _commands data member from _inputFileName
 *
 * @requirement if the Command IsValid() returns false for any Command, the input file is invalidated. An output file still needs to be generated
 * @requirement if a line is not formatted correctly, the file is not invalidated. It is just discarded.
 * @requirement close the file at the end of the function
 */
void CarSimulator::ReadCommandsFromFile()   {
    ifstream ifSt;

    double tempTimeStamp = 0.0;
    double tempVel = 0.0;
    double tempTireAngle = 0.0;

    cout << "Opening file " << _inputFileName << endl;

    ifSt.open(_inputFileName);

    if(!ifSt.is_open()) {
        cout << "[_inputFileName::ReadCommands]Could not open ";
        cout << this->_inputFileName << endl;
    }

    Command newCommand;



//    string inputFromFile;
//    stringstream inputFromFileOSS;

        while (!ifSt.eof()) {
            ifSt >> tempTimeStamp >> tempVel >> tempTireAngle;
            if (ifSt.good()) {

                newCommand = Command(tempVel, tempTireAngle, tempTimeStamp);

                _commands.push_back(newCommand);

//                cout << "[READCOMMANDSFROMFILE] newCommand's values are: " << newCommand.GetTimeStamp() << ", " << newCommand.GetVelocity() << ", "<< newCommand.GetTireAngleRate() << endl;

                if (newCommand.IsValid() == false) {
                    cout << "No good!" << endl;
                    _commands.clear();
                    return;
                }
            }
            else {
                    ifSt.clear();
                    ifSt.ignore(numeric_limits<streamsize>::max(), '\n');
//                cout << "The file stream is incorrect." << endl;
            }
        }
    ifSt.close();
}

/**
 * Populates _stateHistory data member from already populated _commands by calling RunCommand on each command
 *
 * @requirement the last Command in _commands has a duration of .2 seconds
 * @requirement the calculated duration between each Command must be >= .005 seconds and <= .2 seconds otherwise, the whole set of _commands is invalidated. An output file should still be generated.
 */
void CarSimulator::RunAllCommands(){

    double timeBetween = 0.0;
    for (unsigned int i = 0; i < _commands.size() - 1; ++i) {

        timeBetween = _commands[i+1].GetTimeStamp() - _commands[i].GetTimeStamp();
            cout << "[RUNALLCOMMANDS] Time Differnece is " << timeBetween << " Wanted between 0.005 and .2" << endl;

        if (timeBetween >= .005 && timeBetween <= .2)   {
            RunCommand(_commands[i], timeBetween);
        }
        else    {
            _stateHistory.clear();
            cout << "[RUNALLCOMMANDS] " << "Clearing State History" << endl;
            return;
        }
    }
    RunCommand(_commands[_commands.size() - 1], 0.2);
}

/**
 * Adds a new State to _stateHistory given a Command and duration
 *
 * @requirement A new state is updated according to the following equations/pseudocode:
 *
 * x_pos = x_prev + duration*velocity*cos(tire_angle)*cos(heading)
 * y_pos = y_prev + duration*velocity*cos(tire_angle)*sin(heading)
 * tire_angle = tire_angle_prev + duration*tire_angle_rate
 * heading = heading_prev + duration*velocity*(1.0/L)*sin(tire_angle)
 * time_stamp = time_stamp_prev + duration
 *
 * @requirement all data members of the new State must be set with setters. Otherwise, bad things will happen.
 */
void CarSimulator::RunCommand( Command command, double duration ){

//    cout << "[RUNCOMMAND]Number of commands from runCommand is: " << this->_commands.size() << endl;
//    cout << "[RUNCOMMAND]Number of states from RunCommand is: " << this->_stateHistory.size() << endl;
    State newState;
    State oldState = GetCurrentState();
            //calculates the new Xposition
    newState.SetXPos(oldState.GetXPos() + command.GetVelocity()
                                          * duration * cos(oldState.GetTireAngle())
                                          * cos(oldState.GetHeading()));
            //calculates the new Yposition
    newState.SetYPos(oldState.GetYPos() + command.GetVelocity()
                                          * duration * cos(oldState.GetTireAngle())
                                          * sin(oldState.GetHeading()));
            //calculates the new tire_angle
    newState.SetTireAngle(oldState.GetTireAngle() + duration * command.GetTireAngleRate());
            //Calculates the new heading.
    newState.SetHeading(oldState.GetHeading() +
                                duration*command.GetVelocity()*(1.0/L) *
                                sin(oldState.GetTireAngle()));
            //Calculates the new timeStamp
    newState.SetTimeStamp(command.GetTimeStamp() + duration);

    _stateHistory.push_back(newState);
}

/**
 * Populates output file called _outputFileName with _stateHistory
 *
 * @requirement Each line in the output file should be formatted as follows:
 *
 * timestamp,x_pos,y_pos,tire_angle,heading
 *
 * All numbers are of type double.
 *
 * @requirement close the file when you are done.
 */
void CarSimulator::WriteStateHistoryToFile(){

    ofstream outputFile;
    outputFile.open(this->_outputFileName);

                cout << "opening file " << this->_outputFileName  << endl;

    if(!outputFile.is_open())   {
        cout << "[WriteStatEHistoryToFile]Could not open ";
        cout << this->_outputFileName << endl;
        return;
    }
    unsigned int numStates = this->_stateHistory.size();

                cout << "[WRITESTATES]The number of states is: " << this->_stateHistory.size() << endl;

//    ostringstream outputFileOSS;

    for(unsigned int i = 0; i < numStates; ++i)  {

        outputFile << _stateHistory.at(i).GetTimeStamp()
                   << ","
                   << _stateHistory.at(i).GetXPos()
                   <<","
                   << _stateHistory.at(i).GetYPos()
                   <<","
                   << _stateHistory.at(i).GetTireAngle()
                   <<","
                   << _stateHistory.at(i).GetHeading()
                   <<endl;


//        outputFile << outputFileOSS.str();


    }

    outputFile.close();
}

/**
 * Returns the most recent state to be used in RunCommand()
 *
 *
 * @requirement if _stateHistory is empty, return default state (all data members are 0.0), otherwise return the last state in _stateHistory
 */
State CarSimulator::GetCurrentState(){
    State emptyState = State();

    if(_stateHistory.empty())
        return emptyState;
    else
        return _stateHistory.back();
}

