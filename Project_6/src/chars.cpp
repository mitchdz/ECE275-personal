//----------------------------------------------------------------------//
// Author:
// Net ID:
// Date:
//
//----------------------------------------------------------------------//

#include <fstream>
#include <iostream>
#include <algorithm>
#include "word.h"
#include "chars.h"
//#include <iterator>

using namespace std;

/**
 * Description: constructor for Chars
 *
 * @param string wordsFilePath relative path of file to get Word information
 * @param string cardsFilePath relative path of file to get Card information
 * @param string outputFilePath relative path of file to write processed cards information
 *
 * @requirement assign parameters to Chars data members of similar name
 */
Chars::Chars(std::string wordsFilePath, std::string cardsFilePath, std::string outputFilePath){

    _wordFilePath = wordsFilePath;
    _cardFilePath = cardsFilePath;
    _outputFilePath = outputFilePath;


}

/**
* Description: Read Cards from a File
*
*
* @requirement output error if _cardsFilePath cannot be opened
* @requirement populate _cards list in the order they are found in the file
* @requirement Every line in the _cardsFilePath is used to create a new Card object using the Card constructor
* @requirement A Card is added to the _cards list only if the Card is valid
* @requirement close the file stream when you are done.
*
*/
void Chars::ReadCardsFromFile() {

    ifstream cardsFilePath;
    cardsFilePath.open(_cardFilePath);

    string line;


    if (!cardsFilePath.is_open()) {
        cout << "Yo diggity dog, we got ourselves an issue." << endl;
        return;
    }


    while (!cardsFilePath.eof()) {
        getline(cardsFilePath, line);

        Card tempCard(line);

        if (tempCard.IsValid())
            _cards.push_back(tempCard);
    }

    cardsFilePath.close();
}

/**
 * Description: Read Word from a File
 *
 *
 * @requirement output error if _wordsFilePath cannot be opened
 * @requirement populate _words list in the order they are found in the file
 * @requirement Every line in the _wordsFilePath is used to create a new Word object using the Word constructor
 * @requirement A Word is added to the _words list only if the Word is valid
 * @requirement close the file stream when you are done.
 *
 */
void Chars::ReadWordsFromFile() {


    ifstream cardsFilePath;
    cardsFilePath.open(_wordFilePath);

    string line;


    if (!cardsFilePath.is_open()) {
        cout << "Yo diggity dog, we got ourselves an issue." << endl;
        return;
    }

    while (!cardsFilePath.eof()) {
        getline(cardsFilePath, line);

        Word tempCard(line);

        if (tempCard.IsValid())
            _words.push_back(tempCard);
    }

    cardsFilePath.close();

}

/**
 * Description: Uses _cards and _words lists to populate blanks inside of Card
 * objects in _cards with Word objects in _words
 *
 * @requirement attempt to fill all blanks in the Card objects in _cards with
 * the content of a Word object in _words with the same length as the blank
 * ReplaceBlanks should be used for replacing blanks
 *
 * @requirement If no Word object in _words is of the correct size for a Card object in _cards, then the Card object is removed from _cards using the erase function of the list<> type
 *
 * @requirement Once a Word in _words is used to replace a blank in a Card object in _cards, it is removed from _words using the erase function of the list<> type
 *
 */
void Chars::ProcessCards() {

    list<Card>::iterator CardIterator;
    list<Word>::iterator WordIterator;
    int i = 0;

    CardIterator = _cards.begin();

    while ((CardIterator != _cards.end()) )   {
            i = 0;
            WordIterator = _words.begin();

            while (WordIterator != _words.end()) {
                if (WordIterator->GetContent().length() == CardIterator->GetBlankLength()) {
                    CardIterator->ReplaceBlanks(WordIterator->GetContent());

                   WordIterator=_words.erase(WordIterator);
                    i = 1;
                    break;
                }
                ++WordIterator;
            }
                    if (i == 0) {
                    CardIterator = _cards.erase(CardIterator);

                } else{
                    ++CardIterator;
                }

    }
}

/**
 * Description: Write Cards that have blanks fill   ed with Words to _outputFilePath
 *
 * @requirement output error if _outputFilePath cannot be opened
 * @requirement The _cards list must be sorted according to the length of the card from shortest to longest.
 * if the < operator is properly overloaded, this can be done by calling .sort() on a list
 *
 * @requirement Each Card object in _cards must be output on a new line with a carriage return ("\r\n") at the end
 * @requirement close the file stream when you are done.
 *
 */
void Chars::WriteCardsToFile() {

    ofstream outputFileStream;

    outputFileStream.open(_outputFilePath);

    if (!outputFileStream.is_open()) {
        cout << "Yo diggity dog, we got ourselves an issue." << endl;
        return;
    }

    _cards.sort();

    _List_iterator<Card> tempCard;

    for (tempCard = _cards.begin(); tempCard != _cards.end(); ++tempCard)   {
        outputFileStream << tempCard->GetContent() << "\r\n";
    }


    outputFileStream.close();

}
