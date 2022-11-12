run:
	./parallel
build:
	/afs/ece.cmu.edu/class/ece740/tools/armgcc/bin/aarch64-linux-gnu-gcc -static -pthread -o parallel parallel.c
clean: 
	rm -f parallel

all: clean build run