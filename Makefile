# Makefile for Hello World project

hello: main.o hello.o goodbye.o
	gcc -o build/hello main.o hello.o goodbye.o

main.o: main.c
	gcc -c main.c

hello.o: hello.c
	gcc -c hello.c

howitisgoing.o: howitisgoing.c
	gcc -c howitisgoing.c

goodbye.o: goodbye.c
	gcc -c goodbye.c

clean:
	rm -f *.o build/hello
