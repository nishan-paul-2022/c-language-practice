/*
 * Purpose: Reads strings and determines if the last character (assumed to be a digit) is odd or even.
 * Topic: String Input, String Length, Character to Integer Conversion, Modulo Operator
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void) {
    int num_test_cases; // Number of test cases
    int test_case_index;
    char input_string[101]; // Input string buffer (max 100 chars + null terminator)
    int string_length; // Length of input string
    char last_digit_char; // Last character of string

    // Get number of test cases
    printf("Enter the number of test cases: ");
    if (scanf("%d", &num_test_cases) != 1) {
        printf("Error reading number of test cases.\n");
        return 0;
    }

    // Consume newline character left by scanf
    int c;
    while ((c = getchar()) != '\n' && c != EOF);

    // Process each test case
    for (test_case_index = 0; test_case_index < num_test_cases; test_case_index++) {
        // Get input string
        printf("Enter string for test case %d: ", test_case_index + 1);
        // Read string with buffer overflow protection
        if (scanf("%100s", input_string) != 1) {
            printf("Error reading string for test case %d.\n", test_case_index + 1);
            continue; // Skip to next test case if reading fails
        }

        // Consume leftover characters in input buffer
        while ((c = getchar()) != '\n' && c != EOF);

        // Get string length
        string_length = strlen(input_string);

        // Check if string is not empty and last character is a digit
        if (string_length > 0 && isdigit(input_string[string_length - 1])) {
            // Get last character
            last_digit_char = input_string[string_length - 1];

            // Convert character digit to integer
            // Subtracting '0' from digit character gives integer value
            int last_digit_int = last_digit_char - '0';

            // Check if digit is odd or even
            if (last_digit_int % 2 != 0) {
                printf("Result for test case %d: Odd\n", test_case_index + 1);
            } else {
                printf("Result for test case %d: Even\n", test_case_index + 1);
            }
        } else {
            // Handle empty string or non-digit last character
            printf("Invalid input for test case %d: String is empty or last character is not a digit.\n", test_case_index + 1);
        }
    }

    return 0;
}
