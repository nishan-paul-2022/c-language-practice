/*
 * Purpose: Calculates the power of a number (base raised to an exponent) using a recursive function.
 * Topic: Recursion, Arithmetic Operations
 */

#include <stdio.h>

int calculate_power_recursive(int base, int exponent) {
    if (exponent == 0) {
        return 1;
    }
    int ans = base * calculate_power_recursive(base, exponent - 1);
    return ans;
}

int main(void) {
    int base_number, exponent_number;

    printf("Enter the base and exponent (e.g., 2 3 for 2^3): ");
    scanf("%d %d", &base_number, &exponent_number);

    if (exponent_number < 0) {
        printf("Error: This program calculates power for non-negative exponents only.\n");
        return 0;
    }

    int result_power = calculate_power_recursive(base_number, exponent_number);
    printf("%d raised to the power of %d is: %d\n", base_number, exponent_number, result_power);

    return 0;
}
