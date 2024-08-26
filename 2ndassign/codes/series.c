#include <stdio.h>

// Function to calculate the fourth vertex D
void findFourthVertex(int xA, int yA, int xB, int yB, int xC, int yC, int *xD, int *yD) {
    // Calculate the midpoint M of diagonal AC
    float Mx = (xA + xC) / 2.0;
    float My = (yA + yC) / 2.0;
    
    // Calculate the coordinates of D using the midpoint method
    *xD = 2 * Mx - xB;
    *yD = 2 * My - yB;
}

int main() {
    // Coordinates of the given vertices
    int xA = 1, yA = 3;  // Coordinates of A
    int xB = -1, yB = 2; // Coordinates of B
    int xC = 2, yC = 5;  // Coordinates of C
    
    // Variables to hold the coordinates of the fourth vertex D
    int xD, yD;

    // Calculate the fourth vertex D
    findFourthVertex(xA, yA, xB, yB, xC, yC, &xD, &yD);

    // Output the coordinates to a text file
    FILE *file = fopen("coordinates.txt", "w");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    fprintf(file, "A: (%d, %d)\n", xA, yA);
    fprintf(file, "B: (%d, %d)\n", xB, yB);
    fprintf(file, "C: (%d, %d)\n", xC, yC);
    fprintf(file, "D: (%d, %d)\n", xD, yD);

    fclose(file);

    printf("Coordinates have been written to coordinates.txt\n");

    return 0;
}

