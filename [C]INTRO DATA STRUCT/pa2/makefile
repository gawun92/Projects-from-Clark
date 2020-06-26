## Name  : Gawun Kim
## Class : CSE222(DATA STRUC)
## Date  : 02/FEB/ 2018 Winter
## Program assignment 2
## Description : This assignment is one part of PA2. This program is to make a file to be excutable.


all: main
clean: 
	rm *.o main

main: main.o link_list.o
	gcc -o main main.o link_list.o
main.o: main.c link_list.h
	gcc -o main.o -c -g main.c
link_list.o: link_list.c link_list.h
	gcc -o link_list.o -c -g link_list.c

