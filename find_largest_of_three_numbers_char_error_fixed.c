/*
 * Purpose: Reads three integers and determines the largest among them using nested ternary operators.
 *          This version fixes an issue where character types were incorrectly used for integer input/output.
 * Topic: Conditional Operator (Ternary), Basic I/O, Data Types
 */

#include <stdio.h>

// Finds the largest of three integers.
int find_largest(int a, int b, int c) {
    // Use nested ternary operators to find the largest number.
    return (a > b) ? ((a > c) ? a : c) : ((b > c) ? b : c);
}

int main(void) {
    int num1, num2, num3;

    // Prompt the user for input.
    printf("Enter three integers separated by spaces (e.g., 10 20 5): ");
    scanf("%d %d %d", &num1, &num2, &num3);

    // Find and display the largest number.
    int largest_number = find_largest(num1, num2, num3);
    printf("The largest number is: %d\n", largest_number);

    return 0;
}
