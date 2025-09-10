/*
 * Purpose: Calculates the Greatest Common Divisor (GCD) of two integers, handling negative inputs
 *          by taking their absolute values. Uses an iterative approach.
 * Topic: Loops, Conditional Statements, Arithmetic Operators (Modulo), Absolute Value
 */

#include <stdio.h>
#include <stdlib.h>

int main() {
    int num1, num2; // Two integer numbers for which to find the GCD
    int abs_num1, abs_num2; // Absolute values of num1 and num2
    int smaller_abs_num; // Stores the smaller of the two absolute numbers
    int gcd_result; // Stores the calculated GCD

    // Prompt user to enter two integers
    printf("Enter two integers separated by a space (e.g., -48 18): ");
    // Read two integers from user input
    scanf("%d %d", &num1, &num2);

    // Get the absolute values of the numbers
    abs_num1 = abs(num1);
    abs_num2 = abs(num2);

    // Handle cases where one or both numbers are zero
    if (abs_num1 == 0 && abs_num2 == 0) {
        printf("GCD of 0 and 0 is undefined (or 0 by some definitions).\n");
        return 0;
    } else if (abs_num1 == 0) {
        // Display GCD when first number is zero
        printf("The Greatest Common Divisor (GCD) of %d and %d is: %d\n", num1, num2, abs_num2);
        return 0;
    } else if (abs_num2 == 0) {
        // Display GCD when second number is zero
        printf("The Greatest Common Divisor (GCD) of %d and %d is: %d\n", num1, num2, abs_num1);
        return 0;
    }

    // Determine the smaller of the two absolute numbers
    smaller_abs_num = (abs_num1 < abs_num2) ? abs_num1 : abs_num2;

    // Iterate downwards from the smaller absolute number to find the GCD
    for (gcd_result = smaller_abs_num; gcd_result >= 1; gcd_result--) {
        if (abs_num1 % gcd_result == 0 && abs_num2 % gcd_result == 0) {
            break; // Found the GCD, exit the loop
        }
    }

    // Display the calculated GCD
    printf("The Greatest Common Divisor (GCD) of %d and %d is: %d\n", num1, num2, gcd_result);

    return 0;
}
