// Name : Gawun Kim
// CSE 222 Winter
// Februray 16 2018
// Program assignment 3
// This is pa3. This program is asking users to insert numbers and the numbers will be recorded. There are two modes. First one is stack and the other one is queue.
// The user can change the mode and they can see the inserted numbers. Also, they can remove the numbers on the stack or the queue.
// This is queue linklisti.h. This is connected to queuelink.c.  There are "Push" "Pop" "Print" "Clear".



#ifndef _QUEUELINK_H_
#define _QUEUELINK_H_



struct qnode{			/// This is queue struct and there are three
				/// data  next  tailptr 
	int data;
	struct qnode*next;		
	struct qnode*  tailptr;		// tailptr is very important for indicating the TAIL from sentinel.
};					

struct qnode *q_Init();

int q_push(struct qnode* q_list, int num);

int q_pop(struct qnode* q_list);

int q_print(struct qnode*q_list);

void q_clear(struct qnode* q_list);

#endif
