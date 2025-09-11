/*
 * Purpose: Implements the Fast Inverse Square Root algorithm.
 * Topic: Algorithms, Floating-Point Math, Bit Manipulation, Optimization
 */

#include <stdio.h>
#include <math.h>

// Function to calculate the fast inverse square root
float fast_inverse_sqrt(float number) {
    float x_half = 0.5f * number;
    // Use a union to reinterpret the bits of the float as an integer
    union {
        float f;
        int i;
    } conv;

    conv.f = number;
    // The magic number 0x5f3759df provides a good initial guess for the inverse square root
    // The bit shift (i >> 1) effectively divides the exponent by 2
    conv.i = 0x5f3759df - (conv.i >> 1);
    float y = conv.f;

    // One round of Newton's method to refine the approximation
    y = y * (1.5f - x_half * y * y);
    
    return y;
}

int main(void) {
    float input_number;
    float result_fast, result_accurate;

    printf("Enter a positive floating-point number: ");
    
    // Loop to process multiple inputs until a non-positive number is entered
    while (scanf("%f", &input_number) == 1 && input_number > 0) {
        result_fast = fast_inverse_sqrt(input_number);
        result_accurate = 1.0f / sqrtf(input_number); // For comparison

        printf("Input number: %f\n", input_number);
        printf("Fast Inverse Square Root: %f\n", result_fast);
        printf("Accurate Inverse Square Root (1/sqrt(x)): %f\n", result_accurate);
        printf("Difference: %e\n", fabsf(result_fast - result_accurate));
        
        printf("\nEnter a positive floating-point number (or non-positive to exit): ");
    }
    
    printf("Exiting.\n");
    return 0;
}
