#include <iostream>
#include "Matrix.h"

int size; 
int main() {
    
    double **Matrix;
    
    std::cout<< "Please input the matirx size. "<< std::endl;
    std::cin>> size;
    Matrix = allocMatrix(size);
    printMatrix(Matrix, size);
    releaseMatrix(Matrix);

    return 0;
}
