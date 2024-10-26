#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    double x;
    double y;
} Point;

typedef struct {
    Point center;
    double radius;
} Circle;

int point_position(Point p, Circle c) {
    double distance_squared = (p.x - c.center.x) * (p.x - c.center.x) + 
                              (p.y - c.center.y) * (p.y - c.center.y);
    double radius_squared = c.radius * c.radius;

    if (distance_squared < radius_squared) {
        return -1; // Inside
    } else if (distance_squared == radius_squared) {
        return 0; // On the circle
    } else {
        return 1; // Outside
    }
}

