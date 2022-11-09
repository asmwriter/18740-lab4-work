#include<stdio.h>
#include<stdlib.h>
#include<time.h>

unsigned long long rand1(){
    time_t t;
    srand((unsigned) time(&t));
    return rand();
}

unsigned long long rand2(){
    time_t t;
    srand((unsigned) time(&t));
    return rand();
}

unsigned long long f1(){
    return rand1();
}

unsigned long long f2(){
    return rand2();
}

#define UNROLL_TEST        \
        random_test_value = rand(); \
        random_mod_val = rand(); \
        random_seed = rand(); \
        random_condition_val = rand(); \
        random_test_value = random_test_value * random_mod_val; \
        if(random_test_value < random_condition_val){ \
            volatile_dummy += f1();             \
        }                                        \
        else{                                   \
            volatile_dummy += f2();             \
        }                                                       \
        srandom(random_seed); \

#define UNROLL_TEST_5 UNROLL_TEST UNROLL_TEST UNROLL_TEST UNROLL_TEST UNROLL_TEST
#define UNROLL_TEST_10 UNROLL_TEST_5 UNROLL_TEST_5
#define UNROLL_TEST_100 UNROLL_TEST_10 UNROLL_TEST_10 UNROLL_TEST_10 UNROLL_TEST_10 UNROLL_TEST_10 UNROLL_TEST_10 UNROLL_TEST_10 UNROLL_TEST_10 UNROLL_TEST_10
#define UNROLL_TEST_1000 UNROLL_TEST_100 UNROLL_TEST_100 UNROLL_TEST_100 UNROLL_TEST_100 UNROLL_TEST_100 UNROLL_TEST_100 UNROLL_TEST_100 UNROLL_TEST_100 UNROLL_TEST_100 UNROLL_TEST_100
#define UNROLL_TEST_10000 UNROLL_TEST_1000 UNROLL_TEST_1000 UNROLL_TEST_1000 UNROLL_TEST_1000 UNROLL_TEST_1000 UNROLL_TEST_1000 UNROLL_TEST_1000 UNROLL_TEST_1000 UNROLL_TEST_1000 UNROLL_TEST_1000
int main(){
    srandom(1005330);
    unsigned long long int volatile random_test_value, random_mod_val, random_condition_val, random_seed;
    unsigned long long int volatile volatile_dummy = 0;
    while(1){
        UNROLL_TEST_10000 
        UNROLL_TEST_10000
        UNROLL_TEST_10000
        UNROLL_TEST_10000
        UNROLL_TEST_10000
        UNROLL_TEST_10000
        UNROLL_TEST_10000
        UNROLL_TEST_10000
        UNROLL_TEST_10000
        UNROLL_TEST_10000    
    }
    printf("Volatile dummy = %llu\n", volatile_dummy);

}