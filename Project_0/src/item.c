//----------------------------------------------------------------------//
// Author:         Garrett Vanhoy
// Net ID:         gvanhoy
// Date:           8/24/2017
// Project Number: 0
// Project Name:   ececms
//
// Contains the main function.
//----------------------------------------------------------------------//

#include "item.h"
#include <string.h>

/**
 * description: Creates a new item struct and returns it
 *
 * @requirement returns item with blank (strlen returns 0) name and 0.0 price if parameter price is negative
 * @requirement returns item with blank (strlen returns 0) name and 0.0 price if parameter name is blank
 * @param name is the name of the product
 * @param price is the price in USD
 * @return the new item struct
 */
item createItem(char name[], double price){
    
	if (strlen(name) == 0 || price < 0.0) {  //check condition for no name, or for negative price.


		item newItem = { .name = "", .price = 0.0}; //initialize a struct of type item with no name, and a price of 0.
/*
		item newItem[1];

		strcpy(newItem[0].name, "");
		newItem[0].price == 0;
*/
		return newItem;	//return the new struct
	}
	else
	{

		item newItem;		// = { .name = name, .price = price };

		strcpy(newItem.name, name);
		newItem.price = price;
/*
		item newItem[1];

		strcpy(newItem[0].name, name);
		newItem[0].price == price;
*/
		return newItem;
	}




/*
    item newItem;
    return newItem;
*/
}

/**
 * description: Calculates the total price of all items in an array.
 *
 * @requirement returns -1 if total is negative or if an item's name is blank
 * @param items is an array of item structs
 * @param numItems is the number of items in the items array
 * @return the total price
 */
double calculateTotal(item items[], int numItems){

	double sum = 0.0;
	int i = 0, k = 0;

	for (i = 0; i < numItems; ++i) {
		sum += items[i].price;
		if (strlen(items[i].name) == 0) {
			k = 1;
		}
	}

	if ((k == 1) || (sum < 0)) {
		return -1;
	} 
	else
	{
		return (sum);
	}
}