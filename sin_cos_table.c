/*
 * Purpose: To calculate and print a table of sine and cosine values.
 * Topic: Math functions, Loops
 */

#include <stdio.h>
#include <math.h>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

int main() {
    int max_angle;
    int angle;
    double radians, sin_val, cos_val;

    printf("ENTER ANGLE IN DEGREE: ");
    scanf("%d", &max_angle);

    printf("\n angle \t sin \t\t cos \n");
    printf("----------------------------------\n");

    for (angle = 0; angle <= max_angle; angle += 10) {
        radians = (M_PI * angle) / 180.0;
        sin_val = sin(radians);
        cos_val = cos(radians);
        printf(" %d \t %lf \t %lf \n", angle, sin_val, cos_val);
    }

    return 0;
}
