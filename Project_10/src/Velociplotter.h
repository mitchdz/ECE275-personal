//----------------------------------------------------------------------//
// Author:
// Net ID:
// Date:
//
//----------------------------------------------------------------------//

#ifndef VELOCIPLOTTER_H
#define VELOCIPLOTTER_H

#include "GPSPosition.h"
#include <string>
#include <vector>


class Velociplotter{
private:
    std::string _inputFilePath;
    std::string _outputFilePath;
    std::vector<GPSPosition> _positions;
    bool _isValid;

public:
    Velociplotter(std::string inputFilePath, std::string ouputFilePath);
    void Run();
    void ReadInputsFromFile();
    void CalculateAverageVelocities();
    void WriteOutputsToFile();
};
#endif


