#include<stdio.h>
#include<stdlib.h>


int main(){
    srandom(1005330);
    unsigned long int volatile random_test_value, random_mod_val, random_condition_val, random_seed;
    unsigned long int volatile dummy;
    while(1){
        //Generate random test value
        random_test_value = rand();
        //Generate random mod value
        random_mod_val = rand();
        //Generate random seed
        random_seed = rand();
        //If condition random threshold value
        random_condition_val = rand();
        //If condition test value
        random_test_value = random_test_value * random_mod_val; 
        //printf("random_test_value =%u\n", random_test_value);
        //printf("random_condition_val =%u\n", random_condition_val);
        //Test test value against random threshold
        if(random_test_value < random_condition_val){
            //printf("Taken if");
            
            dummy = 0;
            random_seed = rand();
            srandom(random_seed);
            random_seed = rand();
        }
        else{
            //printf("Taken else");
            dummy = 1;
            random_seed = rand();
            srandom(random_seed);
            random_seed = rand();
            random_mod_val = rand() * rand();
            srandom(random_seed*random_mod_val);
        }
        //Change the seed value
        srandom(random_seed);
    }

}