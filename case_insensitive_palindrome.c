/*
 * Purpose: Checks if a given string is a palindrome, ignoring case.
 * Topic: Strings, Character Handling, Loops, Conditional Logic
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    int num_test_cases;
    int i;

    printf("Enter the number of test cases: ");
    if (scanf("%d", &num_test_cases) != 1) {
        printf("Error: Invalid input for number of test cases.\n");
        return 1;
    }

    // Process each test case
    for (i = 0; i < num_test_cases; i++) {
        char input_string[100];
        printf("Enter string %d: ", i + 1);
        if (scanf("%99s", input_string) != 1) {
            printf("Error: Invalid input for string.\n");
            continue;
        }

        // Convert to lowercase for case-insensitive comparison
        int string_length = strlen(input_string);
        for (int i = 0; i < string_length; i++) {
            input_string[i] = tolower(input_string[i]);
        }

        // Check palindrome property
        int left_index = 0;
        int right_index = string_length - 1;
        int is_palindrome = 1;

        while (left_index < right_index) {
            if (input_string[left_index] != input_string[right_index]) {
                is_palindrome = 0; // Not a palindrome
                break;
            }
            left_index++;
            right_index--;
        }

        printf("String \"%s\" is %s a palindrome.\n", input_string, is_palindrome ? "" : "not");
    }

    return 0;
}
