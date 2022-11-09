#include<stdio.h>
#include<stdlib.h>
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

    static unsigned int nSeed = 5323;

    nSeed = (8253729 * nSeed + 2396403);

    return nSeed%32767;
	
}



uint64_t custom_rand(){
    return jump();
}
 

int main(){
    srandom(1005330);
    unsigned long int volatile random_test_value, random_mod_val, random_condition_val, random_seed;
    unsigned long int volatile dummy;
    while(1){
        //Generate random test value
        random_test_value = custom_rand();
        //Generate random mod value
        random_mod_val = custom_rand();
        //Generate random seed
        random_seed = custom_rand();
        //If condition random threshold value
        random_condition_val = custom_rand();
        //If condition test value
        random_test_value = random_test_value * random_mod_val; 
        //printf("random_test_value =%u\n", random_test_value);
        //printf("random_condition_val =%u\n", random_condition_val);
        //Test test value against random threshold
        if(random_test_value < random_condition_val){
            //printf("Taken if");
            
            dummy = 0;
            random_seed = custom_rand();
            srandom(random_seed);
            random_seed = custom_rand();
        }
        else{
            //printf("Taken else");
            dummy = 1;
            random_seed = custom_rand();
            srandom(random_seed);
            random_seed = custom_rand();
            random_mod_val = custom_rand() * custom_rand();
            srandom(random_seed*random_mod_val);
        }
        //Change the seed value
        srandom(random_seed);
    }

}