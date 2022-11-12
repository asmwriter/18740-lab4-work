// CPP Program to find sum of array
#include <stdio.h>
#include <pthread.h>

// size of array
#define MAX 64

// maximum number of threads
#define MAX_THREAD 4


volatile double var1, var2;
volatile double a[MAX] = {0};

struct ab {
    volatile double a;
    volatile double b;
    struct ab *next;
};

volatile struct ab *abs1;

void inc_a(void) {
    volatile struct ab *this_ab = abs1;
    while (this_ab != NULL) {
        this_ab->a++;
        this_ab = this_ab->next;
    }
}

void sum_b(void) {
    int sum = 0;
    volatile struct ab *this_ab = abs1;
    while (this_ab != NULL) {
        sum += this_ab->b;
        this_ab = this_ab->next;
    }
    // return sum;
}


// void* thread_fn(void* arg)
// {
// 	a[0] = a[512]*2;
//     a[1024] = a[1549]+5;
// }

// void* thread_fn(void* arg)
// {
//     int *tid = (int *)arg;
// 	if(*tid == 0){
//         for(int i = 0; i<MAX; i++){
//             var1 += a[i]*2.0;
//         }
//     }
//     if(*tid == 1){
//         for(int i = 0; i<MAX; i+=10){
//             var2 *= a[i]*2.0;
//         }
//     }
//     return 0;

// }

// Driver Code
int main()
{

	pthread_t threads[MAX_THREAD];
    // for(int i = 0; i<MAX;i++){
    //     a[i] = (double)rand()/1.0;
    // }
    while(1){
        // Creating 4 threads
        int i;
        // for (i = 0; i < MAX_THREAD; i++)
            pthread_create(&threads[0], NULL, inc_a, NULL);
            pthread_create(&threads[1], NULL, sum_b, NULL);
            pthread_create(&threads[2], NULL, inc_a, NULL);
            pthread_create(&threads[3], NULL, sum_b, NULL);

        // joining 4 threads i.e. waiting for all 4 threads to complete
        //for (i = 0; i < MAX_THREAD; i++)
        //    pthread_join(threads[i], NULL);

        // adding sum of all 4 parts
        //int total_sum = 0;
        // for (i = 0; i < MAX_THREAD; i++){
        //     printf("sum is %d\n", sum);
        // }
    }

	return 0;
}