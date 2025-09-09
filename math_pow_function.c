// Purpose: Demonstrates the use of the standard C library's pow() function for exponentiation.
// Topic: Mathematical Functions, pow(), Loops

#include <stdio.h>
#include <math.h> // For the pow() function

int main() {
    double base, exponent, result; // Variables for base, exponent, and the calculated result

    // Loop indefinitely until the user enters 0 for the base.
    while (1) {
        // Prompt the user to enter the base and exponent
        printf("Enter base and exponent (separated by a space, enter 0 for base to exit): ");

        // Read the base and exponent from the user.
        // Using %lf for double input. Added input validation.
        if (scanf("%lf %lf", &base, &exponent) != 2) {
            printf("Invalid input. Please enter two numbers for base and exponent.\n");
            // Clear the input buffer to prevent infinite loops on bad input
            while (getchar() != '\n');
            continue; // Skip the rest of the loop iteration
        }

        // Check if the base is zero. If so, exit the loop.
        if (base == 0.0) {
            printf("Exiting program.\n");
            break; // Exit the while loop
        }

        // Calculate base raised to the power of exponent using the pow() function.
        // pow(base, exponent) returns a double.
        result = pow(base, exponent);

        // Print the result.
        // Using %.2lf to display the result with two decimal places.
        printf("Result: %.2lf\n\n", result);
    }

    return 0;
}
