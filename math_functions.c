/*
 * Purpose: Demonstrates usage of various standard C math functions.
 * Topic: Math Functions
 */

#include <stdio.h>
#include <math.h>

void demonstrate_trig_functions() {
    double angle_rad = 1.57; 
    double sine_value = 0.5; 
    double base = 2.0; 
    double exponent = 3.0; 

    printf("\n--- Trigonometric and Power Functions ---\n");
    printf("Sine of %.2f | %.2f\n", angle_rad, sin(angle_rad));
    printf("Arcsine of %.2f | %.2f radians:\n", sine_value, asin(sine_value));
    printf("Power of %.2f^%.2f | %.2f\n", base, exponent, pow(base, exponent));
}

void demonstrate_misc_functions() {
    double remainder_val = 10.57;
    double division_val = 3.0;
    double atan2_y = 1.0;
    double atan2_x = 0.0;

    printf("\n--- Remainder and Angle Functions ---\n");
    printf("Remainder of %.2f / %.2f | %.2f\n", remainder_val, division_val, fmod(remainder_val, division_val));
    printf("Arctangent of y=%.2f, x=%.2f | %.2f radians\n", atan2_y, atan2_x, atan2(atan2_y, atan2_x));
}

int main(void) {
    demonstrate_trig_functions();
    demonstrate_misc_functions();

    return 0;
}