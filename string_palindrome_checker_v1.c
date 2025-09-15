/*
 * Purpose: Checks if a given string is a palindrome.
 * Topic: String manipulation, palindrome checking, loops, input/output.
 */

#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 256

// Function to check if a string is a palindrome
int is_palindrome(const char *str) {
    int len = strlen(str);

    // Handle empty string or single character string as palindromes
    if (len <= 1) {
        return 1;
    }

    // Compare characters from the beginning and end, moving inwards
    for (int i = 0; i < len / 2; i++) {
        if (str[i] != str[len - 1 - i]) {
            return 0; // Not a palindrome
        }
    }

    return 1;
}

int main(void) {
    char input_string[BUFFER_SIZE];
    int continue_processing = 1;

    printf("Enter strings to check if they are palindromes.\n");

    while (continue_processing) {
        printf("Enter a string: ");

        // Read input safely using fgets
        if (fgets(input_string, BUFFER_SIZE, stdin) == NULL) {
            printf("Error reading input.\n");
            continue_processing = 0;
            break;
        }

        // Remove the trailing newline character if it exists
        input_string[strcspn(input_string, "\n")] = 0;

        // Exit condition
        if (strcmp(input_string, "quit") == 0) {
            continue_processing = 0;
            break;
        }

        // Check palindrome
        if (is_palindrome(input_string)) {
            printf("Result: Palindrome\n");
        } else {
            printf("Result: Error\n");
        }
    }

    printf("Ending program\n");
    return 0;
}
