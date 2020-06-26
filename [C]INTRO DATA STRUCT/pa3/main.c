// Name : Gawun Kim
// CSE 222 Winter
// Februray 16 2018
// Program assignment 3
// This is pa3. This program is asking users to insert numbers and the numbers will be recorded. There are two modes. First one is stack and the other one is queue. THe user can change the mode and they can see the inserted numbers. Also, they can remove the numbers on the stack or the queue. 
// This is main.c and this program is connected to stack linklist files and queue linklist files. This main is for everything except linklists.

#include <stdio.h>
#include "stacklink.h"  // This is for stack code
#include "queuelink.h"  // This is for queue code
#include <stdlib.h>
int main(){
struct qnode* q_list = q_Init();
    int done = 0;	// This is for while loop and I initialize this value as a zero
    char buffer[255];  // for stack
    char buffer1[255]; // for queue
    int num;
    int num1;
			// INITIAL direction
    printf("Welcome. This program demonstrates the use of a stack and a queue.\n");
    printf("Usage :\n");
    printf("#   insert #into stack or queue\n");
    printf("s   select STACK mode and display stack\n");
    printf("q   select QUEUE mode and display queue\n");
    printf("p   remove top of stack /head of queue and display\n");
    printf("Q   Quit\n");
    printf("?   Display help\n");
					/// initial asking is for stack
    while (!done){	// This loop will keep going until the value of 'done' is changing
                
        printf("> ");
        fgets(buffer, 255, stdin);		// for asking input line
        switch (buffer[0]){						// initial start mode is stack!!
            case 's':				// this is for stack mode
                    printf("Switching Stack mode!\n");
                    s_print();
                    break;
            case 'p':				// This is for pop
                    s_pop();
                    break;
            
            case 'Q':
                    printf("good bye!\n");
		    done = 1;			// This makes us go out. it means break the while loop
                    break;

            case '?':			
                    printf("Usage :\n");
                    printf("#   insert #into stack or queue\n");
                    printf("s   select STACK mode and display stack\n");
                    printf("q   select QUEUE mode and display queue\n");
                    printf("p   remove top of stack /head of queue and display\n");
                    printf("Q   Quit\n");
                    printf("?   Display help\n");
                    break;

            default:				// if user typed different character or ..user input prpoer number
                    if (sscanf(buffer, "%d", &num) == 1){	// the number will work as a push
                        s_push(num);				// if loop allows a number and it will go inside of push
                    }
                    break;
        }

        if (buffer[0] == 'q'){			//if user typed 'q' and this is also a part of while loop.

            printf("Switching Queue mode!\n");
            q_print(q_list);				// this is all about q so that all the codes are about queue
            buffer1[0] = 0;
            while (buffer1[0] != 's'){		// it will be broken when user types 's' and this loop will break.
                printf("> ");
                fgets(buffer1, 255, stdin);   
                switch (buffer1[0]){
                    case 'q':
                            printf("Switching Queue mode!\n");
                            q_print(q_list);
                            break;
                    case 'p':		
                            q_pop(q_list);
                            break;
                    
                    case 'Q':
                            printf("good bye!\n");
			    q_clear(q_list);        // clean the meory for queue
                            return(1);
			    //return 1;
                    case '?':
                            printf("Usage :\n");
                            printf("#   insert #into stack or queue\n");
                            printf("s   select STACK mode and display stack\n");
                            printf("q   select QUEUE mode and display queue\n");
                            printf("p   remove top of stack /head of queue and display\n");
                            printf("Q   Quit\n");
                            printf("?   Display help\n");
                            break;
                
                    default:
                            if (sscanf(buffer1, "%d", &num1) == 1){		// if user typed some different character or numbers
                                q_push(q_list,num1);					// it allows only number and the number will go to push
                            }
                            break;
                }
            }
	printf("Switching Stack Mode\n");
	s_print();				// above was queue and if user changed the mode from queue to stack, computer show which numbers are in the list of stack mode
        }
    }
s_clear();		// clean the memory for stack
q_clear(q_list);	// clean the meory for queue
}
