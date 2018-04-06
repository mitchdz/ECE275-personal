//----------------------------------------------------------------------//
// Author:
// Net ID:
// Date:
//
//----------------------------------------------------------------------//

#include "card.h"
#include <iostream>

using namespace std;

/**
 * Description: Parse a line from a file and create a card
 *
 * @param lineFromFile A string from a file
 *
 * @requirement carriage returns "\r" and newlines "\n" must be removed
 * @requirement a valid blank is at least three consecutive underscores
 * @requirement blankLength and blankIndex are zero if a valid blank is not found
 * @requirement blankIndex is the index that makes card->GetContent()[card->blankIndex] be the first underscore
 * @requirement blankLength is the number of underscores in the blank
 *
 */
Card::Card(string lineFromFile){

    for (unsigned int i = 0; i < lineFromFile.size(); i++)   {
        if (lineFromFile[i] == '\n' || lineFromFile[i] == '\r')
                lineFromFile.erase(i);
    }


    _content = lineFromFile;


    int j = 0;
    unsigned int counter = 0;

    for (unsigned int i = 0; i < _content.size();++i)    {  //starts a loop to look through the string.
        if (_content[i] == '_') {
                counter = 0;
                j = i;
            while (_content[j] == '_')  {
                counter++;
                ++j;
            }

            if (counter > 2)    {
                _blankIndex = i;
                _blankLength = counter;
                return;
            }
        }
    }
    _blankIndex = 0;
    _blankLength = 0;
}

/**
 * Description: Replace a blank in a card with content from a Word object
 *
 * @param word Word with which to replace the blank inside the card
 *
 * @requirement Card _content has its blank replaced with the _content of word
 *
 */
void Card::ReplaceBlanks(Word word){
    for(unsigned int i = 0; i < _blankLength;++i)   {
        _content[_blankIndex + i] = word.GetContent().at(i);
    }
}

/**
 * Validate Card
 *
 * @requirement blankLength must be at least 3
 *
 */
bool Card::IsValid() {
    return (_blankLength >= 3);
}

/**
 * Description: < operator overload
 *
 * @requirement return false if _content length of current Card is less than content of rhs
 *
 * @note This is necessary in order to use the .sort() function on a list properly
 */
bool Card::operator<(const Card& rhs) const{
//    return _content.size() >= rhs.GetContent().size();

    if (_content.length() < rhs.GetContent().length())  {
        return true;
    }
    else    {
        return false;
    }
}
