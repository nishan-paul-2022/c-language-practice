/*
 * Purpose: Calculates 'base' raised to the power of 'exponent' (base^exponent) using a loop.
 *          Handles positive, zero, and negative integer exponents.
 * Topic: Exponentiation, Loops, Floating-Point Arithmetic
 */

#include <stdio.h>
#include <math.h>

int main() {
    double base;         // The base number
    int exponent;        // The exponent
    double result = 1.0; // Initialize result to 1.0 for exponentiation

    printf("Enter the base (a double) and the exponent (an integer), separated by a comma (e.g., 2.5, 3): ");

    // Read the base and exponent
    if (scanf("%lf, %d", &base, &exponent) != 2) {
        printf("Invalid input format. Please enter in the format: base, exponent\n");
        return 0;
    }

    if (exponent == 0) {
        // Any number to the power of 0 is 1
        result = 1.0;
    } else if (exponent > 0) {
        // Positive exponent: multiply base by itself 'exponent' times
        for (int i = 0; i < exponent; i++) {
            result *= base;
        }
    } else { // exponent < 0
        // Negative exponent: calculate 1 / (base ^ |exponent|)
        // First, check for division by zero
        if (base == 0.0) {
            printf("Error: Division by zero is not allowed (0 raised to a negative power).\n");
            return 0;
        }
        // Calculate power with positive exponent, then take the reciprocal
        for (int i = 0; i < -exponent; i++) {
            result *= base;
        }
        result = 1.0 / result;
    }

    printf("%.2f ^ %d = %f\n", base, exponent, result);

    return 0;
}