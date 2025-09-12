/*
 * Purpose: Calculates and prints the length of a given string.
 * Topic: String Manipulation, String Length Calculation, Input Validation
 */

#include <stdio.h>
#include <string.h>

// Calculates and prints the length of a user-provided string.
void finda_and_print_string_length() {
    char input_string[256]; // Define a buffer for the input string.
    
    // Prompt the user to enter a string.
    printf("Enter a string:\n");

    // Read the input string safely.
    if (fgets(input_string, sizeof(input_string), stdin) == NULL) {
        // Handle potential input errors.
        fprintf(stderr, "Error reading input string.\n");
        return;
    }

    // Remove the trailing newline character, if present.
    input_string[strcspn(input_string, "\n")] = '\0';

    // Calculate and print the string's length.
    printf("%zu\n", strlen(input_string));
}

int main(void) {
    finda_and_print_string_length();
    return 0;
}
