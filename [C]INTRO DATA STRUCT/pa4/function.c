// Name : Gawun Kim
// Date : March / 2 /2018
// Class : CSE222 (Nick Macias)
// Description : This Program is a Binary Search Tress. In this program, the user can inset numbers, delete numbers, and watch the numbers that user typed. When user watch the result, six of lines will be shown: NLR, LNR, LRN, BFS, and for the another options, there will be hight of the tree and checking whether it is balanced or not.
// This is fuction.c and this code will be connected with function.h. In other word, it will be the specific code of function.h
#include"function.h"

//The search function first checks if the tree is empty and it is the function will return 0. else if the number the user is searching for is equal to the root of the table the function will return 1. Otherwise if the number the user is checking for is less then the root of the tree it will restart the process to the left side of the tree, but if the number the user enters is larger than the root it will repeat the process to the right side of the tree.
int search(Tree t,int value){ //returns 0 if the number not is found and returns 1 if the number is found.
        if(t == NULL){ //checks if the tree is empty
                return 0;
        }
        else if(t -> data == value){ //checks if the number the user is searching for is same with the root.
                return 1;
        }
        else if(value < t -> data){  //if the number the user is searching for is less than the root it will repeat the process to the left side of the tree
                return(search(t -> left,value));
        }
                return(search(t -> right,value));  //Otherwise it will repeat the process for the right side
}
//The insert function first checks if the tree is empty if it is it will allocate space of 1000 nodes and sets the number the user wants to add as the root and sets the left and right sides of the root equal to NULL. If the number the user is entering is less than the root it will repeat the process to the left side of the node, otherwise if the number is larger than the node then it repeats the process to the right side of the node. Once the number is inserted the function will return the tree.
Tree insert(Tree t,int value){ //returns t if succesful
        if(t == NULL){ //checks if the tree is empty
                Tree t = malloc(((sizeof(struct node))*TREESIZE)); //allocates space of 1000 nodes
                t -> data = value; //sets the users number equall to the root.
                t -> left = t -> right = NULL; //sets both the right and left side of the node equal to NULL.
                return(t); //if the insert is successful
        }
 else if(value < t -> data){ //if the number the user enters is less then the root then repeat the process to the left side.
                t -> left = insert(t -> left,value);
        }
        else if(value > t-> data){ //otherwise if the number the user enters is larger than repeat the process to the right side of the root.
                t -> right = insert(t -> right,value);
        }
                return(t); //returns if successful.
}
//The delete function fist checks if the tree is empty if is then just return NULL. otherwise if the number entered by the user is larger than the root then repeat the process to the right side of the root, but if the number entered but the user is smaller then the root repeat the process to the left side of the root. After that chech if the left side is equal to NULL if it is then save the value of the right side to a temp tree and free the tree. If the right side is equal to NULL then save the tree left to a temp tree and free the tree and return temp. After that use the function called last thefinds the node that points to NULL and replace it with that node.
Tree delete(Tree t,int value){
        if(t == NULL){ //checks if the tree is empty returns NULL if empty
                return NULL;
        }
        else if(value < t -> data){ //checks if the users entered number is less than the root
                t -> left = delete(t -> left,value); //repeats the process if it is less than the root
        }
        else if(value > t -> data){ // checks if the users number is greater than the root
                t -> right = delete(t-> right,value); //repeats the pprocess if it is greater than the root
        }
        else{
                if(t -> left == NULL){ //if the left side is equal to NULL
                        Tree temp = t -> right; //saves the value of the right side to a temp tree
                        free(t);
                        return(temp);
               }
        else if(t -> right == NULL){ //if the right side of the root is equal to NULL
                Tree temp = t->left; //saves the value of the left side to a temp tree
                free(t);
                return(temp);
        }
                Tree temp = last(t -> right); //saves the trees right lowest node to temp
                t -> data = temp -> data; // saves temp value to the root
                t -> right = delete(t -> right,temp -> data); //repeats the proccess to to the right side
        }
                return(t);
}
// The NLR function prints the the tree in pre-order
void NLR(Tree t){
        if(t == NULL){
                return;
        }
        printf("%d, ", t -> data);
        NLR(t -> left);
        NLR(t -> right);
}
//The LNR function prints the tree in-order
void LNR(Tree t){
        if(t == NULL){
                return;
        }
        LNR(t -> left);
        printf("%d, ", t -> data);
        LNR(t -> right);
}
//The LRN function prints the tree in post-order
void LRN(Tree t){
        if(t == NULL){
                return;
        }
        LRN(t -> left);
        LRN(t -> right);
        printf("%d, ", t -> data);
}
// The BFS function starts from the root and starts exploring its neighbors prints them and moves to the next node.
void BFS(Tree t){
        for(int i=1;i <= Height(t)+2;i++){
                print(t,i);
        }
        printf("\b\b  \n");
}
//The height function first checks if the tree is empty returns -1 if it is. Otherwise is checks the height of the left side if it is greater than the right side than return the hight of the left side + 1. if not return height of the right side + 1.
int Height(Tree t){
        if(t == NULL){ //checks if the tree is empty
                return -1;
        }
        int HL = Height(t -> left);
        int HR = Height(t -> right);
        if(HL > HR){    //checks if the height of the left side is greater than the height of the right side
                return(HL+1); //if it is return hight of left side +1
        }
        else{
                return(HR+1); //if not return the height of the right side + 1.
        }
}
//if the tree is empty it will return 1. Otherwise if the value of subtracting the height of the left and the height of the right and checks its less than or equal to 1. and is true for the left and right side then return 1. else return 0.
int Balance(Tree t){
        if(t == NULL){
                return 1;
        }
        int leftHeight = Height(t -> left);
        int rightHeight = Height(t -> right);
       if((abs(leftHeight - rightHeight) <= 1) && (Balance(t -> left)) && (Balance(t -> right))){
                return 1;
        }
        return 0;
}
//the print function checks if the tree is empty if it is it returns nothing. if the depth is equal to 1 it will print the t->data. otherwise if the depth is larger than 1 it will repeat the process for the left and right sides with depth - 1.
void print(Tree t,int depth){
        if(t == NULL){
                return;
        }

        if(depth == 1){
                printf("%d, ", t->data);
        }

        if(depth > 1){
                print(t -> left, depth-1);
                print(t -> right, depth-1);
        }
}
// keeps going down the tree until tree's left->left = NULL.
Tree last(Tree t){ //returns t if it is successful
        Tree tree = t;
        while(t -> left != NULL){
                t = t -> left;
        }
        return t;
}
//the parse function is used to get the input from the user as a letter than space followed with a number.
int parse(char *in, int *out){ //will return 1 if the requirements are met or 0 if the requirement is not met.
        char c;
        if (sscanf(in,"%c %d",&c,out) > 1){
                return 1;
        } else {
                return 0;
        }
}
// if the tree is not empty free the left and right side of the tree.
void release(Tree t){
        if(t != NULL){
                release(t -> left);
                release(t -> right);
                free(t);
                Tree t = NULL;
        }
}


