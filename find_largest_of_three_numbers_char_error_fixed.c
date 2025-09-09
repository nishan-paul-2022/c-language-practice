/*
 * Purpose: Reads three integers and determines the largest among them using nested ternary operators.
 *          This version fixes an issue where character types were incorrectly used for integer input/output.
 * Topic: Conditional Operator (Ternary), Basic I/O, Data Types
 */

#include <stdio.h> // Required for printf and scanf

int main() {
    int num1, num2, num3; // Three integer numbers to compare
    int largest_number;   // Stores the largest number

    // Prompt user for input
    printf("Enter three integers separated by spaces (e.g., 10 20 5): ");
    scanf("%d %d %d", &num1, &num2, &num3);

    // Find the largest number using nested ternary operators
    // If num1 > num2, then compare num1 with num3. Otherwise, compare num2 with num3.
    largest_number = (num1 > num2) ? ((num1 > num3) ? num1 : num3) : ((num2 > num3) ? num2 : num3);

    // Print the largest number found
    printf("The largest number is: %d\n", largest_number);

    return 0;
}
