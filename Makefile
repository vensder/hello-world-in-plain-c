# Makefile for Hello World project

hello: main.o hello.o goodbye.o
	gcc -o hello main.o hello.o goodbye.o

main.o: main.c
	gcc -c main.c

hello.o: hello.c
	gcc -c hello.c

goodbye.o: goodbye.c
	gcc -c goodbye.c

clean:
	rm -f *.o hello
