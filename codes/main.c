#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double **createMat(int m, int n) {
    double **mat = (double **)malloc(m * sizeof(double *));
    for (int i = 0; i < m; i++) {
        mat[i] = (double *)malloc(n * sizeof(double));
    }
    return mat;
}

double **Matquad(double a, double b, double c) {
    double **roots = createMat(2, 1); // Create a 2x1 matrix for the roots
    double discriminant = b * b - 4 * a * c;

    if (discriminant >= 0) {
        roots[0][0] = (-b + sqrt(discriminant)) / (2 * a);
        roots[1][0] = (-b - sqrt(discriminant)) / (2 * a);
    } else {
        roots[0][0] = -b / (2 * a); // Real part
        roots[1][0] = -b / (2 * a); // Real part
    }

    return roots;
}

double **Mateigval(double **a) {
    if (a == NULL || a[0] == NULL || a[1] == NULL) {
        return NULL; // Error handling
    }
    
    double a11 = a[0][0];
    double a12 = a[0][1];
    double a21 = a[1][0];
    double a22 = a[1][1];

    double trace = a11 + a22;
    double determinant = (a11 * a22) - (a12 * a21);

    double **eigenvalues = Matquad(-1 * trace, determinant, 1);
    
    return eigenvalues;
}

void freeMat(double **mat, int m) {
    for (int i = 0; i < m; i++) {
        free(mat[i]);
    }
    free(mat);
}

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

