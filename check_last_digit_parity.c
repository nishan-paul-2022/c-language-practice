/*
 * Purpose: Reads strings and determines if the last character (assumed to be a digit) is odd or even.
 * Topic: String Input, String Length, Character to Integer Conversion, Modulo Operator
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    int num_test_cases; // Variable to store the total number of test cases.
    int test_case_index;
    char input_string[101]; // Buffer to store the input string (max 100 chars + null terminator).
    int string_length; // Variable to store the length of the input string.
    char last_digit_char; // Variable to store the last character of the string.

    // Prompt the user to enter the number of test cases.
    printf("Enter the number of test cases: ");
    // Read the number of test cases.
    if (scanf("%d", &num_test_cases) != 1) {
        printf("Error reading number of test cases.\n");
        return 0;
    }

    // Consume the newline character left by scanf for the integer.
    // This is important to prevent issues with subsequent string reads.
    int c;
    while ((c = getchar()) != '\n' && c != EOF);

    // Loop through each test case.
    for (test_case_index = 0; test_case_index < num_test_cases; test_case_index++) {
        // Prompt the user to enter a string for the current test case.
        printf("Enter string for test case %d: ", test_case_index + 1);
        // Read the string, preventing buffer overflow.
        if (scanf("%100s", input_string) != 1) {
            printf("Error reading string for test case %d.\n", test_case_index + 1);
            continue; // Skip to the next test case if reading fails.
        }

        // Consume any leftover characters in the input buffer, including the newline.
        while ((c = getchar()) != '\n' && c != EOF);

        // Get the length of the string.
        string_length = strlen(input_string);

        // Check if the string is not empty and if the last character is a digit.
        if (string_length > 0 && isdigit(input_string[string_length - 1])) {
            // Get the last character.
            last_digit_char = input_string[string_length - 1];

            // Convert the character digit to an integer.
            // Subtracting '0' from a digit character gives its integer value.
            int last_digit_int = last_digit_char - '0';

            // Check if the integer digit is odd or even.
            if (last_digit_int % 2 != 0) {
                printf("Result for test case %d: Odd\n", test_case_index + 1);
            } else {
                printf("Result for test case %d: Even\n", test_case_index + 1);
            }
        } else {
            // Handle cases where the string is empty or the last character is not a digit.
            printf("Invalid input for test case %d: String is empty or last character is not a digit.\n", test_case_index + 1);
        }
    }

    return 0;
}
