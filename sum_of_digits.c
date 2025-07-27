#include <stdio.h>

// Purpose: Calculates the sum of the digits of a given integer.
// Topic: Integer Manipulation, Loops
int main() {
    int number;
    int digit_sum = 0;

    // Prompt user for input
    printf("Enter an integer: ");
    // Use " %d" to consume any leading whitespace, including newlines
    if (scanf(" %d", &number) != 1) {
        printf("Invalid input. Please enter an integer.\n");
        return 1; // Indicate an error
    }

    // Handle negative numbers by taking the absolute value for digit sum calculation
    int temp_number = number;
    if (temp_number < 0) {
        temp_number = -temp_number;
    }

    // Calculate the sum of digits
    while (temp_number > 0) {
        digit_sum += temp_number % 10; // Add the last digit
        temp_number /= 10;             // Remove the last digit
    }

    // Print the result
    printf("The sum of the digits of %d is: %d\n", number, digit_sum);

    return 0; // Indicate successful execution
}
