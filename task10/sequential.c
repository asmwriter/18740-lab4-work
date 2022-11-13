#include <stdio.h>
#include <stdlib.h>
#include <time.h>

long cnt = 123456789;
int AR_SIZE = 50;

int main() {
    time_t t;
    srand((unsigned) time(&t));
    volatile float arr[AR_SIZE];
    volatile float sum;
    volatile float arr_add = 0;
    int i,j;
    while (cnt--) {
        for (j = 0; j<AR_SIZE; j++) {
            arr[j] = rand();
        }
        for (i = 1; i <AR_SIZE; i++) {
            arr[i] *= arr[i-1] + i;
            sum = arr[i] + arr[i-1];
            arr[i] = arr[i-1]-1 * sum; 
            arr_add /= sum;
        }
    }
}