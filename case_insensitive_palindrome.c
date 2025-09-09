// Purpose: Checks if a given string is a palindrome, ignoring case.
// Topic: Strings, Character Handling, Loops, Conditional Logic

#include <stdio.h>
#include <string.h>
#include <ctype.h> // For tolower() function

int main() {
    int num_test_cases; // Number of test cases
    int i;              // Loop counter for test cases

    // Read the number of test cases
    scanf("%d", &num_test_cases);

    // Consume the newline character left by the previous scanf
    // This is important if subsequent inputs are read with fgets or similar,
    // but for scanf("%s"), it's less critical as %s skips leading whitespace.
    // However, it's good practice for robustness.
    // while (getchar() != '\n' && getchar() != EOF); // More robust way to clear buffer

    // Process each test case
    for (i = 0; i < num_test_cases; i++) {
        char input_string[100]; // Buffer to store the input string
        int string_length;      // Length of the input string
        int is_palindrome = 1;  // Flag to indicate if the string is a palindrome
        int left_index, right_index; // Pointers for comparison

        // Read the string
        scanf("%99s", input_string); // %99s to prevent buffer overflow

        string_length = strlen(input_string);

        // Convert all characters to lowercase for case-insensitive comparison
        for (left_index = 0; left_index < string_length; left_index++) {
            input_string[left_index] = tolower(input_string[left_index]);
        }

        // Check for palindrome property
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

        // Print the result
        if (is_palindrome) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }

    return 0;
}
