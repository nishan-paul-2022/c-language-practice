/*
 * Purpose: Calculates the sum of natural numbers from 1 up to a given integer 'n' using an iterative while loop.
 * Topic: Loops, Arithmetic Operations
 */

#include <stdio.h> // Required for printf and scanf

int main() {
    int input_number; // The number up to which to calculate the sum
    int sum_result = 0; // Variable to store the sum, initialized to 0

    // Prompt user for input
    printf("Enter a non-negative integer to calculate the sum of natural numbers up to it: ");
    scanf("%d", &input_number);

    // Validate input: sum is typically defined for non-negative integers
    if (input_number < 0) {
        printf("Error: Input must be a non-negative integer.\n");
        return 0;
    }

    // Loop to calculate the sum iteratively
    // The loop continues as long as input_number is greater than 0
    while (input_number > 0) {
        sum_result += input_number; // Add the current number to the sum
        input_number--;             // Decrement the number
    }

    // Print the calculated result
    printf("The sum of natural numbers up to the original number is: %d\n", sum_result);

    return 0;
}
