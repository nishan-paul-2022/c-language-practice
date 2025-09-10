/*
 * Purpose: Checks if a given string is a palindrome, ignoring case.
 * Topic: Strings, Character Handling, Loops, Conditional Logic
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    int num_test_cases; // Number of test cases
    int i;

    // Read number of test cases
    printf("Enter the number of test cases: ");
    if (scanf("%d", &num_test_cases) != 1) {
        printf("Error: Invalid input for number of test cases.\n");
        return 1;
    }

    // Process each test case
    for (i = 0; i < num_test_cases; i++) {
        char input_string[100]; // Buffer for input string
        int string_length;      // Length of input string
        int is_palindrome = 1;  // Flag for palindrome check
        int left_index, right_index; // Comparison pointers

        // Read string with buffer overflow protection
        printf("Enter string %d: ", i + 1);
        if (scanf("%99s", input_string) != 1) {
            printf("Error: Invalid input for string.\n");
            continue;
        }

        string_length = strlen(input_string);

        // Convert to lowercase for case-insensitive comparison
        for (left_index = 0; left_index < string_length; left_index++) {
            input_string[left_index] = tolower(input_string[left_index]);
        }

        // Check palindrome property
        left_index = 0;
        right_index = string_length - 1;

        while (left_index < right_index) {
            if (input_string[left_index] != input_string[right_index]) {
                is_palindrome = 0; // Not a palindrome
                break;
            }
            left_index++;
            right_index--;
        }

        // Print result
        printf("String \"%s\" is %sa palindrome.\n", input_string, is_palindrome ? "" : "not ");
    }

    return 0;
}
