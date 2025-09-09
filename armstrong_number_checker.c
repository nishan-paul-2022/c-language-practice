/*
 * Purpose: Checks if a given positive integer is an Armstrong number.
 *          An Armstrong number is a number that is the sum of its own digits,
 *          each raised to the power of the number of digits.
 * Topic: Loops, Arithmetic Operations, String Conversion, Digit Manipulation
 */

#include <stdio.h> // Required for printf, scanf, sprintf
#include <string.h> // Required for strlen
#include <math.h> // Required for pow (though custom power function is better for integers)

// Function to calculate integer power (base^exponent)
long long int integer_power(int base, int exponent) {
    long long int result = 1;
    for (int i = 0; i < exponent; i++) {
        result *= base;
    }
    return result;
}

int main() {
    int original_number; // The number input by the user
    int temp_number; // Temporary variable for digit extraction
    int num_digits = 0; // Number of digits in the input number
    long long int sum_of_powers = 0; // Sum of digits raised to the power of num_digits
    char num_as_string[20]; // Buffer to store the number as a string (max 19 digits for long long)

    // Prompt user for input
    printf("Enter a positive integer to check if it's an Armstrong number: ");
    scanf("%d", &original_number);

    // Handle negative numbers or zero
    if (original_number < 0) {
        printf("%d is not a positive integer.\n", original_number);
        return 1;
    }
    if (original_number == 0) {
        printf("0 is an Armstrong number.\n"); // 0^1 = 0
        return 0;
    }

    // Convert the number to a string to find the number of digits
    sprintf(num_as_string, "%d", original_number);
    num_digits = strlen(num_as_string);

    // Reset temp_number to the original number for digit extraction
    temp_number = original_number;

    // Extract digits and calculate the sum of powers
    while (temp_number > 0) {
        int digit = temp_number % 10; // Get the last digit
        sum_of_powers += integer_power(digit, num_digits); // Add digit^num_digits to sum
        temp_number /= 10; // Remove the last digit
    }

    // Compare the sum of powers with the original number
    if (sum_of_powers == original_number) {
        printf("%d is an Armstrong number.\n", original_number);
    } else {
        printf("%d is Not an Armstrong number.\n", original_number);
    }

    return 0; // Indicate successful execution
}
