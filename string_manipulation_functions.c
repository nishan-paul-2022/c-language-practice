/*
 * Purpose: Demonstrates string comparison, length calculation, concatenation, and copying.
 * Topic: Strings, String Functions (strcmp, strlen, strcat, strcpy), Input/Output
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_STRING_LEN 100 // Define a maximum length for strings to prevent buffer overflows

int main(void) {
    char string_a[MAX_STRING_LEN];
    char string_b[MAX_STRING_LEN];
    char temp_buffer[MAX_STRING_LEN]; // Temporary buffer for concatenation
    int comparison_result;
    size_t length_a, length_b; // Use size_t for lengths

    // Prompt for and read the first string
    printf("Enter the first string (max %d characters): ", MAX_STRING_LEN - 1);
    if (fgets(string_a, MAX_STRING_LEN, stdin) == NULL) {
        fprintf(stderr, "Error: Failed to read the first string.\n");
        return EXIT_FAILURE;
    }
    // Remove trailing newline character if present
    string_a[strcspn(string_a, "\n")] = 0;

    // Prompt for and read the second string
    printf("Enter the second string (max %d characters): ", MAX_STRING_LEN - 1);
    if (fgets(string_b, MAX_STRING_LEN, stdin) == NULL) {
        fprintf(stderr, "Error: Failed to read the second string.\n");
        return EXIT_FAILURE;
    }
    // Remove trailing newline character if present
    string_b[strcspn(string_b, "\n")] = 0;

    // Compare the two strings
    comparison_result = strcmp(string_a, string_b);

    // Print the comparison result
    printf("\nString Comparison:\n");
    if (comparison_result == 0) {
        printf("Strings are the same.\n");
    } else {
        printf("Strings are not the same.\n");
    }

    // Calculate and print the lengths of the strings
    length_a = strlen(string_a);
    length_b = strlen(string_b);
    printf("Length of first string: %zu\n", length_a);
    printf("Length of second string: %zu\n", length_b);

    // Concatenate string_a, a space, and string_b into string_a
    // Ensure string_a has enough space: MAX_STRING_LEN is sufficient here.
    // First, copy string_a to a temporary buffer to preserve it for the next step.
    strcpy(temp_buffer, string_a);
    
    // Append a space to temp_buffer
    strcat(temp_buffer, " ");
    
    // Append string_b to temp_buffer
    strcat(temp_buffer, string_b);
    
    printf("\nConcatenated string (string_a + \" \" + string_b): %s\n", temp_buffer);

    // Copy string_b to string_a
    // This overwrites the original content of string_a.
    strcpy(string_a, string_b);
    printf("After strcpy(string_a, string_b), string_a is now: %s\n", string_a);

    return 0;
}
