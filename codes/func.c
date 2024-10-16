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

