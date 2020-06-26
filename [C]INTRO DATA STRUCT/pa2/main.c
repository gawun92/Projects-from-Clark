// Name  : Gawun Kim
// Class : CSE 222(DATA STRUC)
// DATE  : 02/FEB/ 2018 Winter
// Program Assignment 2
// Description : This assignment is one part of PA2. In pa2, I expect the result to be shown some input numbers and input numbers can delete, add, and print. Also, all this things are based on node: next and data. This file is main.c file and this is everyting that we need to deal with the node system except link-list. The list is connected with this file by using "#include"link_list.h"".
 

#include<stdio.h>
#include "link_list.h"  // I already typed some codes in link_list.h file and it is ued in this program

int main(){
	struct node *list = init();
	char buffer[255];
	int num;
	int done = 0;

while(!done){	// it will be keep working until done =1 and the value of done would be changed when insert 'x'
	 printf("> ");
	 fgets(buffer,255,stdin);   // This is array for command line
				
	if (buffer[0] == 'i'){   // This is for inserting
	
		if (parse(buffer,&num)){	// This is for checking proper inserting format.
			if(!search(list,num)){  // if num is not in the list.
				add(list,num);  // insert a num into list and it is from link_list.h
				printf("SUCCESS INSERTED\n");
			}
			else{			// if the number is already in the list.
				printf("THIS IS ALREAD IN THE LIST\n");
			}
		}
		else{  // If input does not have a proper inserting format.
			printf(" Enter these following commands\n");
			printf(" i 'number'   insert\n");
			printf(" d 'number'   delete\n");
			printf(" s 'number'   search\n");
			printf(" p            print the list\n");
			printf(" x            exit program\n");
		}	
	  
	}


        else if (buffer[0] == 'd'){  // This is deleting
                if (parse(buffer,&num)){ // checking proper format

                        if (search(list,num)){	// if the number is in the list
                       		  delete(list,num);	// delete the number from the list
                       		  printf("SUCCESS DELETED!\n");
 	                }
			else{			// if the number is not in the list
                        printf("THE IS NOT IN THE LIST\n");
                        }
               	 }
		 else{ // If input does not have a proper inserting format.

			printf(" Enter the following commands\n");
			printf(" i 'number'   insert\n");
			printf(" d 'number'   delete\n");
			printf(" s 'number'   search\n");
			printf(" p            print the list\n");
			printf(" x            exit program\n");

                }
	}



	else if (buffer[0] == 's'){	// This is searching
	
                if (parse(buffer,&num)){    // chedcking proper format
                        if (search(list,num)){	// if the number is in the list
                                printf("FOUND\n");
                	}
			else{
                                printf("NOT FOUND\n");  // if the number is not in the list
                	}
                }
		else{ // if input does not have a proper format
        		printf(" Enter the following commands\n");
			printf(" i 'number'   insert\n");
			printf(" d 'number'   delete\n");
			printf(" s 'number'   search\n");
			printf(" p            print the list\n");
			printf(" x            exit program\n");


              	}
         
	}
	
	else if ( buffer[0] == 'p'){   // This is printing the list
		print(list); 	// printing code from link_list.h
	 
	}
	
	else if ( buffer[0] == 'x'){	// This is for exit.
	clear(list);
	printf("GOODBYE\n");
	done=1;				// the value of done is changed from 0 to 1 and while loop will be broken
	}
	else{
	 		printf(" Enter the following commands\n");
			printf(" i 'number'   insert\n");
			printf(" d 'number'   delete\n");
			printf(" s 'number'   search\n");
			printf(" p            print the list\n");
			printf(" x            exit program\n");



	}

}

}
