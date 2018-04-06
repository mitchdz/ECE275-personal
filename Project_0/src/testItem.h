//----------------------------------------------------------------------//
// Author:         Garrett Vanhoy
// Net ID:         gvanhoy
// Date:           8/24/2017
// Project Number: 0
// Project Name:   ececms
//
// Contains the main function.
//----------------------------------------------------------------------//

#ifndef ITEMTEST_H
#define ITEMTEST_H

#include <stdio.h>

void runTests();
unsigned int testCreateItem();
unsigned int testItemPriceIsPositive();
unsigned int testItemNameIsBlank();
unsigned int testTotalOneItem();
unsigned int testTotalTwoItems();
unsigned int testNegativeTotal();
unsigned int testBlankItemName();

#endif /* test_h */
