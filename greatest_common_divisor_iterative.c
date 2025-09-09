/*
 * Purpose: Calculates the Greatest Common Divisor (GCD) of two integers using an iterative approach.
 * Topic: Loops, Conditional Statements, Arithmetic Operators (Modulo)
 */

#include <stdio.h>

int main() {
    int num1, num2; // Two integer numbers for which to find the GCD
    int larger_num; // Stores the larger of the two numbers
    int smaller_num; // Stores the smaller of the two numbers
    int gcd_result; // Stores the calculated GCD

    // Prompt user for input
    printf("Enter two integers separated by a space (e.g., 48 18): ");
    scanf("%d %d", &num1, &num2);

    // Determine the larger and smaller numbers
    larger_num = (num1 > num2) ? num1 : num2;
    smaller_num = (num1 < num2) ? num1 : num2;

    // Iterate downwards from the smaller number to find the GCD
    // The first number that divides both num1 and num2 is the GCD
    for (gcd_result = smaller_num; gcd_result >= 1; gcd_result--) {
        if (num1 % gcd_result == 0 && num2 % gcd_result == 0) {
            break; // Found the GCD, exit the loop
        }
    }

    // Print the calculated GCD
    printf("The Greatest Common Divisor (GCD) of %d and %d is: %d\n", num1, num2, gcd_result);

    return 0;
}
