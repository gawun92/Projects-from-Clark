## Name : Gawun Kim
## CSE 222 Winter
## Februray 16 2018
## Program assignment 3
## This is pa3. This program is asking users to insert numbers and the numbers will be recorded. There are two modes. First one is stack and the other one is queue. 
##The user can change the mode and they can see the inserted numbers. Also, they can remove the numbers on the stack or the queue.
## This is makefile and it gives user to be comfortable to deal with the program. 

all: main
clean:
	rm *.o main

main: main.o stacklink.o queuelink.o
	gcc -o main main.o stacklink.o queuelink.o

main.o: main.c stacklink.h queuelink.h
	gcc -o main.o -c -g main.c

stacklink.o: stacklink.c stacklink.h
	gcc -o stacklink.o -c -g stacklink.c

queuelink.o: queuelink.c queuelink.h
	gcc -o queuelink.o -c -g queuelink.c
	
