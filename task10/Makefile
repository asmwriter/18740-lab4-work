run:
	./sequential
build:
	/afs/ece.cmu.edu/class/ece740/tools/armgcc/bin/aarch64-linux-gnu-gcc -static -pthread -o sequential sequential.c
clean: 
	rm -f sequential

all: clean build run