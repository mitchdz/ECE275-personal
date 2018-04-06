//----------------------------------------------------------------------//
// Author:
// Net ID:
// Date:
//
//----------------------------------------------------------------------//

#include <iostream>
#include "testChars.h"
#include "word.h"
#include "card.h"

using namespace std;

void CharsTester::RunTests() {
    testConstructWordWithCarriageReturn();
    testConstructWordWithNewLine();
    testIsWordValidWithSpace();
    testIsWordValidPercentSign();
    testIsWordValidShortWord();
    testConstructCardWithCarriageReturn();
    testConstructCardWithNewLine();
    testIsCardValidNoBlank();
    testIsCardValidShortBlank();
    testCorrectBlankLengthAndIndex();
    testCardIsLessThan();
}

/*
 * @requirement pass if "\r\n" is discarded by Word constructor
 * @return pass: true, fail: false
 */
bool CharsTester::testConstructWordWithCarriageReturn() {

    string testString = "This is a test file \r\n";

    Word testWord(testString);
    string testStringAfter = testWord.GetContent();

    return !(testStringAfter[testStringAfter.size() - 2] == '\r'
             && testStringAfter[testStringAfter.size() - 1] == '\n');

}

/*
 * @requirement pass if "\n" is discarded by Word constructor
 * @return pass: true, fail: false
 */
bool CharsTester::testConstructWordWithNewLine() {

    string testString = "This is a test string \n";

    Word testWord(testString);
    string testStringAfter = testWord.GetContent();

    return testStringAfter[testStringAfter.size() - 1] != '\n';
}

/*
 * @requirement pass if Word created using constructor with string that has a space is considered invalid
 * @return pass: true, fail: false
 */
bool CharsTester::testIsWordValidWithSpace() {
    string testString = "This is a string with a space";
    Word testWord(testString);

    return !testWord.IsValid();
}

/*
 * @requirement pass if Word created using constructor with string that has a percent sign is considered valid
 * @return pass: true, fail: false
 */
bool CharsTester::testIsWordValidPercentSign() {
    string testString = "Thisisastringwitha%sign";

    Word testWord(testString);

    if (testWord.IsValid() == true)
            return true;
    else
        return false;


}

/*
 * @requirement pass if Word created using constructor with string that is less than 3 characters is considered invalid
 * @return pass: true, fail: false
 */
bool CharsTester::testIsWordValidShortWord() {
    string testString = "Th";
    Word testWord(testString);

    return !testWord.IsValid();
}

/*
 * @requirement pass if "\r\n" is discarded by Card constructor
 * @return pass: true, fail: false
 */
bool CharsTester::testConstructCardWithCarriageReturn() {

    string testString = "This is a test string\r\n";

    Card testCard(testString);

    string testStringAfter = testCard.GetContent();

    return !(testStringAfter[testStringAfter.size() - 2] == '\r'
             && testStringAfter[testStringAfter.size() - 1] == '\n');
}

/*
 * @requirement pass if "\n" is discarded by Card constructor
 * @return pass: true, fail: false
 */
bool CharsTester::testConstructCardWithNewLine() {

    string testString = "This is a test string\n";

    Card testCard(testString);

    string testStringAfter = testCard.GetContent();
    return testStringAfter[testStringAfter.size() - 1] != '\n';
}

/*
 * @requirement pass if Card created using constructor with string that has no underscores is invalid
 * @return pass: true, fail: false
 */
bool CharsTester::testIsCardValidNoBlank() {

    string testString = "This is a string with no underscores.";
    Card testCard(testString);

    return !testCard.IsValid();
}

/*
 * @requirement pass if Card created using constructor with string that has a blank that is only two characters long is invalid
 * @return pass: true, fail: false
 */
bool CharsTester::testIsCardValidShortBlank() {

    string testString = " a";
    Card testCard(testString);
    return !testCard.IsValid();
}

/*
 * @requirement pass if blankLength and blankIndex is correct in properly formatted Card object with a blank yet to be filled.
 * @return pass: true, fail: false
 */
bool CharsTester::testCorrectBlankLengthAndIndex() {
    string testString = "this is a ___ good sentence ___ ";

    Card* testCard;
    testCard = new Card(testString);


if ((testCard->GetBlankIndex() == 10) && (testCard->GetBlankLength() == 3))
            return true;
    else
        return false;
}

/*
 * @requirement pass if Card with contents that have fewer characters than another Card is considered "less than"
 * @return pass: true, fail: false
 */
bool CharsTester::testCardIsLessThan() {
    string test1String = "I HAVE MORE CHARACTERS HAHAHAHAHAHAHAHA";
    string test2String = ":(";

    Card test1Card(test1String);
    Card test2Card(test2String);

    if ((test2Card < test1Card) == true)
            return true;
    else
        return false;






}

