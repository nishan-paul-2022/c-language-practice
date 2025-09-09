/*
 * Purpose: Calculates and prints the GCD and LCM of two integers iteratively.
 * Topic: Arithmetic Operations, Iteration, GCD, LCM
 */

#include <stdio.h>
#include <stdlib.h> // For exit()

// Function to calculate the Greatest Common Divisor (GCD) of two non-negative integers iteratively.
// Uses the Euclidean algorithm.
long long calculate_gcd(long long num1, long long num2) {
    // Ensure inputs are non-negative for standard GCD definition
    if (num1 < 0) num1 = -num1;
    if (num2 < 0) num2 = -num2;

    // Handle cases where one or both numbers are zero
    if (num1 == 0 && num2 == 0) return 0; // GCD(0,0) is often considered 0
    if (num1 == 0) return num2;
    if (num2 == 0) return num1;

    long long temp;
    while (num2 != 0) {
        temp = num2;
        num2 = num1 % num2;
        num1 = temp;
    }
    return num1; // num1 now holds the GCD
}

// Function to calculate the Least Common Multiple (LCM) of two non-negative integers.
// LCM(a, b) = (|a * b|) / GCD(a, b)
long long calculate_lcm(long long num1, long long num2, long long gcd_val) {
    // Handle cases where one or both numbers are zero
    if (num1 == 0 || num2 == 0) {
        return 0; // LCM(a, 0) = 0
    }
    // Avoid potential overflow by dividing first if possible, though here we use long long
    // The formula is |num1 * num2| / gcd_val
    // Ensure gcd_val is not zero to avoid division by zero, though calculate_gcd handles this.
    if (gcd_val == 0) return 0; // Should not happen if num1 or num2 is non-zero

    // Use unsigned long long for intermediate product to prevent overflow if possible
    unsigned long long product = (unsigned long long)num1 * num2;
    return (long long)(product / gcd_val);
}

int main() {
    long long number1, number2;
    long long gcd_result, lcm_result;

    // Loop to allow multiple calculations until user chooses to exit
    while (1) {
        printf("\nEnter two integers separated by a comma (e.g., 12, 18) or type '0, 0' to exit: ");

        // Read input and check if it's valid
        if (scanf("%ld, %ld", &number1, &number2) != 2) {
            fprintf(stderr, "Error: Invalid input format. Please enter two integers separated by a comma.\n");
            // Clear the input buffer to prevent infinite loop on bad input
            while (getchar() != '\n');
            continue; // Ask for input again
        }

        // Exit condition
        if (number1 == 0 && number2 == 0) {
            printf("Exiting program.\n");
            break;
        }

        // Calculate GCD
        gcd_result = calculate_gcd(number1, number2);

        // Calculate LCM
        lcm_result = calculate_lcm(number1, number2, gcd_result);

        // Print the results
        printf("GCD: %lld, LCM: %lld\n", gcd_result, lcm_result);
    }

    return 0;
}
