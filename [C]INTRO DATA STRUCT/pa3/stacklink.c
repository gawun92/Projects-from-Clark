// Name : Gawun Kim
// CSE 222 Winter
// Februray 16 2018
// Program assignment 3
// This is pa3. This program is asking users to insert numbers and the numbers will be recorded. There are two modes. First one is stack and the other one is queue.
// The user can change the mode and they can see the inserted numbers. Also, they can remove the numbers on the stack or the queue.
// This is queue linklist file. This is connected to queuelink.h. There are "Push" "Pop" "Print" "Clear". This is link list base.
// push is adding (inserting) a number on the top
// pop is remove(deleting) a number from the top
// Print is printing all the data that linked and clear is making clean all the datas



#include "stacklink.h"
#include <stdlib.h>

struct Node *top = NULL;

void s_push(int value){		// This is pushing and inserted number will be put on the top . and it will be accumulated by the order
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node)); //by using malloc  / make a new node
    newNode->data = value;
    if (top == NULL)		/// if there is no data on the top
        newNode->next = NULL;
    else			// there is more than one data on the top
        newNode->next = top;
    
    top = newNode;			// change the top to the new one
//    free(newNode);
    printf("Success!\n");
}
void s_pop(){			// This is pop to remove the number on the top and the pop will be happened from the toppest value
    if (top == NULL){			// if there is no data;
        printf("Stack is Empty!\n");
        return;
    }
        struct Node *temp = top;
        printf("Deleted element: %d\n", top->data);
        top = temp->next;	
        free(temp);			// remove the data for the data leaking

}

void s_print(){					// This is printing all the data inside of stack
    if (top == NULL){				// There is no data 
        printf("Stack is Empty!\n");
        return;
    }
        struct Node *temp = top;
        while (temp->next != NULL){		// this while loop will make pass all numbers
            printf("%d ", temp->data);
            temp = temp->next;			// this is like "i=i+1"
        }
        printf("%d\n", temp->data);
}


void s_clear(){					// clear all the data into nodes for memory leaking
	struct Node* thisnode = top;
	struct Node* nextnode = NULL;
	while(thisnode != NULL){	
		nextnode = thisnode->next;
		free(thisnode);
		thisnode=nextnode;
	}
}

