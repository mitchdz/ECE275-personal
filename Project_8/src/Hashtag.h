//----------------------------------------------------------------------//
// Author:
// Net ID:
// Date:
//
//----------------------------------------------------------------------//


#ifndef HASHTAG_H
#define HASHTAG_H

#include <string>

class Hashtag {
private:
    std::string _word;                // The hashtag itself
    int _startCount;         // Number of occurrences in start file
    int _endCount;           // Number of occurrences in end file
    unsigned int _startRank;          // Rank in start file
    unsigned int _endRank;            // Rank in end file
    int _sumRank;            // starting rank - ending rank


public:
    std::string GetWord() const { return _word; };
    int GetStartCount() const { return _startCount; };
    int GetEndCount() const { return _endCount; };
    int GetStartRank() const { return _startRank; };
    int GetEndRank() const { return _endRank; };
    int GetSumRank() const { return _sumRank; };
    void SetStartRank(int rank) { _startRank = rank; };
    void SetEndRank(int rank) { _endRank = rank; };
    void SetSumRank(int rank) {_sumRank = rank; };
    void IncrementStartCount() { _startCount++; };
    void DecrementStartCount() { _startCount--; };
    void IncrementEndCount() { _endCount++; };
    void DecrementEndCount() {_endCount--;  };
    Hashtag(std::string);
    bool operator<(const Hashtag& rhs) const;

};

#endif // HASHTAG_H
