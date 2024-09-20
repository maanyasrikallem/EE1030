#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "libs/mathfun.h"

// Function prototypes
double **createMat(int m,int n);
void freeMat(double **matrix, int m);
void findFourthVertex(double **A, double **B, double **C, double **D);

// Function to free a matrix of size m x n
void freeMat(double **matrix, int m) {
    for (int i = 0; i < m; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

// Function to find the fourth vertex D of the parallelogram
void findFourthVertex(double **A, double **B, double **C, double **D) {
    // Midpoint of diagonal AC
    double midpoint_AC_x = (A[0][0] + C[0][0]) / 2;
    double midpoint_AC_y = (A[1][0] + C[1][0]) / 2;

    // Calculate D using the midpoint property
    D[0][0] = 2 * midpoint_AC_x - B[0][0];
    D[1][0] = 2 * midpoint_AC_y - B[1][0];
}

int main() {
    // Coordinates of vertices A, B, and C
    double a_coords[2] = {1.0, 3.0};
    double b_coords[2] = {-1.0, 2.0};
    double c_coords[2] = {2.0, 5.0};

    // Create matrices for vertices
    double **A = createMat(2, 1);
    double **B = createMat(2, 1);
    double **C = createMat(2, 1);
    double **D = createMat(2, 1);

    A[0][0] = a_coords[0];
    A[1][0] = a_coords[1];

    B[0][0] = b_coords[0];
    B[1][0] = b_coords[1];

    C[0][0] = c_coords[0];
    C[1][0] = c_coords[1];

    // Find the fourth vertex D
    findFourthVertex(A, B, C, D);

    // Open a file to write the output
    FILE *file = fopen("output.dat", "w");
    if (file == NULL) {
        fprintf(stderr, "Error opening file for writing.\n");
        return 1;
    }

    // Write the coordinates of the fourth vertex D to the file
    fprintf(file, "The coordinates of the fourth vertex D are: (%.2f, %.2f)\n", D[0][0], D[1][0]);

    // Close the file
    fclose(file);

    // Free allocated memory
    freeMat(A, 2);
    freeMat(B, 2);
    freeMat(C, 2);
    freeMat(D, 2);

    return 0;
}

