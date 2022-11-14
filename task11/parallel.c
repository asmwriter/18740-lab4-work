// CPP Program to find sum of array
#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// size of array
#define MAX 500

// maximum number of threads
#define MAX_THREAD 4

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

    // cpu_set_t cpuset;
    // CPU_ZERO(&cpuset);
    

	pthread_t threads[MAX_THREAD];

    long cnt = 12345;
    while(cnt--) {
        // Creating 4 threads
        int i;
        for (i = 0; i < MAX_THREAD; i++) {
            // CPU_SET(i+4, &cpuset);
            pthread_create(&threads[i], NULL, thread_fn, (void*)&i);
            // pthread_setaffinity_np(threads[i], sizeof(cpuset), &cpuset);
            // CPU_CLR(i+4, &cpuset);
            // CPU_ZERO(&cpuset);
        }

        // joining 4 threads i.e. waiting for all 4 threads to complete
        for (i = 0; i < MAX_THREAD; i++)
           pthread_join(threads[i], NULL);

    }

	return 0;
}