/*
 * Purpose: Calculates the power of a number (base raised to an exponent) using a recursive function.
 * Topic: Recursion, Arithmetic Operations
 */

#include <stdio.h> // Required for printf and scanf

// Recursive function to calculate base^exponent
// base: the base number
// exponent: the power to which the base is raised
int calculate_power_recursive(int base, int exponent) {
    // Base case: if exponent is 0, any base raised to 0 is 1
    if (exponent == 0) {
        return 1;
    }
    // Recursive step: base * (base^(exponent-1))
    else {
        return base * calculate_power_recursive(base, exponent - 1);
    }
}

int main() {
    int base_number;     // The base for the power calculation
    int exponent_number; // The exponent for the power calculation
    int result_power;    // Stores the calculated power

    // Prompt user for input
    printf("Enter the base and exponent (e.g., 2 3 for 2^3): ");
    scanf("%d %d", &base_number, &exponent_number);

    // Handle negative exponents (optional, but good practice for a complete power function)
    // For simplicity, this example assumes non-negative exponents as per the original code's logic.
    if (exponent_number < 0) {
        printf("Error: This program calculates power for non-negative exponents only.\n");
        return 0;
    }

    // Call the recursive function to calculate the power
    result_power = calculate_power_recursive(base_number, exponent_number);

    // Print the calculated result
    printf("%d raised to the power of %d is: %d\n", base_number, exponent_number, result_power);

    return 0;
}
