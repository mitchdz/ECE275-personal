//----------------------------------------------------------------------//
// Author:
// Net ID:
// Date:
//
//----------------------------------------------------------------------//


#ifndef TRENDING_H
#define TRENDING_H

#include <string>
#include "Hashtag.h"
#include <list>
#include <vector>


class Trending{
private:
    std::string _startHashtagFilePath;
    std::string _endHashtagFilePath;
    std::string _outputHashtagFilePath;
    std::vector<Hashtag> _Hashtags;
public:
    Trending(std::string startHashtagFilePath, std::string endHashtagFilePath, std::string outputHashtagFilePath);
    void Run();
    void ReadHashtagsFromFile();
    void ProcessHashtags();
    void CalculateSum();
    void WriteHashTagsToFile();

};
#endif /* Trending_hpp */
