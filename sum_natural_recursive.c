/*
 * Purpose: Calculates the sum of the first N natural numbers using recursion.
 * Topic: Recursion, Function Definition, Input Handling
 */

#include <stdio.h>

// Recursive function to calculate the sum of natural numbers from 1 to n.
// Base case: If n is 0, the sum is 0.
// Recursive step: For n > 0, the sum is n + sum of (n-1).
int sum_natural_numbers(int n) {
    // Base case: If n is 0, return 0.
    if (n == 0) {
        return 0;
    }
    // Recursive step: Add n to the sum of numbers from 1 to n-1.
    // This assumes n is positive. Negative input is handled in main.
    return n + sum_natural_numbers(n - 1);
}

int main(void) {
    int n; // The number up to which natural numbers are summed

    printf("Enter a positive integer to calculate the sum of natural numbers up to it: ");
    
    // Read the input and validate that it's an integer
    if (scanf("%d", &n) != 1) {
        fprintf(stderr, "Error: Invalid input. Please enter an integer.\n");
        return 0;
    }

    // Validate that the input is a non-negative integer
    if (n < 0) {
        fprintf(stderr, "Error: Please enter a non-negative integer.\n");
        return 0;
    }

    // Calculate and print the sum using the recursive function
    int sum = sum_natural_numbers(n);
    printf("The sum of the first %d natural numbers is: %d\n", n, sum);

    return 0;
}
