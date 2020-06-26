// Name  : Gawun Kim
// Class : CSE222(DATA STRUC) 
// Date  : 02/FEB/ 2018 Winter
// Program assignment 2
// Description : This assignment is one part of PA2. In pa2, I expect the result to be shown some input numbers and input numbers can delete, add, and print. Also, all this things are based on node: next and data. This file is link_list.c and it will be the specific code for link_list.h. 


#include<stdio.h>
#include<stdlib.h>
#include "link_list.h"  // Connecting to link_list.h

struct node *init(){		// This is to return a pointer to an empty list.
 struct node *new;
 new = malloc(sizeof(struct node));
 new -> next = NULL;		// This is for making an emty list.
 return (new);
}

int add(struct node*list,int number){ // This is for adding some input number into list and change the order by comaring.
 struct node *tmpnode = list;
 struct node *nxtnode;
 struct node *newnode;   // This node is for inserted number
 nxtnode = tmpnode -> next;  	// define "nxtnode"
 newnode = malloc(sizeof(struct node));   // forming a new node

	if( newnode == NULL){  
	 return 0;
	}
 	newnode -> data = number;
	while(nxtnode != NULL){  // while loop will check each node until NULL
		if( number < nxtnode -> data ){ 
		  tmpnode -> next = newnode;
		  newnode -> next = nxtnode;
		  return 1;  // it will be ended.
		}
	 tmpnode = nxtnode;
	 nxtnode = tmpnode -> next;
	}
	
 tmpnode -> next = newnode;
 newnode -> next = NULL;  //This is the case that number is the largest into list.
 return 1;
}

int delete(struct node *list, int number){ // This node is deleting inserted number intoi list and change 'next' of each of nodes.

 struct node *tmpnode = list;
 struct node *nxtnode;  

 nxtnode = tmpnode -> next;
	while (nxtnode != NULL){
		if( number == nxtnode -> data ){
		 tmpnode -> next = nxtnode -> next; //for deleting, change 'next' in each node.
		    free(nxtnode);
		 return 1;
		}
	 tmpnode = nxtnode;  // for moving tmp and next to each of next node
	 nxtnode = tmpnode -> next; 
	}
 return 0; 
}

void print(struct node*list){  // This is printing some number into list.
 struct node *tmpnode = list -> next; 
// struct node *nxtnode = tmpnode -> next;
	 while(tmpnode != NULL){	// it will keep going until NULL
	 	if(tmpnode -> next == NULL){
                 printf("%d\n", tmpnode->data);
                 tmpnode = tmpnode -> next; // This is like i++
                }
                else{
                 printf("%d ", tmpnode->data);
                 tmpnode = tmpnode -> next;
		}
	}
}

int search(struct node*list, int number){ // This is searching some number into list.
 struct node *tmpnode = list -> next;
	while(tmpnode != NULL){
		if(tmpnode -> data == number){
		 return 1; // If inserted number is found into list
		}
	 tmpnode = tmpnode -> next;
	}
 return 0;   // If inserted number is not found into list
}


int parse(char *in, int *out){  // This is the code for checking proper input format.
        char c;
        if (sscanf(in,"%c %d",&c,out) > 1){
                return 1;
        } else {
                return 0;
        }
}

void clear(struct node* list) {
        struct node* tmpnode = list;
        struct node* nxtnode = NULL;
        while (tmpnode != NULL) {
                nxtnode = tmpnode -> next;
                free(tmpnode);
                tmpnode = nxtnode;
        }
}
