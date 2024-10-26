#include <stdio.h>
#include <stdlib.h>
#include "func.c" // Include the functions from func.c

int main() {
    // Open output file
    FILE *file = fopen("output.dat", "w");
    if (file == NULL) {
        fprintf(stderr, "Error opening output file.\n");
        return 1;
    }

    // Define a point and a circle
    Point p = {1.0, 2.0};
    Circle c = {{1.0, -3.0}, 3.0}; // Center at (1, -3) with radius 3

    // Determine the position of the point relative to the circle
    int position = point_position(p, c);
    if (position == -1) {
        fprintf(file, "Point P is inside the circle.\n");
    } else if (position == 0) {
        fprintf(file, "Point P is on the circle.\n");
    } else {
        fprintf(file, "Point P is outside the circle.\n");
    }

    // Close the output file
    fclose(file);
    return 0;
}

