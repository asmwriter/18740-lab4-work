#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<stdint.h>

#define UNROLL_TEST                 \
        rand_no = random()%1024;    \
        if(rand_no < 512){          \
            not_taken++;            \
        }                           \
        if(rand_no >= 512){         \
            taken++;                \
        }                           \

#define UNROLL_TEST_10 UNROLL_TEST UNROLL_TEST UNROLL_TEST UNROLL_TEST UNROLL_TEST UNROLL_TEST UNROLL_TEST UNROLL_TEST UNROLL_TEST UNROLL_TEST
#define UNROLL_TEST_100 UNROLL_TEST_10 UNROLL_TEST_10 UNROLL_TEST_10 UNROLL_TEST_10 UNROLL_TEST_10 UNROLL_TEST_10 UNROLL_TEST_10 UNROLL_TEST_10 UNROLL_TEST_10
#define UNROLL_TEST_1000 UNROLL_TEST_100 UNROLL_TEST_100 UNROLL_TEST_100 UNROLL_TEST_100 UNROLL_TEST_100 UNROLL_TEST_100 UNROLL_TEST_100 UNROLL_TEST_100 UNROLL_TEST_100 UNROLL_TEST_100
#define UNROLL_TEST_10000 UNROLL_TEST_1000 UNROLL_TEST_1000 UNROLL_TEST_1000 UNROLL_TEST_1000 UNROLL_TEST_1000 UNROLL_TEST_1000 UNROLL_TEST_1000 UNROLL_TEST_1000 UNROLL_TEST_1000 UNROLL_TEST_1000

int main(){
    int rand_no; 
    int taken = 0, not_taken = 0;
    while(1){
        UNROLL_TEST_10000
		UNROLL_TEST_10000
		UNROLL_TEST_10000
		UNROLL_TEST_10000
		UNROLL_TEST_10000
    }
    return 0;

}