// CPP Program to find sum of array
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// size of array
#define MAX 32

// maximum number of threads
#define MAX_THREAD 4


// volatile double var1, var2;
volatile int matA[MAX][MAX];
volatile int matB[MAX][MAX];
volatile int matC[MAX][MAX];



void* operations(int i, int j, int k, int l) {
    matA[i][k] += 7;
    matB[k][j] += matA[i][k]%2;
    matC[i][j] += matA[i][k] * matB[k][j];
    matC[i][j] *= matC[i][j] +9;

    matA[l][k] += 7;
    matB[k][j] += matA[l][k]%2;
    matC[l][j] += matA[l][k] * matB[k][j];
    matC[l][j] *= matC[l][j] +9;

    matA[i][i] += 7;
    matB[i][i] += matA[i][i]%2;
    matC[i][i] += matA[i][i] * matB[i][i];
}


void* thread_fn(void* arg)
{
    int *tid = (int *)arg;
	// if(*tid == 0){
        for(int i = 0; i<MAX; i++){
            // matA[i][i] += 7;
            // matB[i][i] += matA[i][i]%2;
            // matC[i][i] += matA[i][i] * matB[i][i];
            for(int j = 0; j<MAX; j++) {
                matA[i][j] += 7;
                matB[j][i] += matA[i][j]%2;
                matC[i][j] += matA[i][j] * matB[j][i];
                for (int k = 0; k < MAX; k++){
                    for(int l = 0; l<MAX; l++) {
                        // matA[i][k] += 7;
                        // matB[k][j] += matA[i][k]%2;
                        // matC[i][j] += matA[i][k] * matB[k][j];
                        // matC[i][j] *= matC[i][j] +9;

                        // matA[l][k] += 7;
                        // matB[k][j] += matA[l][k]%2;
                        // matC[l][j] += matA[l][k] * matB[k][j];
                        // matC[l][j] *= matC[l][j] +9;

                        // matA[i][i] += 7;
                        // matB[i][i] += matA[i][i]%2;
                        // matC[i][i] += matA[i][i] * matB[i][i];

                        operations(i,j,k,l);
                        operations(MAX-i-1, MAX-j-1, MAX-k-1, MAX-l-1);

                        

                    }
                    // if(i%4 == 0) {
                        

                    // }
                    
                }
                // matC[i][j] += matA[i][j] * matB[j][i];
            }
            
        }
    // }
    // if(*tid == 1){
    //     for(int i = 0; i<MAX; i++){
    //         for(int j = 0; j<MAX; j++) {
    //             matC[i][j] += matA[i][j] * matB[j][i];
    //             for (int k = 0; k < MAX; k++){
    //                 // if(i%4 == 1) {
    //                     matC[i][j] += matA[i][k] * matB[k][j];
    //                 // } 
    //             }
    //             matC[i][j] += matA[i][j] * matB[j][i];
    //         }
    //     }
    // }

    // if(*tid == 2){
    //     for(int i = 0; i<MAX; i++){
    //         for(int j = 0; j<MAX; j++) {
    //             matC[i][j] += matA[i][j] * matB[j][i];
    //             for (int k = 0; k < MAX; k++){
    //                 // if(i%4 == 2) {
    //                     matC[i][j] += matA[i][k] * matB[k][j];
    //                 // } 
    //             }
    //             matC[i][j] += matA[i][j] * matB[j][i];
    //         }
    //     }
    // }

    // if(*tid == 3){
    //     for(int i = 0; i<MAX; i++){
    //         for(int j = 0; j<MAX; j++) {
    //             matC[i][j] += matA[i][j] * matB[j][i];
    //             for (int k = 0; k < MAX; k++){
    //                 // if(i%4 == 3) {
    //                     matC[i][j] += matA[i][k] * matB[k][j];
    //                 // } 
    //             }
    //             matC[i][j] += matA[i][j] * matB[j][i];
    //         }
    //     }
    // }
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