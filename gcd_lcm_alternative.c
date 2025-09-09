/*
 * Purpose: Calculates the Greatest Common Divisor (GCD) and Least Common Multiple (LCM) of two numbers using an alternative approach for GCD.
 * Topic: Number Theory, GCD, LCM, Input Handling
 */
#include <stdio.h>
#include <stdlib.h> // For EXIT_SUCCESS and EXIT_FAILURE

// Function to calculate GCD using the Euclidean algorithm
long int calculate_gcd(long int a, long int b) {
    // Ensure a and b are non-negative for the algorithm
    if (a < 0) a = -a;
    if (b < 0) b = -b;

    // Handle cases where one or both numbers are zero
    if (a == 0 && b == 0) return 0; // GCD of 0 and 0 is undefined, returning 0 for simplicity
    if (a == 0) return b;
    if (b == 0) return a;

    // Euclidean algorithm
    while (b != 0) {
        long int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Function to calculate LCM using the formula: LCM(a, b) = |a * b| / GCD(a, b)
long int calculate_lcm(long int a, long int b, long int gcd) {
    if (gcd == 0) return 0; // Avoid division by zero if GCD is 0
    // Use absolute values for calculation to handle negative inputs correctly
    long int abs_a = (a < 0) ? -a : a;
    long int abs_b = (b < 0) ? -b : b;
    return (abs_a / gcd) * abs_b; // Prevent potential overflow by dividing first
}

int main() {
    long int num1, num2;
    long int gcd_result, lcm_result;

    printf("Enter pairs of numbers (e.g., '12, 18') or press Ctrl+D (Unix/Linux) or Ctrl+Z (Windows) to exit.\n");

    // Read pairs of numbers until EOF is encountered or an error occurs
    while (scanf("%ld, %ld", &num1, &num2) == 2) {
        gcd_result = calculate_gcd(num1, num2);
        lcm_result = calculate_lcm(num1, num2, gcd_result);

        printf("For %ld and %ld:\n", num1, num2);
        if (gcd_result == 0) {
            printf("  GCD: Undefined (both numbers are 0)\n");
            printf("  LCM: Undefined (both numbers are 0)\n");
        } else {
            printf("  GCD: %ld\n", gcd_result);
            printf("  LCM: %ld\n", lcm_result);
        }
    }

    // Check if the loop terminated due to an error other than reaching EOF
    if (ferror(stdin)) {
        perror("Error reading input");
        return EXIT_FAILURE;
    }

    printf("Exiting program.\n");
    return 0;
}
