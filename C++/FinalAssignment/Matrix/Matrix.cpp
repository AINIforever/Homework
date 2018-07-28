#include "Matrix.h"
#include <stdio.h>

void printMatrix(double **matrix , int n ){
    for (int i = 0; i<n; i++) {
        for (int j=0; j<n; j++) {
            printf("%f\t",matrix[i][j]);
        }
        printf("\n");
    }
}

double **allocMatrix(int n){
	sz = n;
    double **matrix = new double*[n+1];
    
    for (int i = 0; i<n; i++) {
        matrix[i] = new double[n];
    }
    matrix[n] = NULL;
    
    for (int i = 0; i<n; i++) {
        for (int j=0; j<n; j++) {
            matrix[i][j] = i+0.1*j;
        }
    }
    return matrix;
}


void releaseMatrix(double **m){
    for (int i = 0; i<sz; i++) {
        delete[] m[i];
        m[i] = NULL;
    }
    delete []m; 
    m = NULL;
}

