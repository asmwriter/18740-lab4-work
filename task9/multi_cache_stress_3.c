// CPP Program to find sum of array
#include <stdio.h>
#include <pthread.h>
#include <stdalign.h>

// size of array
#define MAX 4

// maximum number of threads
#define MAX_THREAD 4

struct cache_access {
    volatile double arr[MAX]; 
};

volatile struct cache_access a,b;
// volatile int a[MAX] = {0};

void sum_arr (double volatile *a, double volatile *b) {
   *b =  *a + *b;
   *a =  *a + *b;
}

void* thread_fn(void* arg)
{
	a.arr[0] = a.arr[1] * 2;
    b.arr[1] = b.arr[2] + b.arr[0];
    b.arr[3] +=7;
    b.arr[3] = b.arr[3] + 1;
    a.arr[1] = a.arr[0] - 5;
    sum_arr(&a.arr[1], &b.arr[2]);
    return 0;
}

// Driver Code
int main()
{

	pthread_t threads[MAX_THREAD];

   
    while(1){
        // Creating 4 threads
        int i;
        for (i = 0; i < MAX_THREAD; i++)
            pthread_create(&threads[i], NULL, thread_fn, (void*)NULL);

    }

	return 0;
}