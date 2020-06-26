// Name  : Gawun Kim
// Class : CSE222(DATA STRUC)
// Date  : 02/FEB/ 2018 Winter
// Program assignment 2
// Description : This assignment is one part of PA2. In pa2, I expect the result to be shown some input numbers and input numbers can delete, add, and print. Also, all this things are based on node: next and data. This file is link_list.h and it is linked to main.c file. All these specific codes are contained in link_list.c



#ifndef _LINK_LIST_H_
#define _LINK_LIST_H_



struct node{
 int data;
 struct node*next;
};

struct node *init(); 
int add(struct node*list,int number); 
void print(struct node*list);
int delete(struct node*list, int number);
int search(struct node*list, int number);
void clear(struct node* list);
int parse(char *in, int *out);
#endif
