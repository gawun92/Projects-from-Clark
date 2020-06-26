// Name : Gawun Kim
// Class: CSE 222(Nick Macias)
// Date : Mar/15/2018
// Program assignment 5
// No parter
// main.c
// Description : This program requires the user to type some number and this number would be the bag's cappacity(weight). All the products' list is written into 'knapsack.data. This program reads that list and show the best possibility to be able to put. The heaviest product would be put as many as possible, second heaviest,.... and the last one. Also, depends on the possibility, the total value of products would be calculated and the number would be shown. For the last line, the line shows the products that are inside of the bag.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "functions.h"
int main(int argc, char *argv[]){



FILE *file = fopen("knapsack.data","r"); //read the data from  knapsack.data
	  if (file == NULL){ //if the file is equla to NULL then the file cannot be opened
	    fprintf(stderr,"Coudn't open the file\n");
	    return -1;
	  }
 char buffer[120];

	while (fgets(buffer,120,file) != NULL){ //get the list from knapsack.data
	  int value;
          int weight;
          char description[120];
                if(sscanf(buffer,"%d %d %s",&weight,&value,description) >= 3){  //checking the list is in the right format and scaning itto buffer.
                        items[tail].weight = weight;                            //go throught all the weights in the list and saves it to weight
                        items[tail].value = value;                             //go through all the values' in the list and save it to value
                        strcpy(items[tail].description,description); //go through all the descriptions in the list and saves it to description
                        tail++; //increasing the # of tail
                }
		else{
                        fprintf(stderr,"Invalid line: %s", buffer); //if there is any incorrent format in knapsack.data file
                        printf("Please make sure your file is formatted in the following format:\n");
                        printf("[weight] [value] [description of the item]\n");
                        return -1;
                }
        }


        if (argc == 2){ //checks that there is a second argument

		int i;
	 	int answer = sscanf(argv[1], "%d", &i);

		if(i <0 ){		// if insert negative number
		printf("Illegal capacity: should be between 1 and 1024\n");
		return -1;
		}

		if(answer != 1){	// if insert non-number
		printf("Usage: pa5sample capacity\n");
		return -1;
		}


		if ( atoi(argv[1]) >= 1025 ){	//if insert too big number

        	   printf("It is too big size\n");
   		   printf("Illegal capacity: should be between 1 and 1024\n");
       		   return -1;
       		 }


				printf("  item   Weight  Value    Name\n");
        	            	printf("  ----   ------  -----    ----\n");

                for(int i=0;i<tail;i++){ //  print each of lines from the file
                        printf("   %d      %d      %d      %s\n",i,items[i].weight,items[i].value,items[i].description);
		
                }
                int n = strtol(argv[1],NULL,10); //converting the second argument from a char to a integer
		printf("Bag's capacity=%s\n", argv[1]);
                printf("Highest possible value=%d\n",maxVal(n)); // printing for the highest possible value
                printList(n); //print the items into bag
        }else{
                fprintf(stderr,"No weight was typed!\n"); // if the user did not type any input 
        }
}

