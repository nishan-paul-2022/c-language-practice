/*
 * Purpose: Demonstrates how to copy one string to another character by character using a loop.
 * Topic: Strings, Arrays, Loops
 */

#include <stdio.h>
#include <string.h>

int main(void) {
    char source_string[100];      // Source string to be copied
    char destination_string[100]; // Destination buffer for the copied string
    int i;

    // Prompt user for input and read the source string safely
    printf("Enter a string: ");
    if (fgets(source_string, sizeof(source_string), stdin) == NULL) {
        printf("Error reading input.\n");
        return 0;
    }

    // Remove the trailing newline character if fgets read it
    source_string[strcspn(source_string, "\n")] = '\0';

    // Copy characters from source_string to destination_string
    for (i = 0; source_string[i] != '\0'; i++) {
        destination_string[i] = source_string[i];
    }
    destination_string[i] = '\0'; // Null-terminate the destination string

    // Print the original and copied strings
    printf("Original string: ");
    puts(source_string);
    printf("Copied string: ");
    puts(destination_string);

    return 0;
}
