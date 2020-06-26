## Name : Gawun Kim
## Date : March / 2 /2018
## Class : CSE222 (Nick Macias)
## Description : This Program is a Binary Search Tress. In this program, the user can inset numbers, delete numbers, and watch the numbers that user typed. When user watch the result, six of lines will be shown: NLR, LNR, LRN, BFS, and for the another options, there will be hight of the tree and checking whether it is balanced or not.
## This is makefile and it makes the user compile this program easily.


all : main
clean:
	rm *.o main

main: main.o function.o
	gcc -o main main.o function.o
main.o: main.c function.h
	gcc -o main.o -c -g main.c
function.o: function.c function.h
	gcc -o function.o -c -g function.c

