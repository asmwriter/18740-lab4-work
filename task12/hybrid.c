// CPP Program to find sum of array
#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// size of array
#define MAX 6000

int AR_SIZE = 50;

// maximum number of threads
#define MAX_THREAD 4

void seq_fn (volatile float *arr) {

    volatile float sum;
    volatile float arr_add = 0;

    for (int j = 0; j<AR_SIZE; j++) {
        arr[j] = rand();
    }
    for (int i = 1; i <AR_SIZE; i++) {
        arr[i] *= arr[i-1] + i;
        sum = arr[i] + arr[i-1];
        arr[i] = arr[i-1]-1 * sum; 
        arr_add /= sum;
    }
}

void* thread_fn(void* arg) {
    long temp = 1;
    int ar1[MAX];
    int ar2[MAX];
    for (int i=0;i<MAX;i++) {
        ar1[i] = rand()%10;
        ar2[i] = rand()%10;
    }
    for(int i=0;i<MAX;i++){
        for(int j=0;j<MAX;j++){
            temp *= ar1[i] * ar2[j];
            if(temp>MAX)
                temp = 1;
        }
    }
}

// Driver Code
int main() {

    volatile float arr[AR_SIZE];

    // cpu_set_t cpuset;
    // cpu_set_t  mask;
    // CPU_ZERO(&cpuset);
    // CPU_ZERO(&mask);
    
    // CPU_SET(4, &mask);
	// sched_setaffinity(0, sizeof(mask), &mask);
	


    long cnt1 = 7000000;
    while(cnt1--) {
        seq_fn(arr);
    }

    pthread_t threads[MAX_THREAD];

    long cnt2 = 10;
    while(cnt2--) {

        // Creating 4 threads
        int i;
        for (i = 0; i < MAX_THREAD; i++) {
            // CPU_SET(i, &cpuset);
            pthread_create(&threads[i], NULL, thread_fn, (void*)&i);
            // pthread_setaffinity_np(threads[i], sizeof(cpuset), &cpuset);
            // CPU_CLR(i, &cpuset);
            // CPU_ZERO(&cpuset);
        }

        // joining 4 threads i.e. waiting for all 4 threads to complete
        for (i = 0; i < MAX_THREAD; i++)
           pthread_join(threads[i], NULL);

    }

	return 0;
}