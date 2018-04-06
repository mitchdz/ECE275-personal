//----------------------------------------------------------------------//
// Author:         Mitchell Dzurick
// Net ID:         mitchdz
// Date:           9/7/2017
// Project Number: 0
// Project Name:   ececms
//
// Contains the main function.
//----------------------------------------------------------------------//

#include "item.h"
#include "testItem.h"
#include <string.h>

void runTests(){
    testCreateItem();
    testItemPriceIsPositive();
    testTotalOneItem();
    testTotalTwoItems();
    testNegativeTotal();
}

/*
 * @requirement pass if all items are set to correct values
 * @return pass: 1, fail: 0
 */
unsigned int testCreateItem(){
	item newItem = createItem("Apple", .50);

	if (strcmp(newItem.name, "Apple") == 0 && newItem.price == .50) {
		printf("Test #1 passed successfully!");
		return 1;
	}
	else
	{
		return 0;
	}
    return 0;
}

/*
 * @requirement pass if the name of the item returned is blank (strlen is 0) and price is 0.0 when name passed to createItem is blank
 * @return pass: 1, fail: 0
 */
unsigned int testItemNameIsBlank(){
    
	item newItem = createItem("", 0.50);

	if (strlen(newItem.name) == 0 && newItem.price == 0.0) {
		return 1;
	}
	else {
		return 0;
	}
}

/*
 * @requirement pass if the name of the item returnd is blank (strlen is 0) and price is 0.0 when price passed to createItem is negative
 * @return pass: 1, fail: 0
 */
unsigned int testItemPriceIsPositive(){
	item newItem = createItem("", -.50);

	if (strlen(newItem.name) == 0 && newItem.price == 0.0) {
		printf("Test successfully passed when there is no name, and a negative price!");
		return 1;
	}
	else
	{
		return 0;
	}

    return 0;
}

/*
 * @requirement pass if total returned from calculateTotal is correct when a single item array is passed in
 * @return pass: 1, fail: 0
 */
unsigned int testTotalOneItem(){

	item items[1];  //initialize an array of items

	strcpy(items[0].name, "potato");
	items[0].price = 1.0;

	if (calculateTotal(items, 1) == items[0].price) {
		return 1; //if the sum matches, pass the test
	}
	else
	{
		return 0;
	}
}

/*
 * @requirement pass if total returned from calculateTotal is correct when a two item array is passed in
 * @warning using createItem in this function is not a good idea because each unit test should only test ONE function.
 * @return pass: 1, fail: 0
 */
unsigned int testTotalTwoItems(){
	item items[2]; // initialize an array of items

	strcpy(items[0].name, "potato");
	strcpy(items[1].name, "Apple");

	items[0].price = 1.0;
	items[1].price = 2.0;

	if (calculateTotal(items, 2) == (items[0].price + items[1].price)) {
		printf("Test successfully passed when finding the sum of the items.");
		return 1;
	}
	else
	{
		return 0;
	}
}

/*
 * @requirement pass if total returned from calculateTotal is -1.0 when the total price is negative
 * @warning using createItem in this function is not a good idea because each unit test should only test ONE function.
 * @return pass: 1, fail: 0
 */
unsigned int testNegativeTotal(){
    
	item items[1];

	strcpy(items[0].name, "Apple");
	items[0].price = -2.0;

	if (calculateTotal(items, 1) == -1.0) {
		printf("testNegativeTotal unit test passed successfully!");
		return 1;
	}
	else
	{
		return 0;
	}

}

/*
 * @requirement pass if total returned from calculateTotal is -1.0 when one item's name is blank
 * @warning using createItem in this function is not a good idea because each unit test should only test ONE function.
 * @return pass: 1, fail: 0
 */
unsigned int testBlankItemName(){
    
	item items[2];

	strcpy(items[0].name, "potato");
	strcpy(items[1].name, "");

	items[0].price = 1.0;

	if (calculateTotal(items, 2) == -1.0) {
		return 1;
	}
	else
	{
		return 0;
	}
}
