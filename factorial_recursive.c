/*
 * Purpose: Calculates the factorial of a non-negative integer using recursion.
 * Topic: Recursion, Mathematical Functions
 */

#include <stdio.h>

// Function to calculate factorial recursively
// Returns -1 for negative input, and the factorial value for non-negative input.
// Note: Factorials grow very rapidly. For inputs larger than 20, 'long long' will overflow.
long long calculate_factorial_recursive(int n) {
    // Base case: Factorial of 0 is 1.
    if (n == 0) {
        return 1;
    }
    // Error case: Factorial is not defined for negative numbers.
    else if (n < 0) {
        return -1; // Indicate an error
    }
    // Recursive step: n! = n * (n-1)!
    else {
        // Check for potential overflow before multiplication
        long long prev_factorial = calculate_factorial_recursive(n - 1);
        if (prev_factorial == -1) { // Propagate error if n-1 was negative
            return -1;
        }
        // Check for overflow: if prev_factorial * n exceeds the max value of long long
        // A simple check: if n > LLONG_MAX / prev_factorial (requires limits.h)
        // For simplicity here, we'll assume inputs are within reasonable bounds for long long.
        // A more robust solution would use __builtin_mul_overflow or a BigInt library.
        return (long long)n * prev_factorial;
    }
}

int main(void) {
    int n;
    long long factorial_result;

    // Prompt user for input
    printf("Enter a non-negative integer to calculate its factorial: ");
    
    // Read input
    if (scanf("%d", &n) != 1) {
        printf("Invalid input. Please enter an integer.\n");
        return 1; // Indicate input error
    }

    // Calculate factorial
    factorial_result = calculate_factorial_recursive(n);

    // Print the result or an error message
    if (factorial_result == -1) {
        printf("Factorial is not defined for negative numbers.\n");
    } else {
        printf("Factorial of %d is %lld\n", n, factorial_result);
    }

    return 0;
}
