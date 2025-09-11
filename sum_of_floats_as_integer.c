/*
 * Purpose: Reads two floating-point numbers, calculates their sum, and prints the sum as an integer.
 *          This demonstrates implicit type conversion (truncation) from float to int.
 * Topic: Basic I/O, Data Types, Type Conversion
 */

#include <stdio.h>

int main(void) {
    float first_number;  // First floating-point number input by user
    float second_number; // Second floating-point number input by user
    int sum_as_integer;  // Variable to store the sum after converting to integer

    // Prompt user for input
    printf("Enter two floating-point values (e.g., 10.5 2.3): \n");
    scanf("%f %f", &first_number, &second_number);

    // Calculate the sum of the two floating-point numbers
    // The result is implicitly cast to an integer, truncating any decimal part.
    sum_as_integer = (int)(first_number + second_number);

    // Print the sum as an integer
    printf("The sum of the two numbers (truncated to integer) is: %d\n", sum_as_integer);

    return 0;
}
