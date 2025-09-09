/*
 * Purpose: Demonstrates reading two strings, copying the first to the second, and printing the result.
 * Topic: String copying and input/output
 */

#include <stdio.h>
#include <string.h>

int main(void) {
    char source_string[10000]; // Buffer for the source string
    char destination_string[10000]; // Buffer for the destination string

    printf("Enter the first string: ");
    // Read the first string safely using fgets
    if (fgets(source_string, sizeof(source_string), stdin) == NULL) {
        fprintf(stderr, "Error reading the first string.\n");
        return 0;
    }
    // Remove the trailing newline character if present
    source_string[strcspn(source_string, "\n")] = 0;

    printf("Enter the second string: ");
    // Read the second string safely using fgets
    if (fgets(destination_string, sizeof(destination_string), stdin) == NULL) {
        fprintf(stderr, "Error reading the second string.\n");
        return 0;
    }
    // Remove the trailing newline character if present
    destination_string[strcspn(destination_string, "\n")] = 0;

    // Copy the content of source_string to destination_string
    // strcpy is safe here because both buffers have the same size and destination_string is large enough.
    strcpy(destination_string, source_string);

    printf("The copied string is: ");
    // Print the destination string
    puts(destination_string);

    return 0;
}
