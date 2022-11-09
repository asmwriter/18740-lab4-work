run:
	./bp_stress
build:
	/afs/ece.cmu.edu/class/ece740/tools/armgcc/bin/aarch64-linux-gnu-gcc -static -pthread -o bp_stress bp_stress.c
clean: 
	rm -f bp_stress

all: clean build run