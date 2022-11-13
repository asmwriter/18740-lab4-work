// CPP Program to find sum of array
#include <stdio.h>
#include <pthread.h>

// size of array
#define MAX 1024

// maximum number of threads
#define MAX_THREAD 4


int a[MAX] = {0};
int sum[MAX] = { 0 };
int part = 0;

void* sum_array(void* arg)
{


	// Each thread computes sum of 1/4th of array
	int thread_part = part++;
    int i;
	//for (i = thread_part * (MAX / 4); i < (thread_part + 1) * (MAX / 4); i++)
	//	sum[thread_part] += a[i];
    for (i = 0; i < MAX; i++)
		sum[i] += a[i];
}

// Driver Code
int main()
{

	pthread_t threads[MAX_THREAD];
    while(1){
        // Creating 4 threads
        int i;
        for (i = 0; i < MAX_THREAD; i++)
            pthread_create(&threads[i], NULL, sum_array, (void*)NULL);

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
