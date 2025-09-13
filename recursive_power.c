/*
 * Purpose: Calculates x raised to the power of y using recursion.
 * Topic: Recursion, Mathematical Functions
 */

#include <stdio.h>

// Recursive function to calculate base^exponent (exponent >= 0)
int power_recursive(int base, int exponent) {
    if (exponent < 0) { // Only non-negative exponents allowed
        printf("Error: Exponent must be non-negative.\n");
        return -1;
    }
    if (exponent == 0) return 1; // Base case: any number^0 = 1
    return base * power_recursive(base, exponent - 1); // Recursive step
}

int main(void) {
    int base, exponent, power_result;

    printf("Enter the base and exponent (space separated): ");
    if (scanf("%d %d", &base, &exponent) != 2) {
        printf("Invalid input. Enter two integers.\n");
        return 0;
    }

    power_result = power_recursive(base, exponent);
    if (power_result != -1) {
        printf("%d raised to the power of %d is: %d\n", base, exponent, power_result);
    }

    return 0;
}
