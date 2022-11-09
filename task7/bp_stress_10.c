#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#include <stdint.h>


/*  Written in 2018 by David Blackman and Sebastiano Vigna (vigna@acm.org)

To the extent possible under law, the author has dedicated all copyright
and related and neighboring rights to this software to the public domain
worldwide. This software is distributed without any warranty.

See <http://creativecommons.org/publicdomain/zero/1.0/>. 
*/


/* This is xoshiro256** 1.0, one of our all-purpose, rock-solid
   generators. It has excellent (sub-ns) speed, a state (256 bits) that is
   large enough for any parallel application, and it passes all tests we
   are aware of.

   For generating just floating-point numbers, xoshiro256+ is even faster.

   The state must be seeded so that it is not everywhere zero. If you have
   a 64-bit seed, we suggest to seed a splitmix64 generator and use its
   output to fill s. */


static inline uint64_t rotl(const uint64_t x, int k) {
	return (x << k) | (x >> (64 - k));
}

static uint64_t s[4];

uint64_t next(void) {
	const uint64_t result = rotl(s[1] * 5, 7) * 9;

	const uint64_t t = s[1] << 17;

	s[2] ^= s[0];
	s[3] ^= s[1];
	s[1] ^= s[2];
	s[0] ^= s[3];

	s[2] ^= t;

	s[3] = rotl(s[3], 45);

	return result;
}

/* This is the jump function for the generator. It is equivalent
   to 2^128 calls to next(); it can be used to generate 2^128
   non-overlapping subsequences for parallel computations. */

uint64_t jump(void) {
	static const uint64_t JUMP[] = { 0x180ec6d33cfd0aba, 0xd5a61266f0c9392c, 0xa9582618e03fc9aa, 0x39abdc4529b1661c };

	uint64_t s0 = 0;
	uint64_t s1 = 0;
	uint64_t s2 = 0;
	uint64_t s3 = 0;
	for(int i = 0; i < sizeof JUMP / sizeof *JUMP; i++)
		for(int b = 0; b < 64; b++) {
			if (JUMP[i] & UINT64_C(1) << b) {
				s0 ^= s[0];
				s1 ^= s[1];
				s2 ^= s[2];
				s3 ^= s[3];
			}
			next();	
		}
		
	s[0] = s0;
	s[1] = s1;
	s[2] = s2;
	s[3] = s3;
    return s[0]^s[1]^s[2]^s[3];
}

uint64_t custom_rand(){
    return jump();
}

int rand1() {
    volatile unsigned long long int r;
    while(((r = custom_rand() % 1024) < 512) );
    return r;
}

int rand2() {
    volatile unsigned long long int r;
    while(((r = custom_rand() % 1024) >= 512) );
    return r;
}

/*
int rand2(int pattern)
{
    int i;
    for(i = 0; (i & 0x70000000) != (pattern & 0x70000000); i++);
    return i;
}
*/

unsigned long long f1(){
    //time_t t;
    //srand((unsigned) time(&t));
    return rand1();
}

unsigned long long f2(){
    //time_t t;
    //srand((unsigned) time(&t));
    return rand2();
}

#define UNROLL_TEST        \
        random_test_value = custom_rand(); \
        random_mod_val = custom_rand(); \
        random_seed = custom_rand(); \
        random_condition_val = custom_rand(); \
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
    unsigned int iterations = 500000;
    unsigned long long int volatile random_test_value, random_mod_val, random_condition_val, random_seed;
    unsigned long long int volatile volatile_dummy = 0;
    while(1){
        for(int i= 0; i < iterations; i++){
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
    }
    printf("Volatile dummy = %llu\n", volatile_dummy);

}