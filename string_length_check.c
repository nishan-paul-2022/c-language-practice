// Purpose: Reads a string and prints its length if the string's length is less than a specified maximum length.
// Topic: String Input and Length Calculation

#include <stdio.h>
#include <string.h> // For strlen, strcspn

int main() {
    int max_len;

    // Prompt user for the maximum string length
    printf("Enter the maximum string length (n): ");
    if (scanf("%d", &max_len) != 1) {
        fprintf(stderr, "Error: Invalid input for maximum length.\n");
        return 1;
    }

    // Consume the newline character left by scanf to prepare for fgets
    int c;
    while ((c = getchar()) != '\n' && c != EOF);

    // Validate the maximum length
    if (max_len <= 0) {
        fprintf(stderr, "Error: Maximum length must be positive.\n");
        return 1;
    }

    char input_string[max_len + 1]; // +1 for null terminator

    // Prompt user for the string
    printf("Enter a string (up to %d characters):\n", max_len);

    // Read the string using fgets for safety
    if (fgets(input_string, sizeof(input_string), stdin) == NULL) {
        fprintf(stderr, "Error: Failed to read string.\n");
        return 1;
    }

    // Remove the trailing newline character if it exists
    input_string[strcspn(input_string, "\n")] = '\0';

    // Get the actual length of the string
    size_t current_len = strlen(input_string);

    // Check if the string length is within the allowed limit (less than max_len)
    // The original code checked if i < n, where i was the length.
    // This means if the string was exactly n characters long, it would print ERROR.
    if (current_len < max_len) {
        printf("String length: %zu\n", current_len); // Use %zu for size_t
    } else {
        printf("ERROR: String is too long or invalid.\n");
    }

    return 0; // Exit after processing one string
}
