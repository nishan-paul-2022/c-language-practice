/*
 * Purpose: Approximates the value of Euler's number (e) using its Taylor series expansion.
 * Topic: Series Approximation, Mathematical Constants
 */

#include <stdio.h>

int main(void) {
    double e = 1.0; // First term of series: 1/0! = 1
    double term = 1.0; // Current term in the series
    double factorial = 1.0; // Factorial for current term calculation
    int n = 1; // Series term index

    // Calculate e using Taylor series: e = 1 + 1/1! + 1/2! + 1/3! + ...
    while (1) {
        factorial *= n; // Calculate n!
        term = 1.0 / factorial; // Calculate 1/n!

        // Stop when term is negligible
        if (term < 0.000001) {
            break;
        }

        e += term; // Add term to approximation
        n++; // Increment term index
    }

    // Output result with high precision
    printf("Approximated value of e: %0.15lf\n", e);

    return 0;
}
