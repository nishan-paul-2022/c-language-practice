// Purpose: Checks if a given string is a palindrome.
// Topic: String manipulation, palindrome checking, loops, input/output.

#include <stdio.h>
#include <string.h> // For strlen and strcspn

#define BUFFER_SIZE 256 // Define a reasonable buffer size for input strings

// Function to check if a string is a palindrome
// Returns 1 if it's a palindrome, 0 otherwise.
int is_palindrome(const char *str) {
    int len = strlen(str);
    int i;

    // Handle empty string or single character string as palindromes
    if (len <= 1) {
        return 1;
    }

    // Compare characters from the beginning and end, moving inwards
    for (i = 0; i < len / 2; i++) {
        // If characters do not match, it's not a palindrome
        if (str[i] != str[len - 1 - i]) {
            return 0; // Not a palindrome
        }
    }

    return 1; // It's a palindrome
}

int main() {
    char input_string[BUFFER_SIZE];
    int continue_processing = 1; // Flag to control the loop

    printf("Enter strings to check if they are palindromes. Type 'quit' to exit.\\n");

    while (continue_processing) {
        printf("Enter a string: ");
        // Use fgets for safe input
        if (fgets(input_string, BUFFER_SIZE, stdin) == NULL) {
            printf("Error reading input.\\n");
            continue_processing = 0; // Exit on error
            break;
        }

        // Remove the trailing newline character if it exists
        input_string[strcspn(input_string, "\\n")] = 0;

        // Check for exit condition
        if (strcmp(input_string, "quit") == 0) {
            continue_processing = 0; // Set flag to exit loop
            break;
        }

        // Check if the string is a palindrome using the helper function
        if (is_palindrome(input_string)) {
            printf("Result: PALIN\\n");
        } else {
            printf("Result: ERROR\\n"); // Using ERROR to indicate "not a palindrome" as per original code's output style
        }
    }

    printf("Exiting program.\\n");
    return 0; // Indicate successful execution
}
