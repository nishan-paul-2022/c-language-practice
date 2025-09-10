/*
 * Purpose: Calculates the perimeter and area of a circle given two points on its circumference.
 * Topic: Math Functions, Basic I/O, Geometry
 */

#include <stdio.h>
#include <math.h>

// Define M_PI constant if not already defined
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

int main() {
    float x1, y1, x2, y2, radius, perimeter, area;

    // Get coordinates of first point
    printf("Enter the coordinates of the first point (x1 y1): ");
    scanf("%f %f", &x1, &y1);

    // Get coordinates of second point
    printf("Enter the coordinates of the second point (x2 y2): ");
    scanf("%f %f", &x2, &y2);

    // Calculate radius as distance between the two points
    radius = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
    // Calculate perimeter and area using radius
    perimeter = 2 * M_PI * radius;
    area = M_PI * pow(radius, 2);

    // Print results
    printf("Perimeter: %f\nArea: %f\n", perimeter, area);

    return 0;
}
