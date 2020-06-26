// Name : Gawun Kim
// Class: CSE 222(Nick Macias)
// Date : Mar/15/2018
// Program assignment 5
// No parter
// functions.h
// Description : This program requires the user to type some number and this number would be the bag's cappacity(weight). All the products' list is written into 'knapsack.data. This program reads that list and show the best possibility to be able to put. The heaviest product would be put as many as possible, second heaviest,.... and the last one. Also, depends on the possibility, the total value of products would be calculated and the number would be shown. For the last line, the line shows the products that are inside of the bag.


#ifndef _FUNCTIONS_H
#define _FUNCTIONS_H
#include <stdio.h>
#include <string.h>
struct item{
        int weight;
        int value;
        char description[30];
};
        struct item items[128];
int tail;
int maxVal(int n);
void printList(int n);

#endif

