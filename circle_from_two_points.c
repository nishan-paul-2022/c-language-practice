/*
 * Purpose: To calculate the perimeter and area of a circle given two points on its circumference.
 * Topic: Math functions, Basic I/O
 */

#include <stdio.h>
#include <math.h>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

int main() {
    float x1, y1, x2, y2, radius, perimeter, area;

    printf("Enter the coordinates of the first point (x1 y1): ");
    scanf("%f %f", &x1, &y1);

    printf("Enter the coordinates of the second point (x2 y2): ");
    scanf("%f %f", &x2, &y2);

    radius = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
    perimeter = 2 * M_PI * radius;
    area = M_PI * pow(radius, 2);

    printf("Perimeter: %f\nArea: %f\n", perimeter, area);

    return 0;
}
