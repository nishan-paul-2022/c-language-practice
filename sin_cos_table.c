/*
 * Purpose: To calculate and print a table of sine and cosine values.
 * Topic: Math functions, Loops
 */

#include <stdio.h>
#include <math.h>

#ifndef M_PI
#define M_PI 3.1416
#endif

int main(void) {
    int max_angle;

    printf("Enter maximum angle in degrees: ");

    if (scanf("%d", &max_angle) != 1) {
        printf("Invalid input.\n");
        return 0;
    }

    printf("\nAngle\tSin\t\tCos\n");
    printf("--------------------------------\n");

    for (int angle = 0; angle <= max_angle; angle += 10) {
        double radians = (M_PI * angle) / 180.0;
        double sin_val = sin(radians);
        double cos_val = cos(radians);
        
        printf("%d\t%lf\t%lf\n", angle, sin_val, cos_val);
    }

    return 0;
}
