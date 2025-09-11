/*
 * Purpose: Converts a string representation of a number into an integer and finds all its divisors.
 * Topic: String to Integer Conversion, Loops, Divisors, Integer Arithmetic
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int main(void) {
    int num_test_cases;         // Variable to store the total number of test cases.
    int test_case_index;
    char input_string[7];       // Buffer to store the input string (max 6 chars + null terminator).
    int string_length;          // Variable to store the length of the input string.
    long number_from_string = 0; // Variable to store the integer converted from the string.
    int divisor;                // Loop variable for finding divisors.
    long power_of_10;           // To calculate powers of 10 for string to integer conversion.
    int digit_value;            // To store the integer value of a character digit.
    int char_index;

    // Prompt the user to enter the number of test cases.
    printf("Enter the number of test cases: ");
    // Read the number of test cases.
    if (scanf("%d", &num_test_cases) != 1) {
        printf("Error reading number of test cases.\n");
        return EXIT_FAILURE;
    }

    // Consume the newline character left by scanf for the integer.
    int c;
    while ((c = getchar()) != '\n' && c != EOF);

    // Loop through each test case.
    for (test_case_index = 0; test_case_index < num_test_cases; test_case_index++) {
        // Prompt the user to enter a string representing a number.
        printf("Enter number string for test case %d (max 6 digits): ", test_case_index + 1);
        // Read the string, preventing buffer overflow.
        if (scanf("%6s", input_string) != 1) {
            printf("Error reading string for test case %d.\n", test_case_index + 1);
            continue; // Skip to the next test case if reading fails.
        }

        // Consume any leftover characters in the input buffer.
        while ((c = getchar()) != '\n' && c != EOF);

        // --- String to Integer Conversion ---
        number_from_string = 0; // Reset for each test case.
        power_of_10 = 1;        // Start with 10^0.
        string_length = strlen(input_string);

        // Iterate through the string from right to left (least significant digit to most significant).
        for (char_index = string_length - 1; char_index >= 0; char_index--) {
            // Check if the character is a digit.
            if (input_string[char_index] >= '0' && input_string[char_index] <= '9') {
                digit_value = input_string[char_index] - '0'; // Convert char digit to int.
                number_from_string += digit_value * power_of_10; // Add to the total number.
                power_of_10 *= 10; // Increase the power of 10 for the next digit.
            } else {
                // If a non-digit character is found, treat it as an invalid input.
                printf("Invalid input for test case %d: '%s' contains non-digit characters.\n", test_case_index + 1, input_string);
                number_from_string = -1; // Mark as invalid.
                break; // Exit the inner loop.
            }
        }

        // Proceed only if the conversion was successful (number_from_string is not -1).
        if (number_from_string != -1) {
            printf("Case %d: Divisors of %ld are:", test_case_index + 1, number_from_string);

            // --- Finding Divisors ---
            // Iterate from 1 up to the number itself to find all divisors.
            // Optimization: Iterate up to sqrt(number_from_string) and find pairs of divisors.
            // For simplicity and directness matching the original logic, we'll iterate up to the number.
            // If optimization is needed, we'd check up to sqrt(number_from_string) and print both i and number_from_string/i.
            for (divisor = 1; divisor <= number_from_string; divisor++) {
                if (number_from_string % divisor == 0) {
                    printf(" %d", divisor);
                }
            }
            printf("\n");
        }
    }

    return 0;
}
