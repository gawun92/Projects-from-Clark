// Name  : Gawun Kim
// Class : CSE 222
// DATE  : Jan/18/18
// Program Assignment 1
//link list.h will be used in the main by include.

#ifndef _LINK_LIST_H_
#define _LINK_LIST_H_
#define SIZE 100   //  define the size of node to 100

struct node
{
	int data;
	int next;
	int valid;
};

int parse(char *in, int *out);
int get_node(struct node*ll);
void release_node(struct node*ll,int number);
void init(struct node*ll); 
int add(struct node*ll, int number);
int delete(struct node*ll, int number);
void print(struct node*ll);
int search(struct node*ll, int number);


#endif
