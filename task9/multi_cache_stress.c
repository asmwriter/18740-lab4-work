// CPP Program to find sum of array
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// size of array
#define MAX 32

// maximum number of threads
#define MAX_THREAD 4


volatile double var1, var2;
volatile char matA[MAX][MAX];
volatile char matB[MAX][MAX];
volatile char matC[MAX][MAX];


void* thread_fn(void* arg)
{
    int *tid = (int *)arg;
	if(*tid == 0){
        for(int i = 0; i<MAX; i++){
            for(int j = 0; j<MAX; j++) {
                for (int k = 0; k < MAX; k++){
                    // if(i%4 == 0) {
                        matC[i][j] += matA[i][k] * matB[k][j];
                    // }
                    
                }
            }
            
        }
    }
    if(*tid == 1){
        for(int i = 0; i<MAX; i++){
            for(int j = 0; j<MAX; j++) {
                for (int k = 0; k < MAX; k++){
                    // if(i%4 == 1) {
                        matC[i][j] += matA[i][k] * matB[k][j];
                    // } 
                }
            }
        }
    }

    if(*tid == 2){
        for(int i = 0; i<MAX; i++){
            for(int j = 0; j<MAX; j++) {
                for (int k = 0; k < MAX; k++){
                    // if(i%4 == 2) {
                        matC[i][j] += matA[i][k] * matB[k][j];
                    // } 
                }
            }
        }
    }

    if(*tid == 3){
        for(int i = 0; i<MAX; i++){
            for(int j = 0; j<MAX; j++) {
                for (int k = 0; k < MAX; k++){
                    // if(i%4 == 3) {
                        matC[i][j] += matA[i][k] * matB[k][j];
                    // } 
                }
            }
        }
    }
    return 0;

}

// Driver Code
int main()
{

	pthread_t threads[MAX_THREAD];
    // for(int i = 0; i<MAX;i++){
    //     a[i] = (double)rand()/1.0;
    // }

    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            matA[i][j] = rand() % 10;
            matB[i][j] = rand() % 10;
        }
    }

    while(1){
        // Creating 4 threads
        int i;
        for (i = 0; i < MAX_THREAD; i++)
            pthread_create(&threads[i], NULL, thread_fn, (void*)&i);
            // pthread_create(&threads[1], NULL, thread_fn, (void*)&i);
            // pthread_create(&threads[2], NULL, thread_fn, (void*)&i);
            // pthread_create(&threads[3], NULL, thread_fn, (void*)&i);

        // joining 4 threads i.e. waiting for all 4 threads to complete
        for (i = 0; i < MAX_THREAD; i++)
           pthread_join(threads[i], NULL);

        // adding sum of all 4 parts
        //int total_sum = 0;
        // for (i = 0; i < MAX_THREAD; i++){
        //     printf("sum is %d\n", sum);
        // }
    }

	return 0;
}