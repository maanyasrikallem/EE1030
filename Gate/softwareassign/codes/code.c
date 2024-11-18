#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define MAX_SIZE 100
#define TOLERANCE 1e-6
#define MAX_ITERATIONS 1000

// Function prototypes
void qrDecomposition(int n, double A[MAX_SIZE][MAX_SIZE], double Q[MAX_SIZE][MAX_SIZE], double R[MAX_SIZE][MAX_SIZE]);
void matrixMultiply(int n, double A[MAX_SIZE][MAX_SIZE], double B[MAX_SIZE][MAX_SIZE], double result[MAX_SIZE][MAX_SIZE]);
void printMatrix(int n, double matrix[MAX_SIZE][MAX_SIZE]);
int isConverged(int n, double A[MAX_SIZE][MAX_SIZE], double B[MAX_SIZE][MAX_SIZE]);

int main() {
   
    double A[MAX_SIZE][MAX_SIZE], Q[MAX_SIZE][MAX_SIZE], R[MAX_SIZE][MAX_SIZE];
    double Ak[MAX_SIZE][MAX_SIZE], temp[MAX_SIZE][MAX_SIZE];
    int iterations = 0;

    // First take input for knowing the size of the matrix 
    printf("Enter the size for square matrix (n): ");
     int n;
    scanf("%d", &n);

    // Take input of all elements in the matrix
    printf("Enter the elements for %dx%d matrix:\n", n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%lf", &A[i][j]);
            Ak[i][j] = A[i][j]; 
        }
    }

    // Start of QR Algorithm
    while (iterations < MAX_ITERATIONS) {
        // Performing the QR decomposition
        qrDecomposition(n, Ak, Q, R);

        // Update Ak as R * Q
        matrixMultiply(n, R, Q, temp);
        if (isConverged(n, Ak, temp)) {
            break; 
        }

        // Copy temp to Ak
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                Ak[i][j] = temp[i][j];
            }
        }

        iterations++;
    }

   
    printf("\nEigenvalues after %d iterations:\n", iterations);
    for (int i = 0; i < n; i++) {
        printf("%lf\n", Ak[i][i]); // Eigenvalues are the diagonal elements of Ak
    }

    return 0;
}

void qrDecomposition(int n, double A[MAX_SIZE][MAX_SIZE], double Q[MAX_SIZE][MAX_SIZE], double R[MAX_SIZE][MAX_SIZE]) {
    double u[MAX_SIZE], norm;
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            u[i] = A[i][k];
        }

        for (int j = 0; j < k; j++) {
            double dot = 0;
            for (int i = 0; i < n; i++) {
                dot += Q[i][j] * u[i];
            }
            R[j][k] = dot;
            for (int i = 0; i < n; i++) {
                u[i] -= dot * Q[i][j];
            }
        }

        norm = 0;
        for (int i = 0; i < n; i++) {
            norm += u[i] * u[i];
        }
        norm = sqrt(norm);

        for (int i = 0; i < n; i++) {
            Q[i][k] = u[i] / norm;
        }
        R[k][k] = norm;

        for (int i = k + 1; i < n; i++) {
            R[k][i] = 0;
        }
    }
}

void matrixMultiply(int n, double A[MAX_SIZE][MAX_SIZE], double B[MAX_SIZE][MAX_SIZE], double result[MAX_SIZE][MAX_SIZE]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            result[i][j] = 0;
            for (int k = 0; k < n; k++) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

int isConverged(int n, double A[MAX_SIZE][MAX_SIZE], double B[MAX_SIZE][MAX_SIZE]) {
    double maxDiff = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            double diff = fabs(A[i][j] - B[i][j]);
            if (diff > maxDiff) {
                maxDiff = diff;
            }
        }
    }
    return maxDiff < TOLERANCE;
}
