// Purpose: Calculates and prints the length of a given string.
// Topic: String Manipulation, String Length Calculation, Input Validation

#include <stdio.h>
#include <string.h> // For strlen and strcspn

int main() {
    int bufferSize;
    char inputString[256]; // Use a reasonably sized buffer
    int stringLength;

    // Prompt user for buffer size (though we'll use a fixed buffer for simplicity and safety)
    printf("Enter the maximum string length (e.g., 255 for a buffer of 256):\n");
    if (scanf("%d", &bufferSize) != 1 || bufferSize <= 0 || bufferSize >= sizeof(inputString)) {
        fprintf(stderr, "Invalid buffer size entered. Using default buffer size of %lu.\n", sizeof(inputString) - 1);
        bufferSize = sizeof(inputString) - 1; // Use the maximum allowed size
    }
    // Consume the newline character after reading the integer
    while (getchar() != '\n');

    printf("Enter a string (max %d characters):\n", bufferSize);
    // Read the input string safely using fgets
    if (fgets(inputString, sizeof(inputString), stdin) == NULL) {
        fprintf(stderr, "Error reading input string.\n");
        return 1; // Indicate an error
    }

    // Remove trailing newline character if present
    inputString[strcspn(inputString, "\n")] = 0;

    // Calculate the string length using strlen
    stringLength = strlen(inputString);

    // The original code had a check `if(i<n)` which was related to buffer overflow.
    // With fgets, we are safer, but we can still check if the input length
    // respects the user-provided buffer size for logical consistency.
    if (stringLength > bufferSize) {
        printf("ERROR: Input string length exceeds the specified buffer size.\n");
    } else {
        printf("%d\n", stringLength);
    }

    return 0; // Indicate successful execution
}
