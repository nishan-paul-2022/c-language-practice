/*
 * Purpose: Calculates the factorial of a non-negative integer using recursion.
 * Topic: Recursion, Mathematical Functions
 */

#include <stdio.h>

long long factorial(int n) {
    // Factorial is not defined for negative numbers
    if (n < 0) {
        return -1; // Error indicator
    }
    // Base case: factorial of 0 is 1
    if (n == 0) {
        return 1;
    }
    // Recursive step
    return (long long)n * factorial(n - 1);
}

int main(void) {
    int n;

    printf("Enter a non-negative integer: ");
    if (scanf("%d", &n) != 1) {
        printf("Invalid input. Please enter an integer.\n");
        return 0;
    }

    long long result = factorial(n);

    if (result == -1) {
        printf("Error: Factorial is not defined for negative numbers.\n");
    } else {
        printf("Factorial of %d is %lld\n", n, result);
    }

    return 0;
}
