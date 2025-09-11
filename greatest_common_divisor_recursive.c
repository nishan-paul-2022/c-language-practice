/*
 * Purpose: Calculates the Greatest Common Divisor (GCD) of two integers using a recursive function.
 * Topic: Recursion, Arithmetic Operators (Modulo)
 */

#include <stdio.h>

// Recursive function to find the GCD of two numbers
// This implementation uses the property that GCD(a, b) = GCD(b, a % b)
// and GCD(a, 0) = a.
int find_gcd_recursive(int num1, int num2) {
    // Base case: if num2 is 0, then num1 is the GCD
    if (num2 == 0) {
        return num1;
    }
    // Recursive step: call the function with num2 and the remainder of num1 divided by num2
    return find_gcd_recursive(num2, num1 % num2);
}

int main(void) {
    int number1, number2; // Two integer numbers for which to find the GCD
    int gcd_result; // Stores the calculated GCD

    // Prompt user to enter two integers
    printf("Enter two integers separated by a space (e.g., 48 18): ");
    // Read two integers from user input
    scanf("%d %d", &number1, &number2);

    // Handle cases where inputs are negative or zero for GCD
    // The Euclidean algorithm works with non-negative integers.
    // abs() from stdlib.h can be used if negative inputs are expected.
    // For simplicity, assuming positive inputs for this example.
    if (number1 < 0) number1 = -number1;
    if (number2 < 0) number2 = -number2;

    // If both numbers are 0, GCD is typically undefined or 0.
    if (number1 == 0 && number2 == 0) {
        printf("GCD of 0 and 0 is undefined (or 0 by some definitions).\n");
        return 0;
    }

    // Call the recursive function to find the GCD
    gcd_result = find_gcd_recursive(number1, number2);

    // Display the calculated GCD
    printf("The Greatest Common Divisor (GCD) of %d and %d is: %d\n", number1, number2, gcd_result);

    return 0;
}
