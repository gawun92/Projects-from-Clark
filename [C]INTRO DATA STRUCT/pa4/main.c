// Name : Gawun Kim
// Date : March / 2 /2018
// Class : CSE222 (Nick Macias)
// Description : This Program is a Binary Search Tress. In this program, the user can inset numbers, delete numbers, and watch the numbers that user typed. When user watch the result, six of lines will be shown: NLR, LNR, LRN, BFS, and for the another options, there will be hight of the tree and checking whether it is balanced or not.
// This is main.c and this is the main code of this program(Tree) All the defined code will be given from function.h.


#include<stdio.h>
#include<stdlib.h>
#include"function.h"


int main(){
        Tree t = NULL; //Inisialize the tree to NULL
        int done = 0;
        char buffer[255];
        int num;
        printf("Enter '?' for help.\n");
        while (!done){
                printf(": ");
                fgets(buffer,255,stdin);
        switch(buffer[0]){

        case 'x':
        case 'X':
                printf("NLR: ");
                NLR(t);
                printf("\b\b  \nLNR: ");
                LNR(t);
                printf("\b\b  \nLRN: ");
                LRN(t);
                printf("\b\b  \nBFS: ");
                BFS(t);
                printf("HEIGHT: %d", Height(t));
                if (Balance(t)){
                        printf("\nBALANCED: YES");
                }else{
                        printf("\nBALANCED: NO");
                }
                printf("\n");
                break;
        case 'q':
        case 'Q':
                printf("GoodBye\n");
                done = 1;
                break;
        case 's':
        case 'S':
                if (parse(buffer,&num)){
                        if (search(t,num)){
                                printf("FOUND\n");
                        } else {
                                printf("NOT FOUND\n");
                        }
                }
  break;
        case 'd':
        case 'D':
                if (parse(buffer,&num)){
                        if (search(t,num)){
                                t = delete(t,num);
                        printf("SUCCESS\n");
                }else {
                        printf("NODE NOT FOUND\n");
                        }
                }
                break;
        case '?':
                printf("s [number]   Searchs for number in the Binary Tree.\n");
                printf("d [number]   Deletes number from the Binary Tree.\n");
                printf("X            Displays information about the Binary Tree.\n");
                printf("#            Inserts that number into the Binary Tree.\n");
                printf("?            Displays valid commands.\n");
                printf("Q            Exits the program.\n");
        default:
                if(sscanf(buffer,"%d",&num)){
                        if(search(t,num)==0){
                                t = insert(t,num);
                                printf("SUCCESS\n");
                        } else{
                                printf("NODE ALREADY IN THE LIST\n");
                        }
                } else { printf("Enter '?' for help.\n"); }
                        break;
        }
   }
                release(t);
}

