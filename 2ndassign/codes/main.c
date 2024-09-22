#include <stdio.h>
#include<math.h>
#include <stdlib.h>
#include "libs/mathfun.h"


// Function to free allocated memory for a matrix
void freeMat(double **mat, int m) {
    for (int i = 0; i < m; i++) {
        free(mat[i]);
    }
    free(mat);
}


// Function to find the fourth vertex of a parallelogram
double **findFourthVertex(double **A, double **B, double **C) {
    double **scaledB = Matscale(B, 1, 2, 1.0); // Scale B by 1 (no change)
    double **D = Matadd(A, C, 1, 2);
    double **finalD = Matadd(D, scaledB, 1, 2);
    
    // Free the scaledB and intermediate D matrices
    freeMat(scaledB, 1);
    freeMat(D, 1);
    
    return finalD;
}

int main() {
    // Initialize points A, B, C
    double **A = createMat(1, 2);
    double **B = createMat(1, 2);
    double **C = createMat(1, 2);
    
    A[0][0] = 1; A[0][1] = 3;  // Point A
    B[0][0] = -1; B[0][1] = 2; // Point B
    C[0][0] = 2; C[0][1] = 5;  // Point C
    
    // Finding the fourth vertex D
    double **D = findFourthVertex(A, B, C);
    
    // Open file for writing
    FILE *file = fopen("output.dat", "w");
    if (file == NULL) {
        fprintf(stderr, "error opening file for writing");
        return 1;
    }

    // Writing the result to the file
    fprintf(file, "The coordinates of the fourth vertex D are: (%.2f, %.2f)\n", D[0][0], D[0][1]);
    
    // Close the file
    fclose(file);
    
    // Free allocated memory
    freeMat(A, 1);
    freeMat(B, 1);
    freeMat(C, 1);
    freeMat(D, 1);
    
    return 0;
}

