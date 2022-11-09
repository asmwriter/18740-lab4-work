run:
	./multi_cache_stress
build:
	/afs/ece.cmu.edu/class/ece740/tools/armgcc/bin/aarch64-linux-gnu-gcc -static -pthread -o multi_cache_stress multi_cache_stress.c
clean: 
	rm -f multi_cache_stress

all: clean build run