# Makefile for Hello World project

hello: main.o hello.o howisitgoing.o goodbye.o
	gcc -o build/hello main.o hello.o howisitgoing.o goodbye.o

main.o: main.c
	gcc -c main.c

hello.o: hello.c
	gcc -c hello.c

howisitgoing.o: howisitgoing.c
	gcc -c howisitgoing.c

goodbye.o: goodbye.c
	gcc -c goodbye.c

clean:
	rm -f *.o build/hello
