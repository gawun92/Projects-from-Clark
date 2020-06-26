## Name : Gawun Kim
## Class: CSE 222(Nick Macias)
## Date : Mar/15/2018
## Program assignment 5
## No parter
## makefile
## Description : This program requires the user to type some number and this number would be the bag's cappacity(weight). All the products' list is written into 'knapsack.data. This program reads that list and show the best possibility to be able to put. The heaviest product would be put as many as possible, second heaviest,.... and the last one. Also, depends on the possibility, the total value of products would be calculated and the number would be shown. For the last line, the line shows the products that are inside of the bag.

all: main
clean:
	rm *.o main

main: main.o functions.o
	gcc -o main main.o functions.o
main.o: main.c functions.h
	gcc -o main.o -c -g main.c
functions.o: functions.c functions.h
	gcc -o functions.o -c -g functions.c

