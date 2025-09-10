/*
 * Purpose: Calculates the Greatest Common Divisor (GCD) of two integers using a while loop.
 * Topic: Loops, Conditional Operator (Ternary), Arithmetic Operators (Modulo)
 */

#include <stdio.h>

int main() {
    int num1, num2; // Two integer numbers for which to find the GCD
    int current_divisor; // Variable to iterate downwards from the smaller number

    // Prompt user to enter two integers
    printf("Enter two integers separated by a space (e.g., 48 18): ");
    // Read two integers from user input
    scanf("%d %d", &num1, &num2);

    // Initialize current_divisor with the smaller of the two numbers
    current_divisor = (num1 < num2) ? num1 : num2;

    // Loop downwards from current_divisor to find the GCD
    // The first number that divides both num1 and num2 is the GCD
    while (current_divisor >= 1) {
        if (num1 % current_divisor == 0 && num2 % current_divisor == 0) {
            break; // Found the GCD, exit the loop
        }
        current_divisor--; // Decrement to check the next smaller number
    }

    // Display the calculated GCD
    printf("The Greatest Common Divisor (GCD) of %d and %d is: %d\n", num1, num2, current_divisor);

    return 0;
}
