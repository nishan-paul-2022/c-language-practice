/*
 * Purpose: Calculates the perimeter and area of a circle given two points on its circumference.
 * Topic: Math Functions, Basic I/O, Geometry
 */

#include <stdio.h>
#include <math.h>

#define PI 3.1416

int main(void) {
    float x1, y1, x2, y2;
    
    printf("Circle Calculator from Two Points\n");
    printf("Enter the coordinates of the first point (x1 y1): ");
    scanf("%f %f", &x1, &y1);
    
    printf("Enter the coordinates of the second point (x2 y2): ");
    scanf("%f %f", &x2, &y2);
    
    float radius = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
    float perimeter = 2 * PI * radius;
    float area = PI * pow(radius, 2);
    
    printf("Circle Properties:\n");
    printf("Perimeter: %.2f\n", perimeter);
    printf("Area: %.2f\n", area);
    
    return 0;
}
