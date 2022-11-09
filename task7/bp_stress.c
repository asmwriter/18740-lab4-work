#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#include <stdint.h>

unsigned long long int rand1() {
    volatile unsigned long long int r;
    while(((r = rand() % 1024) < 512) );
    return r;
}

unsigned long long int  rand2() {
    volatile unsigned long long int r;
    while(((r = rand() % 1024) >= 512) );
    return r;
}

#define UNROLL_TEST \
        rand_no = rand1(); \
        if(rand_no < 256){      \
            taken++;            \
        }         \
		rand_no = rand2();              \
        if(rand_no >= 256){     \
            not_taken++;         \
        }                       \

#define UNROLL_TEST_10 UNROLL_TEST UNROLL_TEST UNROLL_TEST UNROLL_TEST UNROLL_TEST UNROLL_TEST UNROLL_TEST UNROLL_TEST UNROLL_TEST UNROLL_TEST
#define UNROLL_TEST_100 UNROLL_TEST_10 UNROLL_TEST_10 UNROLL_TEST_10 UNROLL_TEST_10 UNROLL_TEST_10 UNROLL_TEST_10 UNROLL_TEST_10 UNROLL_TEST_10 UNROLL_TEST_10
#define UNROLL_TEST_1000 UNROLL_TEST_100 UNROLL_TEST_100 UNROLL_TEST_100 UNROLL_TEST_100 UNROLL_TEST_100 UNROLL_TEST_100 UNROLL_TEST_100 UNROLL_TEST_100 UNROLL_TEST_100 UNROLL_TEST_100
#define UNROLL_TEST_10000 UNROLL_TEST_1000 UNROLL_TEST_1000 UNROLL_TEST_1000 UNROLL_TEST_1000 UNROLL_TEST_1000 UNROLL_TEST_1000 UNROLL_TEST_1000 UNROLL_TEST_1000 UNROLL_TEST_1000 UNROLL_TEST_1000

int main(){
    unsigned long long int rand_no;
	 
    int taken = 0, not_taken = 0;
    while(1){
        UNROLL_TEST_10000
		
    }
    return 0;

}