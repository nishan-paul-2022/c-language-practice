/*
 * Purpose: Calculates the length of a string using recursion.
 * Topic: Recursion, String Manipulation
 */

#include <stdio.h>

// Function to calculate the length of a string recursively
int recursive_string_length(const char *str) {
    // Base case: if the current character is the null terminator, return 0
    if (*str == '\0') {
        return 0;
    } else {
        // Recursive step: return 1 (for the current character) + the length of the rest of the string
        return 1 + recursive_string_length(str + 1);
    }
}

int main(void) {
    char input_string[1000]; // Buffer to store user input

    printf("Enter a string: ");
    // Use fgets for safe input to prevent buffer overflows
    if (fgets(input_string, sizeof(input_string), stdin) != NULL) {
        // Remove the trailing newline character if fgets read one
        // Find the newline character
        char *newline = input_string;
        while (*newline != '\n' && *newline != '\0') {
            newline++;
        }
        // If a newline was found, replace it with a null terminator
        if (*newline == '\n') {
            *newline = '\0';
        }

        // Calculate the length of the string using the recursive function
        int len = recursive_string_length(input_string);

        printf("The length of the string is: %d\n", len);
    } else {
        printf("Error reading input.\n");
        return 0;
    }

    return 0;
}
