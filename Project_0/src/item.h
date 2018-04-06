//----------------------------------------------------------------------//
// Author:         Garrett Vanhoy
// Net ID:         gvanhoy
// Date:           8/24/2017
// Project Number: 0
// Project Name:   ececms
//
// Contains the main function.
//----------------------------------------------------------------------//

#ifndef ITEM_H
#define ITEM_H

#include <stdlib.h>
#include <stdio.h>

typedef struct item_struct{
    char name[50];
    double price;
} item;

item createItem(char name[], double price);
double calculateTotal(item items[], int numItems);

#endif // PROCESS_H
