/*
 * Purpose: Implements the Fast Inverse Square Root algorithm.
 * Topic: Algorithms, Floating-Point Math, Bit Manipulation, Optimization
 */

#include <stdio.h>
#include <math.h>

// Calculate fast inverse square root
float fast_inverse_sqrt(float number) {
    float number_half = 0.5f * number;
    // Reinterpret float bits as integer
    union {
        float f;
        int i;
    } conv;

    // Magic number for initial guess
    conv.i = 0x5f3759df - (conv.i >> 1);
    conv.f = number;

    // Refine with Newton's method
    float y = conv.f;
    y = y * (1.5f - number_half * y * y);
    
    return y;
}

int main(void) {
    float input_number;
    float result_fast, result_accurate;

    printf("Enter a positive floating-point number: ");
    
    // Process inputs until non-positive number
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
