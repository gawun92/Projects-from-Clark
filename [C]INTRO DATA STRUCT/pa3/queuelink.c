// Name : Gawun Kim
// CSE 222 Winter
// Februray 16 2018
// Program assignment 3
// This is pa3. This program is asking users to insert numbers and the numbers will be recorded. There are two modes. First one is stack and the other one is queue.
// The user can change the mode and they can see the inserted numbers. Also, they can remove the numbers on the stack or the queue.
// This is queue linklist file. This is connected to queuelink.h. There are "Push" "Pop" "Print" "Clear". This is link list base.
// push is adding (inserting) a number to the TAIL side
// pop is remove(deleting) a number from the most HEAD 
// Print is printing all the data that linked and clear is making clean all the datas


#include<stdio.h>
#include<stdlib.h>
#include "queuelink.h"



struct qnode *q_Init(){						// This is initializing the node for the beginning
	struct qnode *new = malloc(sizeof(struct qnode));
	new -> next = NULL;
	return (new);
}

int q_push(struct qnode* q_list, int num){ 			// This is for adding a number
 struct qnode *sentinel = q_list;				// Pushing is add and it will be added on the tail.
  								
 struct qnode *tmpnode = malloc(sizeof(struct qnode));		// making a  new node
if (tmpnode == NULL){						// if there is no memory to write
	return 0; 			// it is not successful working
}
	tmpnode -> data = num; 					// give data into new node

if(sentinel -> next == NULL){					//if there is no data before.. when user writes some data at first

	sentinel -> next = tmpnode;				// connect the new with sentinel 
	tmpnode -> next = NULL;					// also it is the first data node and the next has to be null
	sentinel -> tailptr = tmpnode;				// setting the tailptr to the data node
	return 1;				//it is successful working
}


	sentinel -> tailptr -> next = tmpnode;	// if there is more than one datas are linked , the new data will go the tail part, most edge part
	tmpnode -> next = NULL;			// and the next of node will be null
	sentinel -> tailptr = tmpnode;		// change the tailpointer to the new tail
	return 1;			// it is successful working
}

int q_pop(struct qnode* q_list){		// This is pop, that is deleting and the pop will be happened around sentinel node // around head
 struct qnode *sentinel = q_list;		// in sentinel there is no data
 struct qnode *delete;// = sentinel -> next;

	if(sentinel->next == NULL){
	 return 0; // When there is no number
	}

	delete = sentinel -> next;		// change the connection of before and after of the node that has data.
	sentinel -> next = delete -> next;   // 
	free(delete);				// make it free for memory leaking
	
	return 1;
	
}

int q_print(struct qnode* q_list){	// this is printing all the datas in the queue and all the number will be passed by using while loop
     struct qnode *sentinel = q_list;	// this is a sentinel and there is no data
     struct qnode *tmpnode = sentinel -> next;

    if (tmpnode == NULL){		// if there is no data to print
        printf("Queue is Empty!\n");
        printf("HEAD-> <-Tail\n");
        return -1;
    }
        printf("HEAD->");	
        while (tmpnode->next != NULL){		// all the datas of nodes will be passed by while loop
            printf("%d ", tmpnode->data);
            tmpnode = tmpnode->next;		// the increament from here . it works like i=i+1
        }
        printf("%d<-TAIL\n", tmpnode->data);
	return 1;
}

void q_clear(struct qnode* qsent){		// this is a function to make all node to be free and it will make no memory leaking
        struct qnode* temp;

	
  	     while( qsent!=NULL){		// all the data nodes will be passed through this while loop
                temp=qsent;
                qsent=qsent->next;		// for keep counting
		free(temp);			// each of nodes will be free
                
        }


	//tmpnode = NULL;
        //nxtnode = NULL;
}


