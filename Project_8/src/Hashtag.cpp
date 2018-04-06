//----------------------------------------------------------------------//
// Author:
// Net ID:
// Date:
//
//----------------------------------------------------------------------//


#include "Hashtag.h"

using namespace std;


Hashtag::Hashtag(std::string word)   {
    _word = word;
    _startCount = 0;
    _endCount = 0;
    _endRank = 0;
    _sumRank = 0;
}

bool Hashtag::operator<(const Hashtag& rhs) const {
/*    The cases for each statement to make this true is as follows:
 *    The lefthand side (lhs) **Hashtag** is less than the righthand (rhs) if (all string comparisons are case insensitive):
 *    1.    If the rhs' end count is less than the lhs end count
 *    2.    If the rhs' end count is equal to the lhs' end count, and both end counts are not 0, and the lhs' word is less than rhs' word alphabetically
 *    3.    If both the rhs' and the lhs' end counts are 0, and the rhs' start count is less than the lhs' start count
 *    4.    If both the rhs' and lhs' end counts are 0, and the rhs' start count is equal to the lhs' start count,
 *             and the lhs' word is less than the rhs' word alphabetically
 */
            //first case
    if (rhs.GetEndCount() < this->_endCount)
        return true;
            //second case
    if (rhs.GetEndCount() == this->_endCount &&
             (rhs.GetEndCount() != 0 && this->_endCount != 0)
              && (this->_word < rhs.GetWord())) {
        return true;
    }
            //third case
    if ((this->_endCount == 0 && rhs.GetEndCount() == 0) &&
            rhs.GetStartCount() < this->_startCount)
        return true;
            //fourth case
    if ((this->_endCount == 0 && rhs.GetEndCount() == 0)
        && (rhs.GetStartCount() == this->_startCount)
        && (this->_word < rhs.GetWord())
            )
        return true;
    return false;   //default result if no condition is met.
    }
