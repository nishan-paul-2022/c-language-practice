// Purpose: Demonstrates the usage of various standard C math functions.
// Topic: Math Functions

#include <stdio.h>
#include <math.h>

int main() {
    double angle_rad;      // Input for trigonometric functions (in radians)
    double sine_value;     // Input for inverse trigonometric functions
    double base;           // Base for the power function
    double exponent;       // Exponent for the power function
    double remainder_val;  // Value for fmod function
    double atan2_y, atan2_x; // Values for atan2 function

    printf("Enter four double values separated by spaces (e.g., 1.57 0.5 2.0 3.0): ");
    // Read input values. Check if scanf successfully read all four values.
    if (scanf("%lf %lf %lf %lf", &angle_rad, &sine_value, &base, &exponent) != 4) {
        fprintf(stderr, "Error: Invalid input. Please enter four double values.\n");
        return 1; // Indicate an error
    }

    // Demonstrate various math functions
    printf("sin(%.2f) = %.4f\n", angle_rad, sin(angle_rad));
    printf("asin(%.2f) = %.4f radians\n", sine_value, asin(sine_value));
    printf("pow(%.2f, %.2f) = %.4f\n", base, exponent, pow(base, exponent));
    
    // fmod example: remainder of 10.57 divided by 3
    remainder_val = 10.57;
    printf("fmod(%.2f, %.2f) = %.4f\n", remainder_val, 3.0, fmod(remainder_val, 3.0));
    
    // atan2 example: angle for point (1, 0)
    atan2_y = 1.0;
    atan2_x = 0.0;
    printf("atan2(%.2f, %.2f) = %.4f radians\n", atan2_y, atan2_x, atan2(atan2_y, atan2_x));

    return 0;
}
