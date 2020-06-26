// Name  : Gawun Kim
// Class : CSE 222
// DATE  : Jan/18/18
// Program Assignment 1
// this link_list.c is the code for link_list.h  

#include<stdio.h>
#include "link_list.h"
#define MYNULL -1

int parse(char *in, int *out){  // This is checking for valid input
        char c;
        if (sscanf(in,"%c %d",&c,out) > 1){
                return 1; // if user typed proper inputs, it will return 1
        } else {
                return 0; // if it is not proper, it will return 0
        }
}
int get_node(struct node*ll){ // This looks for the next free spot. if there are valid nodes , the indexes of these node will be return and if there is no more space it will be return -1 it is my null
	int i;
	for (i=0; i<SIZE; i++){
                if(ll[i].valid==0){
                ll[i].valid=1;
                return i;
                }
        }
  return MYNULL;
}

void release_node(struct node*ll,int number){ // for the node to be available, change the value of valid from others to zero
 ll[number].valid=0;
}

void init(struct node*ll){		// initialize nodes
	int i;
	for (i=0; i<SIZE; i++){
		release_node(ll,i);  //make nodes available
	}
	i=get_node(ll);    
	ll[i].next = MYNULL;
}

int add(struct node*ll,int number){   // This is adding number in the list and sorting the number orderly from low to high.
  int tmpnode=0;
  int nextnode=ll[tmpnode].next;
  int newnode=get_node(ll);

	if(newnode == MYNULL){   // if newnode is the end of nodes
		return 0; 		// it is unsuccessful
	}

	ll[newnode].data  = number;

	while(nextnode != MYNULL){    // all nodes will be checked until the end of node that has mynull
			if ( number < ll[nextnode].data){
			 ll[tmpnode].next = newnode;
			 ll[newnode].next = nextnode;
			return 1;  // if it is successful, it will return 1 
			}
		   tmpnode=nextnode;
		   nextnode=ll[tmpnode].next;
	}
	ll[tmpnode].next = newnode;
	ll[newnode].next = MYNULL;
	return 1; // if it is successful it will return 1
}

int delete(struct node*ll, int number){ // This is deleting number in the list
	int tmpnode = 0;
	int nextnode=ll[tmpnode].next;
	
	while (nextnode != MYNULL){   // all node will be checked until the end of node that has mynull
		if (ll[nextnode].data == number){   // if there is same number in the node and
			ll[tmpnode].next=ll[nextnode].next; // change the value of the next
			release_node(ll,nextnode);
		}
	tmpnode=nextnode;
	nextnode=ll[tmpnode].next;
	}
}

 
void print(struct node*ll){  // printing the list.
	
	int tmpnode=ll[0].next;
	while (tmpnode != MYNULL){    // it will be keep checking until the last node that has mynull
		if(ll[tmpnode].next == MYNULL){
                        printf("%d\n", ll[tmpnode].data);
                        tmpnode = ll[tmpnode].next;
                 }
                else{
                         printf("%d ", ll[tmpnode].data);
                         tmpnode = ll[tmpnode].next;
                    }

	}
}
int search(struct node*ll, int number){   // searching some number in the list.
        int tmpnode = ll[0].next;
        while(tmpnode!=MYNULL){
                if(ll[tmpnode].data == number){
                         return 1;		 /// if the number is found
                }
                        tmpnode = ll[tmpnode].next;
        }
                        return 0;  		
}


