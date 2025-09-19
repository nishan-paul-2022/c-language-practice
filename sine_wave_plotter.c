/*
 * Purpose: Visualizes a sine wave by printing asterisks at scaled positions.
 * Topic: Trigonometry, Loops, Math Functions, Output Formatting
 */

#include <stdio.h>
#include <math.h>

#ifndef M_PI
#define M_PI 3.1416
#endif

double degrees_to_radians(int degrees) {
    double radians = (M_PI / 180.0) * degrees;
    return radians;
}

int calculate_scaled_position(double sine_val, double amplitude, int offset) {
    int scaled_pos = (int)round(amplitude * sine_val) + offset;
    return scaled_pos;
}

void print_spaces(int count) {
    for (int j = 0; j < count; j++) {
        printf(" ");
    }
}

void display_sine_wave(int max_degrees, int step, double amplitude) {
    const int OFFSET = (int)amplitude; // Center the wave

    printf("Sine Wave Plot (0 to %d degrees):\n", max_degrees);
    printf("-----------------------------------\n");
    
    for (int i = 0; i <= max_degrees; i += step) {
        double angle_rad = degrees_to_radians(i);
        double sine_val = sin(angle_rad);
        int scaled_pos = calculate_scaled_position(sine_val, amplitude, OFFSET);

        if (scaled_pos >= 0) {
            print_spaces(scaled_pos);
            printf("*");
        }

        printf(" (%d°)\n", i);
    }

    printf("-----------------------------------\n");
}

int main(void) {
    const double AMPLITUDE = 50.0;
    const int DEGREE_STEP = 15;
    const int MAX_DEGREES = 720;

    display_sine_wave(MAX_DEGREES, DEGREE_STEP, AMPLITUDE);

    return 0;
}
