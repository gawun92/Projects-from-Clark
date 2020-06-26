// Name : Gawun Kim
// Class: CSE 222(Nick Macias)
// Date : Mar/15/2018
// Program assignment 5
// No parter
// functions.c
// Description : This program requires the user to type some number and this number would be the bag's cappacity(weight). All the products' list is written into 'knapsack.data. This program reads that list and show the best possibility to be able to put. The heaviest product would be put as many as possible, second heaviest,.... and the last one. Also, depends on the possibility, the total value of products would be calculated and the number would be shown. For the last line, the line shows the products that are inside of the bag.



#include "functions.h"
int bestValue[1024] = {0};
int bestItem[1024] = {0};
int count[1024] = {0};
// It finds the maximum possibility for the items to be put. 
int maxVal(int n){
        int best = 0;
        int total = 0;
        if(bestValue[n]>0){
                return(bestValue[n]);
        }
        for(int i=0;i<tail;i++){
                if(n>=items[i].weight){
                        total = items[i].value + maxVal(n-items[i].weight);
                }
                if(total > best){
                        best = total;
                        bestItem[n] = i;
                }
        }
        bestValue[n] = best;
        return(best);
}
//The printList shows itemlist into bag.
void printList(int n){
        if (n <= 0){
	for (int j = 0; j < 1024; j++){
			if ( count[j] != 0)
				printf( "Item %d (%s) : %d\n", j , items[j].description , count[j] );
		}
                return;
        }
        int i = bestItem[n];
	count[i]++;
	printList(n-items[i].weight);	//it would make keeping go through the function unless n <= 0
}
