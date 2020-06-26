// Name : Gawun Kim
// Date : March / 2 /2018
// Class : CSE222 (Nick Macias)
// Description : This Program is a Binary Search Tress. In this program, the user can inset numbers, delete numbers, and watch the numbers that user typed. When user watch the result, six of lines will be shown: NLR, LNR, LRN, BFS, and for the another options, there will be hight of the tree and checking whether it is balanced or not.
// This is fuction.h and this code will be connected with function.c. In other word, all the specific codes are contained in function.c. Also, this code will be defined in the main program.


#ifndef _FUNCTION_H
#define _FUNCTION_H

#include<stdio.h>
#include<stdlib.h>
#define TREESIZE 1000

struct node{
        struct node* left;
        int data;
        struct node* right;
};

typedef struct node* Tree;

int search(Tree,int);
Tree insert(Tree,int);
Tree delete(Tree,int);
void print(Tree,int);
void BFS(Tree);
void LNR(Tree);
void LRN(Tree);
void NLR(Tree);
int Height(Tree);
int Balance(Tree);
Tree last(Tree);
int parse(char *in, int *out);
void release(Tree);

#endif
