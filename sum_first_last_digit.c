// Purpose: Calculates the sum of the first and last digits of a given integer.
// Topic: Number Manipulation, Digits, Loops, Input/Output

#include <stdio.h>

int main() {
    int number;
    int first_digit = 0;
    int last_digit;
    int temp_number;
    int power_of_10 = 1;

    printf("Enter an integer: ");
    // Read the number from user input and validate
    if (scanf("%d", &number) != 1) {
        printf("Error: Invalid input. Please enter an integer.\n");
        return 1; // Indicate an error
    }

    // Handle negative numbers: sum of digits of absolute value
    temp_number = number;
    if (temp_number < 0) {
        temp_number = -temp_number;
    }

    // Get the last digit
    last_digit = temp_number % 10;

    // Find the first digit
    // Keep dividing by 10 until the number is less than 10
    while (temp_number >= 10) {
        temp_number /= 10;
    }
    first_digit = temp_number;

    // Calculate the sum of the first and last digits
    int sum_of_digits = first_digit + last_digit;

    printf("The sum of the first and last digits of %d is: %d\n", number, sum_of_digits);

    return 0; // Indicate successful execution
}
