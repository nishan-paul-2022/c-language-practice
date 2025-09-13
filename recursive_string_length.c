/*
 * Purpose: Calculates the length of a string using recursion.
 * Topic: Recursion, String Manipulation
 */

#include <stdio.h>
#include <string.h>

#define MAX_STRING_SIZE 1000

// Recursive function to calculate string length
int recursive_string_length(const char *str) {
    if (*str == '\0') return 0; // Base case: null terminator
    return 1 + recursive_string_length(str + 1); // Recursive step
}

// Function to safely read a string from input
int read_input_string(char *buffer, int size) {
    if (fgets(buffer, size, stdin) == NULL) {
        return -1; // Failure
    }
    buffer[strcspn(buffer, "\n")] = '\0'; // Remove trailing newline
    return 0; // Success
}

int main(void) {
    char input_string[MAX_STRING_SIZE];

    printf("Enter a string: ");
    if (read_input_string(input_string, MAX_STRING_SIZE) == -1) {
        printf("Error reading input.\n");
        return 0;
    }

    int len = recursive_string_length(input_string);
    printf("The length of the string is: %d\n", len);

    return 0;
}
