// Purpose: Calculates the sum of the digits of a non-negative integer.
// Topic: Arithmetic Operations, Loops, Modulo and Division, Input Handling

#include <stdio.h>

int main() {
    int input_number;       // The number entered by the user
    int original_number;    // To store the original number for display
    int sum_of_digits = 0;  // Accumulator for the sum of digits
    int current_digit;      // To store the current digit being processed

    printf("Enter a non-negative integer: ");
    
    // Read the input number and validate that it's an integer
    if (scanf("%d", &input_number) != 1) {
        fprintf(stderr, "Error: Invalid input. Please enter an integer.\n");
        return 1; // Indicate an error
    }

    // Validate that the input is non-negative
    if (input_number < 0) {
        fprintf(stderr, "Error: Please enter a non-negative integer.\n");
        return 1; // Indicate an error
    }

    original_number = input_number; // Store the original number for the final output

    // Loop to extract digits and sum them up
    // The loop continues as long as there are digits left in the number
    while (input_number > 0) {
        current_digit = input_number % 10; // Get the last digit
        sum_of_digits += current_digit;    // Add the digit to the sum
        input_number /= 10;                // Remove the last digit (integer division)
    }

    // Special case: if the input was 0, the sum of digits is 0.
    // The loop above would not execute for input_number = 0.
    if (original_number == 0) {
        sum_of_digits = 0;
    }

    printf("The sum of the digits of %d is: %d\n", original_number, sum_of_digits);

    return 0;
}
