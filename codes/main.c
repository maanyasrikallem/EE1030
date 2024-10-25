#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include"libs/mathfun.h"
#include"libs/geofun.h"

int main() {
    // Define a 2x2 matrix
    double **matrix = createMat(2, 2);
    matrix[0][0] = 4; // a11
    matrix[0][1] = 1; // a12
    matrix[1][0] = 2; // a21
    matrix[1][1] = 3; // a22

    // Calculate eigenvalues
    double **eigenvalues = Mateigval(matrix);

    // Output results to output.dat
    FILE *file = fopen("output.dat", "w");
    if (file == NULL) {
        fprintf(stderr, "Error opening file!\n");
        return 1;
    }

    fprintf(file, "Eigenvalues:\n");
    fprintf(file, "λ1: %lf\n", eigenvalues[0][0]);
    fprintf(file, "λ2: %lf\n", eigenvalues[1][0]);

    fclose(file);

    // Free allocated memory
    freeMat(matrix, 2);
    freeMat(eigenvalues, 2);

    return 0;
}

