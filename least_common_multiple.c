/*
 * Purpose: Calculates the Least Common Multiple (LCM) of two integers.
 *          It first finds the Greatest Common Divisor (GCD) and then uses the formula:
 *          LCM(a, b) = (a * b) / GCD(a, b).
 * Topic: Loops, Conditional Statements, Arithmetic Operators (Modulo), GCD, LCM
 */

#include <stdio.h>

int main() {
    int num1, num2; // Two integer numbers for which to find the LCM
    int smaller_num; // Stores the smaller of the two numbers
    int gcd_val; // Stores the calculated GCD
    long long int lcm_result; // Stores the calculated LCM (using long long for potential larger values)

    // Prompt user for input
    printf("Enter two integers separated by a space (e.g., 12 18): ");
    scanf("%d %d", &num1, &num2);

    // Handle cases where one or both numbers are zero
    if (num1 == 0 || num2 == 0) {
        printf("LCM of 0 with any number is 0.\n");
        return 0;
    }

    // Determine the smaller number to start GCD iteration
    smaller_num = (num1 < num2) ? num1 : num2;

    // Find the GCD using an iterative approach
    for (gcd_val = smaller_num; gcd_val >= 1; gcd_val--) {
        if (num1 % gcd_val == 0 && num2 % gcd_val == 0) {
            break; // Found the GCD
        }
    }

    // Calculate LCM using the formula: LCM(a, b) = (a * b) / GCD(a, b)
    // Cast to long long int to prevent overflow before division, especially for large num1 * num2
    lcm_result = ((long long int)num1 * num2) / gcd_val;

    // Print the calculated LCM
    printf("The Least Common Multiple (LCM) of %d and %d is: %lld\n", num1, num2, lcm_result);

    return 0;
}
