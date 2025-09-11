/*
 * Purpose: Reads a string and prints its length using dynamic memory allocation and standard library functions.
 * Topic: String Input, Length Calculation, and Dynamic Memory
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    int max_len;

    // Prompt user for the maximum string length
    printf("Enter the maximum string length (n): ");
    if (scanf("%d", &max_len) != 1) {
        fprintf(stderr, "Error: Invalid input for maximum length.\n");
        return 0;
    }

    // Consume the newline character left by scanf to prepare for fgets
    int c;
    while ((c = getchar()) != '\n' && c != EOF);

    // Validate the maximum length
    if (max_len <= 0) {
        fprintf(stderr, "Error: Maximum length must be positive.\n");
        return 0;
    }

    // Dynamically allocate memory for the string buffer
    char *input_string = (char *)malloc((max_len + 1) * sizeof(char));
    if (input_string == NULL) {
        fprintf(stderr, "Error: Memory allocation failed.\n");
        return 0;
    }

    // Prompt user for the string
    printf("Enter a string (up to %d characters):\n", max_len);

    // Read the string using fgets for safety
    if (fgets(input_string, max_len + 1, stdin) == NULL) {
        fprintf(stderr, "Error: Failed to read string.\n");
        free(input_string); // Free allocated memory before exiting
        return 0;
    }

    // Remove the trailing newline character if it exists
    input_string[strcspn(input_string, "\n")] = '\0';

    // Get the actual length of the string using strlen
    size_t string_length = strlen(input_string);

    // Print the length of the string
    printf("String length: %zu\n", string_length); // Use %zu for size_t

    // Free the dynamically allocated memory
    free(input_string);

    return 0; // Exit after processing one string
}
