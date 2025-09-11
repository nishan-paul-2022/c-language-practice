/*
 * Purpose: Calculates the area and circumference of a circle given its radius.
 * Topic: Input/Output, Basic Geometry, Floating-Point Numbers
 */

#include <stdio.h>

// Define PI constant for readability and precision
#define PI 3.14159265358979323846

int main(void) {
    float radius;
    float area;
    float circumference;

    printf("Enter the radius of the circle: ");
    if (scanf("%f", &radius) != 1) {
        printf("Invalid input. Please enter a numeric value for the radius.\n");
        return 0;
    }

    if (radius < 0) {
        printf("Radius cannot be negative. Please enter a non-negative value.\n");
        return 0;
    }

    area = PI * radius * radius;
    circumference = 2 * PI * radius;

    printf("Area: %.2f\n", area);
    printf("Circumference: %.2f\n", circumference);

    return 0;
}
