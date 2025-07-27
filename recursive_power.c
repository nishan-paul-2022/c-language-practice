// Purpose: Calculates x raised to the power of y using recursion.
// Topic: Recursion, Mathematical Functions

#include <stdio.h>

// Recursive function to calculate power (base^exponent)
// Returns 1 if exponent is 0.
// Otherwise, returns base * power(base, exponent - 1).
int power_recursive(int base, int exponent) {
    // Base case: any number to the power of 0 is 1.
    if (exponent == 0) {
        return 1;
    }
    // Recursive step: base * power(base, exponent - 1)
    else {
        // Ensure exponent is non-negative for this implementation.
        // For negative exponents, a different approach (using doubles and division) would be needed.
        if (exponent < 0) {
            printf("Error: Exponent must be non-negative for this function.\n");
            return -1; // Indicate an error
        }
        return base * power_recursive(base, exponent - 1);
    }
}

int main() {
    int base, exponent, power_result; // Variables for base, exponent, and the result

    // Prompt the user to enter the base and exponent
    printf("Enter the base and exponent (separated by a space): ");

    // Read the base and exponent from the user.
    // Added input validation for scanf.
    if (scanf("%d %d", &base, &exponent) != 2) {
        printf("Invalid input. Please enter two integers for base and exponent.\n");
        return 1; // Indicate an error
    }

    // Calculate the power using the recursive function
    power_result = power_recursive(base, exponent);

    // Print the result if no error occurred
    if (power_result != -1) {
        printf("%d raised to the power of %d is: %d\n", base, exponent, power_result);
    }

    return 0; // Indicate successful execution
}
