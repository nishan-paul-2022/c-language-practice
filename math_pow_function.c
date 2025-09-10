/*
 * Purpose: Demonstrates the use of the standard C library's pow() function for exponentiation.
 * Topic: Mathematical Functions, pow(), Loops
 */

#include <stdio.h>
#include <math.h>

int main() {
    double base, exponent, result; // Stores the base, exponent, and the final result

    // Loop until the user enters 0 for the base to exit.
    while (1) {
        printf("Enter the base and exponent (or 0 for base to exit): ");

        // Read and validate the base and exponent.
        if (scanf("%lf %lf", &base, &exponent) != 2) {
            printf("Invalid input. Please enter two numeric values.\n");
            // Clear the input buffer to prevent an infinite loop.
            while (getchar() != '\n');
            continue; // Restart the loop
        }

        // If the base is 0, exit the loop.
        if (base == 0.0) {
            printf("Exiting program.\n");
            break;
        }

        // Calculate the power using the pow() function.
        result = pow(base, exponent);

        // Print the final result.
        printf("Result: %.2lf\n\n", result);
    }

    return 0;
}