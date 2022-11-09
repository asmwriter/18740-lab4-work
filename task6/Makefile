run:
	./hello_world
build:
	/afs/ece.cmu.edu/class/ece740/tools/armgcc/bin/aarch64-linux-gnu-gcc -static -pthread -o hello_world hello_world.c
clean: 
	rm -f hello_world

all: clean build run