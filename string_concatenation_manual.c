/*
 * Purpose: Demonstrates how to concatenate two strings into a third string manually using loops.
 * Topic: Strings, Arrays, Loops
 */

#include <stdio.h>  // Required for printf, fgets, puts
#include <string.h> // Required for strlen, strcspn (to remove newline from fgets)

int main() {
    char string1[100]; // First string
    char string2[100]; // Second string
    char concatenated_string[200]; // Buffer for the concatenated string (large enough for both)
    int i, j; // Loop counters
    int len1, len2; // Lengths of string1 and string2

    // Prompt user for input and read the first string safely
    printf("Enter the first string: ");
    if (fgets(string1, sizeof(string1), stdin) == NULL) {
        printf("Error reading input for string 1.\n");
        return 1;
    }
    string1[strcspn(string1, "\n")] = '\0'; // Remove trailing newline

    // Prompt user for input and read the second string safely
    printf("Enter the second string: ");
    if (fgets(string2, sizeof(string2), stdin) == NULL) {
        printf("Error reading input for string 2.\n");
        return 1;
    }
    string2[strcspn(string2, "\n")] = '\0'; // Remove trailing newline

    // Get lengths of the strings
    len1 = strlen(string1);
    len2 = strlen(string2);

    // Copy characters from string1 to concatenated_string
    for (i = 0; i < len1; i++) {
        concatenated_string[i] = string1[i];
    }

    // Copy characters from string2 to concatenated_string, starting after string1
    for (j = 0; j < len2; j++) {
        concatenated_string[len1 + j] = string2[j];
    }
    concatenated_string[len1 + len2] = '\0'; // Null-terminate the concatenated string

    // Print the concatenated string
    printf("Concatenated string: ");
    puts(concatenated_string);

    return 0;
}
