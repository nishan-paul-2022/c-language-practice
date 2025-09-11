/*
 * Purpose: Calculates and prints the length of a given string using a separate function.
 * Topic: String Manipulation, Function Usage, String Length Calculation, Input Validation
 */

#include <stdio.h>
#include <string.h>

// Function to calculate the length of a string
int calculate_string_length(char str[]) {
    int i;
    // Iterate through the string until the null terminator is found
    for (i = 0; str[i] != '\0'; i++) {
        // The loop body is empty as we only need the count
    }
    return i; // Return the count, which is the length of the string
}

int main(void) {
    int string_length;
    char input_string[256]; // Use a reasonably sized buffer

    printf("Enter a string (max %lu characters):\n", sizeof(input_string) - 1);

    // Read the input string safely using fgets
    if (fgets(input_string, sizeof(input_string), stdin) == NULL) {
        fprintf(stderr, "Error reading input string.\n");
        return 0;
    }

    // Remove trailing newline character if present
    input_string[strcspn(input_string, "\n")] = 0;

    // Calculate the string length using the dedicated function
    string_length = calculate_string_length(input_string);

    printf("%d\n", string_length);

    return 0;
}
