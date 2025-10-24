# Makefile for Hello World project

hello_world: hello_world.o hello.o howisitgoing.o goodbye.o
	gcc -o build/hello_world hello_world.o hello.o howisitgoing.o goodbye.o

hello_world.o: hello_world.c hello_world.h
	gcc -c hello_world.c

hello.o: hello.c
	gcc -c hello.c

howisitgoing.o: howisitgoing.c
	gcc -c howisitgoing.c

goodbye.o: goodbye.c
	gcc -c goodbye.c

clean:
	rm -f *.o build/hello_world
