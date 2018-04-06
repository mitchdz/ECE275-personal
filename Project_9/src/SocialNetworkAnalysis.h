//----------------------------------------------------------------------//
// Author:
// Net ID:
// Date:
//
//----------------------------------------------------------------------//

#ifndef SOCIALNETWORKANALYSIS_H
#define SOCIALNETWORKANALYSIS_H

#include <string>
#include "SocialNetwork.h"
#include <list>
#include <vector>

class SocialNetworkAnalysis{
private:
    std::string _inputFilePath;
    std::string _outputFilePath;
    SocialNetwork _socialNetwork;

public:
    SocialNetworkAnalysis(std::string inputFilePath, std::string ouputFilePath);
    void Run();
    void ReadFromFile();
    void PrintSuggestions();
    void SortUsers();

};
#endif /* SocialNetworkAnalysis_hpp */
