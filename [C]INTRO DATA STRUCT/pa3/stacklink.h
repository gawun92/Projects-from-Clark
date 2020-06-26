// Name : Gawun Kim
// CSE 222 Winter
// Februray 16 2018
// Program assignment 3
// This is pa3. This program is asking users to insert numbers and the numbers will be recorded. There are two modes. First one is stack and the other one is queue.
// The user can change the mode and they can see the inserted numbers. Also, they can remove the numbers on the stack or the queue.
// This is stack linklist file. This is stacklist.h and it will be link with main.c stacklink.c There are push pop print and clear and these four would work in main.



#include <stdio.h>
struct Node			// This is stack struct 
{
    int data;
    struct Node *next;	
};

void s_push(int);
void s_pop();
void s_print();
void s_clear();
