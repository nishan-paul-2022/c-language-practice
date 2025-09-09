/*
 * Purpose: Calculates and prints the length of a given string by iterating through characters.
 * Topic: String Manipulation, Manual String Length Calculation, Input Handling
 */

#include <stdio.h>
#include <string.h>

int main() {
    char inputString[256]; // Use a reasonably sized buffer
    int stringLength = 0;
    int i;

    printf("Enter a string (max %lu characters):\n", sizeof(inputString) - 1);

    // Read the input string safely using fgets
    if (fgets(inputString, sizeof(inputString), stdin) == NULL) {
        fprintf(stderr, "Error reading input string.\n");
        return 0;
    }

    // Remove trailing newline character if present
    inputString[strcspn(inputString, "\n")] = 0;

    // Manually calculate the string length by iterating until the null terminator
    for (i = 0; inputString[i] != '\0'; i++) {
        stringLength++;
    }

    printf("%d\n", stringLength);

    return 0;
}
