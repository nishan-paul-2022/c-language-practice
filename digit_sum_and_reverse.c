/*
 * Purpose: Calculates the sum of digits and reverses a given integer.
 * Topic: Number Manipulation, Loops, Functions, Input/Output
 */

#include <stdio.h>
#include <math.h>

// Function to calculate the sum of digits of a number
long int sum_digits(long int num) {
    long int sum = 0;
    long int temp_num = num; // Use a temporary variable to avoid modifying the original number

    // Handle negative numbers by taking the absolute value for digit sum
    if (temp_num < 0) {
        temp_num = -temp_num;
    }

    // Iterate while the number is greater than 0
    while (temp_num > 0) {
        sum += temp_num % 10; // Add the last digit to the sum
        temp_num /= 10;       // Remove the last digit
    }
    return sum;
}

// Function to reverse a number
long int reverse_number(long int num) {
    long int reversed_num = 0;
    long int temp_num = num; // Use a temporary variable

    // Handle negative numbers: reverse the absolute value and keep the sign
    int sign = 1;
    if (temp_num < 0) {
        sign = -1;
        temp_num = -temp_num;
    }

    // Iterate while the number is greater than 0
    while (temp_num > 0) {
        reversed_num = reversed_num * 10 + temp_num % 10; // Append the last digit to the reversed number
        temp_num /= 10;                                  // Remove the last digit
    }
    return sign * reversed_num; // Return the reversed number with its original sign
}

int main() {
    long int number;
    long int sum_of_digits;
    long int reversed_number;

    printf("Enter an integer: ");
    // Read the number from user input and validate
    if (scanf("%ld", &number) != 1) {
        printf("Error: Invalid input. Please enter a long integer.\n");
        return 0;
    }

    // Calculate the sum of digits
    sum_of_digits = sum_digits(number);

    // Reverse the number
    reversed_number = reverse_number(number);

    // Print the results
    printf("Sum of digits: %ld\n", sum_of_digits);
    printf("Reversed number: %ld\n", reversed_number);

    return 0;
}
