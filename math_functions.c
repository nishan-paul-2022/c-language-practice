/*
 * Purpose: Demonstrates usage of various standard C math functions.
 * Topic: Math Functions
 */

#include <stdio.h>
#include <math.h>

int main(void) {
    double angle_rad; // Angle in radians for trigonometric functions
    double sine_value; // Value for inverse trigonometric functions
    double base; // Base for the power function
    double exponent; // Exponent for the power function
    double remainder_val; // Value for the fmod function
    double atan2_y, atan2_x; // y and x coordinates for the atan2 function

    printf("Enter values for angle (radians), sine, base, and exponent: ");
    // Read and validate all four input values.
    if (scanf("%lf %lf %lf %lf", &angle_rad, &sine_value, &base, &exponent) != 4) {
        fprintf(stderr, "Error: Invalid input. Please enter four numeric values.\n");
        return 0;
    }

    // --- Demonstrate Math Functions ---
    printf("\n--- Trigonometric and Power Functions ---\n");
    printf("Sine of %.2f = %.4f\n", angle_rad, sin(angle_rad));
    printf("Arcsine of %.2f = %.4f radians\n", sine_value, asin(sine_value));
    printf("Power of %.2f^%.2f = %.4f\n", base, exponent, pow(base, exponent));
    
    // Calculate the remainder of 10.57 / 3.0
    remainder_val = 10.57;
    printf("\n--- Remainder and Angle Functions ---\n");
    printf("Remainder of %.2f / 3.0 = %.4f\n", remainder_val, fmod(remainder_val, 3.0));
    
    // Calculate the angle for point (y=1.0, x=0.0)
    atan2_y = 1.0;
    atan2_x = 0.0;
    printf("Arctangent of y=%.2f, x=%.2f = %.4f radians\n", atan2_y, atan2_x, atan2(atan2_y, atan2_x));

    return 0;
}