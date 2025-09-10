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
    scanf("%d", &num_test_cases);

    // Process each test case
    for (i = 0; i < num_test_cases; i++) {
        char input_string[100]; // Buffer for input string
        int string_length;      // Length of input string
        int is_palindrome = 1;  // Flag for palindrome check
        int left_index, right_index; // Comparison pointers

        // Read string with buffer overflow protection
        scanf("%99s", input_string);

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
        if (is_palindrome) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }

    return 0;
}
