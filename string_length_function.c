/*
 * Purpose: Calculates and prints the length of a given string using a separate function.
 * Topic: String Manipulation, Function Usage, String Length Calculation, Input Validation
 */

#include <stdio.h>
#include <string.h> // For strcspn

// Function to calculate the length of a string
int calculateStringLength(char str[]) {
    int i;
    // Iterate through the string until the null terminator is found
    for (i = 0; str[i] != '\0'; i++) {
        // The loop body is empty as we only need the count
    }
    return i; // Return the count, which is the length of the string
}

int main() {
    int stringLength;
    char inputString[256]; // Use a reasonably sized buffer

    printf("Enter a string (max %lu characters):\n", sizeof(inputString) - 1);

    // Read the input string safely using fgets
    if (fgets(inputString, sizeof(inputString), stdin) == NULL) {
        fprintf(stderr, "Error reading input string.\n");
        return 0;
    }

    // Remove trailing newline character if present
    inputString[strcspn(inputString, "\n")] = 0;

    // Calculate the string length using the dedicated function
    stringLength = calculateStringLength(inputString);

    printf("%d\n", stringLength);

    return 0;
}
