#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define n 2048

double A[n][n];
double B[n][n];
double C[n][n];

int main() {

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {

            A[i][j] = (double) rand() / (double) RAND_MAX;
            B[i][j] = (double) rand() / (double) RAND_MAX;
            C[i][j] = 0;
        }
    }

    //matrix multiplication
    for (int j = 0; j < n; j++) {
        for (int k = 0; k < n; k+=10) {
            for (int i = 0; i < n; i++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return 0;
}