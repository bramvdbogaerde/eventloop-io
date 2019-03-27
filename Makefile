all: main.o taskqueue.o tasks.o
	gcc main.o taskqueue.o tasks.o -o eventloop-io

main.o: main.c
	gcc -c main.c

taskqueue.o: taskqueue.c taskqueue.h
	gcc -c taskqueue.c

tasks.o: tasks.c tasks.h
	gcc -c tasks.c
