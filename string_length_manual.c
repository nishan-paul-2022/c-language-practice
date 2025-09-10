/*
 * Purpose: Calculates and prints the length of a given string by iterating through characters.
 * Topic: String Manipulation, Manual String Length Calculation, Input Handling
 */

#include <stdio.h>
#include <string.h>

int main() {
    char input_string[256]; // Use a reasonably sized buffer
    int string_length = 0;
    int i;

    printf("Enter a string (max %lu characters):\n", sizeof(input_string) - 1);

    // Read the input string safely using fgets
    if (fgets(input_string, sizeof(input_string), stdin) == NULL) {
        fprintf(stderr, "Error reading input string.\n");
        return 0;
    }

    // Remove trailing newline character if present
    input_string[strcspn(input_string, "\n")] = 0;

    // Manually calculate the string length by iterating until the null terminator
    for (i = 0; input_string[i] != '\0'; i++) {
        string_length++;
    }

    printf("%d\n", string_length);

    return 0;
}
