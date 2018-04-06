Author: <br>
NetID: <br>
Date: <br>
Project Name: project_7 <br>
Course Name: ece275 <br>

# Project 6: Chars
## High-Level Description
The chars program fills in blank strings in an input card file with an appropriate string from input strings file, and writes the results to an output file.

## Chars Against Formatting
The popular game *Cards Against Humanity* is a horrible game, for horrible people. This assignment, fortunately, can be carried out without playing that horrible game (for horrible people). One interesting aspect of that game, however, is that it is available under a Creative Commons BY-NC-SA 2.0 license. That means you can use, remix, and share the game for free, but you can’t sell it without their permission. They kindly asked “Please do not steal our name or we will smash you.” So we haven’t. *chars Against Formatting* is not based on any single game, but any resemblance to games, living or dead, is not just a coincidence.
This assignment requires you to take a card, which is a string with one blank in it, and inserts into those blank spaces an appropriate **Word** from a second file. A blank is represented as sequence of consecutive underscores. For example, consider the following **Card**:

This assignment requires you to take a **Card**, which is a string with one blank in it, and inserts into those blank spaces an appropriate **Word** from a second file. A blank is represented as sequence of consecutive underscores. For example, consider the following **Card**:

> A Lannister _ _ _ _ _ _ pays his debts.

The blank here is a sequence of 6 consecutive underscore characters. Consider the below list of **Word**s:

* Tarth
* spoiler
* always
* Winter
* never

Your program should look through this list until it finds the **first** string with the same length as the blank, i.e., a length of 6, and output a processed **Card** by replacing the blank with that **Word**. In this example, since always is the first string of length 6, the processed **Card** is:

> A Lannister always pays his debts.

If no matching **Word** is found, then no processed **Card** should be written to the output file. The **Word** used in that processed **Card** is removed from the list of **Word**s. In the above example, *always* is removed from the list of **Word**, resulting in:

* Tarth
* spoiler
* Winter
* never

## The std::list<> class
The std::list<> class is part of the C++ Standard Template Library (STL) and is a doubly-linked list. We have yet to cover how to use these in detail, but they are similar to vectors in some ways. Please use the [CPlusPlus API Reference](http://www.cplusplus.com/reference/list/list/) to familiar yourself with some of the functions. With the std::list<>, adding elements to the list is still done using push_back(). The biggest difference with lists than with std::vector is how to iterate. There are two main ways used to iterate in a list.

```cpp
std::list<Card>::iterator card = _cards.begin() // Create an iterator object
while(card != _cards.end()){ // keep iterating until we hit the end
    card++;
}
```

and

```cpp
for( std::list<Card>::iterator card = _cards.begin(); card != _cards.end() ; card++){

}
```

One of these two structures are better for when we intend to delete items from a list as we iterate and it is left up to you to figure this out.
## Input Card File
The inputCardsFile is formatted according to the following specifications:

### Formatting

1. It is a plain-text file with lines up to 1024 characters in length. Each line has a new line or carriage return ("\r\n") at the end.
2. Every line represents the _content of a new Card.
2. A card may have whitespace, punctuation, numbers, etc., in its _content.
3. Valid blanks may or may not have spaces on either or both sides in the character array.
4. A blank is a consecutive sequence of the character ‘_’ that is of length 3 or longer.
5. If a card does not contain a valid blank is should have its _blankLength and _blankIndex set to 0.
6. Not every line from the input file is guaranteed to have a blank (i.e., a sequence of underscore characters) in it.
7. All valid **Card**s should be added to the Chars _cards list.

### Parsing
The cardsFilePath should be parsed according to the following specifications:

1.    Any line with no content can be skipped.
2.    Duplicate cards are permitted in the cardsFilePath.
3.    As always, your program should be robust to files that are empty, or that do not match the input formats.

## Input Word File
The wordsFilePath is formatted according to the following specifications:

### Formatting
1.    It is a plain-text file with **whitespace** separated strings.
2.    Any line with no content can be skipped.
3.    Any line with fewer than 3 characters should not be added to the list of **Word**s.
4.    **Word**s can be any valid ASCII string of alphanumeric or punctuation characters (i.e., isalnum() or ispunct() returns true).
5.    **Word**s can consist of values that seem like another type (e.g., integer and floating-point).
6.    Duplicate **Word**s are permitted in wordsFilePath and the list _words.
7.    **Word** in the wordsFilePath will never contain special characters (e.g., underscores, dashes).

### Parsing
The wordsFilePath should be parsed according to the following specifications:
1.    Each valid **Word** read from the **Word** file will be stored in _words.
2.    Invalid **Word**s should not be added to the list of strings (neither isalnum() or ispunct() returns true).
3.    **Word**s containing values that seem like another type should be read in as std::strings, not numeric values.

## Output File

The outputFile should be formatted according to the following specification.
1.    It is a plain-text file that will consist of all successfully processed cards.
2.    Each processed card should be written to the outputFilePath followed by a carriage return ("\r\n").
3.    If _cards is empty after processing, your program should create an empty output file with name provided through the Chars constructor
4.    The _cards list should be ordered by length using the list .sort() function before outputing to the output file (from shortest to longest).
5.    If two processed cards have the same length, then the one that appears first in the cardsFilePath should be written first to the outputFilePath.


