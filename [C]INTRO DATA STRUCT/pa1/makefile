## Name  : Gawun Kim
## Class : CSE 222
## DATE  : Jan/18/18
## PA 1
all: main
clean: 
	rm *.o main

main: main.o link_list.o
	gcc -o main main.o link_list.o
main.o: main.c link_list.h
	gcc -o main.o -c -g main.c
link_list.o: link_list.c link_list.h
	gcc -o link_list.o -c -g link_list.c

