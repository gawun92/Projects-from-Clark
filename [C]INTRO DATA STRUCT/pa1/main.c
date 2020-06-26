// Name  : Gawun Kim
// Class : CSE 222
// DATE  : Jan/18/18
// Program Assignment 1 
// This is a single linklist. A user can insert, delete, search a number, and print the list

#include<stdio.h>
#include "link_list.h"  // I already typed some codes in link_list.h file and it is ued in this program

int main(){
	struct node ll[SIZE];
	init(ll);
	char buffer[255];
	int num;
	int done = 0;

while(!done){
	 printf("> ");
	 fgets(buffer,255,stdin);   // This is array for command line
				
	if (buffer[0] == 'i'){   // This is for inserting
	
		if (parse(buffer,&num)){
			if(!search(ll,num)){  // if the number is not in the list.
				add(ll,num);  //insert number into the list and it is from link_list.h
				printf("SUCCESS INSERTED\n");
			}
			else{			// if the number is in the list.
				printf("THIS IS ALREAD IN THE LIST\n");
			}
		}
		else{
			printf(" Enter these following commands\n");
			printf(" i 'number'   insert\n");
			printf(" d 'number'   delete\n");
			printf(" s 'number'   search\n");
			printf(" p            print the list\n");
			printf(" x            exit program\n");
		}	
	  
	}


        else if (buffer[0] == 'd'){  // This is deleting
                if (parse(buffer,&num)){
                        if (search(ll,num)){	// if the number is in the list
                       		  delete(ll,num);	// delete the number from the list
                       		  printf("SUCCESS DELETED!\n");
 	                }
			else{			// if the number is not in the list
                        printf("THE IS NOT IN THE LIST\n");
                        }
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



	else if (buffer[0] == 's'){	// This is searching
	
                if (parse(buffer,&num)){     
                        if (search(ll,num)){	// if the number is in the list
                                printf("FOUND\n");
                	}
			else{
                                printf("NOT FOUND\n");  // if the number is not in the list
                	}
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
	
	else if ( buffer[0] == 'p'){   // This is printing the list
		print(ll);
	 
	}
	
	else if ( buffer[0] == 'x'){	// This is for exit.
	printf("GOODBYE\n");
	done=1;				// while loop will be broken
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
