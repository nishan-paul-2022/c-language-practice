/*
 * Purpose: Demonstrates usage of various standard C math functions.
 * Topic: Math Functions
 */

#include <stdio.h>
#include <math.h>

int read_input_values(double *angle_rad, double *sine_value, double *base, double *exponent) {
    printf("Enter values for angle (radians), sine, base, and exponent: ");
    if (scanf("%lf %lf %lf %lf", angle_rad, sine_value, base, exponent) != 4) {
        fprintf(stderr, "Error: Invalid input. Please enter four numeric values.\n");
        return -1;
    }
    return 0;
}

void demonstrate_trig_functions(double angle_rad, double sine_value, double base, double exponent) {
    printf("\n--- Trigonometric and Power Functions ---\n");
    printf("Sine of %.2f = %.4f\n", angle_rad, sin(angle_rad));
    printf("Arcsine of %.2f = %.4f radians\n", sine_value, asin(sine_value));
    printf("Power of %.2f^%.2f = %.4f\n", base, exponent, pow(base, exponent));
}

void demonstrate_misc_functions(void) {
    double remainder_val = 10.57;
    double atan2_y = 1.0;
    double atan2_x = 0.0;

    printf("\n--- Remainder and Angle Functions ---\n");
    printf("Remainder of %.2f / 3.0 = %.4f\n", remainder_val, fmod(remainder_val, 3.0));
    printf("Arctangent of y=%.2f, x=%.2f = %.4f radians\n", atan2_y, atan2_x, atan2(atan2_y, atan2_x));
}

int main(void) {
    double angle_rad, sine_value, base, exponent;

    if (read_input_values(&angle_rad, &sine_value, &base, &exponent) == -1) {
        return 0;
    }

    demonstrate_trig_functions(angle_rad, sine_value, base, exponent);
    demonstrate_misc_functions();

    return 0;
}
