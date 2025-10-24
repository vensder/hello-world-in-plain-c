# Makefile for Hello World project

hello_world: hello_world.o hello.o howisitgoing.o goodbye.o cpu_freq.o cpu_model.o check_vm.o sys_vendor.o
	gcc -o build/hello_world hello_world.o hello.o howisitgoing.o goodbye.o cpu_freq.o cpu_model.o check_vm.o sys_vendor.o

hello_world.o: hello_world.c hello_world.h
	gcc -c hello_world.c

hello.o: hello.c
	gcc -c hello.c

howisitgoing.o: howisitgoing.c
	gcc -c howisitgoing.c

goodbye.o: goodbye.c
	gcc -c goodbye.c

cpu_freq.o: cpu_freq.c
	gcc -c cpu_freq.c

cpu_model.o: cpu_model.c
	gcc -c cpu_model.c

check_vm.o: check_vm.c
	gcc -c check_vm.c

sys_vendor.o: sys_vendor.c
	gcc -c sys_vendor.c

clean:
	rm -f *.o build/hello_world
