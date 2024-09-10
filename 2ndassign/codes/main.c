#include <stdio.h>

// Function prototype
void findFourthVertex(double x1, double y1, double x2, double y2, double x3, double y3, double* x4, double* y4);

int main() {
    double x1, y1, x2, y2, x3, y3;
    double x4, y4;

    // Input coordinates of the three vertices
    printf("Enter the coordinates of the first vertex (x1 y1): ");
    scanf("%lf %lf", &x1, &y1);

    printf("Enter the coordinates of the second vertex (x2 y2): ");
    scanf("%lf %lf", &x2, &y2);

    printf("Enter the coordinates of the third vertex (x3 y3): ");
    scanf("%lf %lf", &x3, &y3);

    // Calculate the coordinates of the fourth vertex
    findFourthVertex(x1, y1, x2, y2, x3, y3, &x4, &y4);

    // Display the result
    printf("The coordinates of the fourth vertex are (%.2lf, %.2lf)\n", x4, y4);

    return 0;
}

// Function definition
void findFourthVertex(double x1, double y1, double x2, double y2, double x3, double y3, double* x4, double* y4) {
    *x4 = x1 - x2 + x3;
    *y4 = y1 - y2 + y3;
}
