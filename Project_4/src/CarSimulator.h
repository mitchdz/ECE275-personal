//----------------------------------------------------------------------//
// Author:
// Net ID:
// Date:
//
//----------------------------------------------------------------------//
#ifndef VEHICLE_H
#define VEHICLE_H

#include "State.h"
#include "Command.h"
#include <vector>
#include <string>
#include <fstream>
#include <iostream>

// wheelbase length in meters
#define L 2.6187

class CarSimulator {
private:
    std::vector<State> _stateHistory;
    std::vector<Command> _commands;
    std::string _inputFileName;
    std::string _outputFileName;
    
public:
    CarSimulator(std::string _inputFileName, std::string _outputFileName);
    void ReadCommandsFromFile();
    void RunAllCommands();
    void RunCommand( Command command, double duration );
    State GetCurrentState();
    void WriteStateHistoryToFile();
};

#endif // VEHICLE_H
