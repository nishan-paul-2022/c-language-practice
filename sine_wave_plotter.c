/*
 * Purpose: Visualizes a sine wave by printing asterisks at scaled positions.
 * Topic: Trigonometry, Loops, Math Functions, Output Formatting
 */

#include <stdio.h>
#include <math.h>

#ifndef M_PI
#define M_PI 3.1416
#endif

int main(void) {
    const double AMPLITUDE = 50.0;
    const int DEGREE_STEP = 15;
    int i, scaled_pos;
    double angle_rad, sine_val;

    printf("Sine Wave Plot:\n");
    printf("----------------\n");

    for (i = 0; i <= 180; i += DEGREE_STEP) {
        angle_rad = (M_PI / 180.0) * i;
        sine_val = sin(angle_rad);
        scaled_pos = (int)round(AMPLITUDE * sine_val);

        for (int j = 0; j < scaled_pos; j++) {
            printf(" ");
        }
        printf("*\n");
    }

    printf("----------------\n");
    return 0;
}
