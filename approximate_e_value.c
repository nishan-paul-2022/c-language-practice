/*
 * Purpose: Approximates the value of Euler's number (e) using its Taylor series expansion.
 * Topic: Series Approximation, Mathematical Constants
 */

#include <stdio.h>

int main(void) {
    double e = 1.0;          // Initialize e with the first term (1/0!)
    double term = 1.0;       // Initialize the current term (1/n!)
    double factorial = 1.0;  // Initialize factorial for the current term
    int n = 1;               // Start with the second term (1/1!)

    // Calculate terms of the Taylor series for e: e = 1 + 1/1! + 1/2! + 1/3! + ...
    // The loop continues as long as the calculated term is significant.
    while (1) {
        factorial *= n;      // Calculate n!
        term = 1.0 / factorial; // Calculate the current term (1/n!)

        // If the term becomes very small, we can stop adding it as it won't significantly change 'e'
        if (term < 0.000001) { // Using a slightly smaller threshold for better precision
            break;
        }

        e += term;           // Add the current term to e
        n++;                 // Move to the next term
    }

    // Print the approximated value of e with high precision
    printf("Approximated value of e: %0.15lf\n", e);

    return 0; // Indicate successful execution
}
