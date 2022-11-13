// CPP Program to find sum of array
#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// size of array
#define MAX 128

// maximum number of threads
#define MAX_THREAD 4

volatile int matA[MAX][MAX];
volatile int matB[MAX][MAX];


volatile int sum[MAX_THREAD] = {0};
int part =  0;

struct data{
   int  tid;
};

struct data data_arr[MAX_THREAD];

void operate(int thread_part)
{
    for (int i = 0; i < MAX; i++) {
        for (int j=1;j<MAX;j++) {
            matA[i][j] += matB[i][j];
            matB[i][j-1] += matA[i][j-1];
            for (int k=0;k<MAX*1000;k++) {
                sum[thread_part] += matA[MAX-i-1][j];
                matA[MAX-i-1][j] += 4+sum[thread_part];
                
                sum[thread_part] += matA[i][j];
                matA[i][j] += 4+sum[thread_part];

                sum[thread_part] += matB[MAX-i-1][j];
                matB[MAX-i-1][j-1] += 4+sum[thread_part];
                matB[MAX-i-1][j] += 4+sum[thread_part];

                sum[(thread_part-1)%MAX_THREAD] += matB[i][j];
                matB[i][j] += 4+matA[i][j-1];
                matB[i][j-1] += sum[(thread_part)%MAX_THREAD];
            }
        }
    }

}
void* thread_fn(void* arg)
{
    struct data *lc;
    lc = (struct data *)arg;
    int tid = lc->tid;
    int thread_part = tid;
    int temp = 0;
    operate(thread_part);


    return 0;
}

// Driver Code
int main()
{

	pthread_t threads[MAX_THREAD];

    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            matA[i][j] = rand() % 10;
            matB[i][j] = rand() % 10;
        }
    }
    // int cnt = 2;
    // printf("#######VERSION 16#############\n");
    while(1){
        part = 0;
        // Creating 4 threads
        
        for (int i = 0; i < MAX_THREAD; i++) {
            data_arr[i].tid = i;
            pthread_create(&threads[i], NULL, thread_fn, &data_arr[i]);
        }

    
        // joining 4 threads i.e. waiting for all 4 threads to complete
        for (int i = 0; i < MAX_THREAD; i++)
           pthread_join(threads[i], NULL);

    }

	return 0;
}