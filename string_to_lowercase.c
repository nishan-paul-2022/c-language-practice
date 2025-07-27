// Purpose: Converts all uppercase letters in a string to lowercase.
// Topic: String Manipulation, Character Conversion, Input Validation

#include <stdio.h>
#include <string.h> // For strlen and strcspn

int main() {
    int bufferSize;
    char inputString[256]; // Use a reasonably sized buffer
    int strLength;
    int charIndex;

    // Prompt user for buffer size (though we'll use a fixed buffer for simplicity and safety)
    // In a real-world scenario, you might dynamically allocate or use a fixed, sufficiently large buffer.
    // For this example, we'll use a fixed buffer and inform the user about its limit.
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

    strLength = strlen(inputString);

    // Check if the string length exceeds the intended buffer size (though fgets handles overflow)
    // This check is more for logical consistency with the original code's intent.
    if (strLength > bufferSize) {
        printf("ERROR: Input string exceeds the specified buffer size.\n");
    } else {
        // Convert uppercase characters to lowercase
        for (charIndex = 0; inputString[charIndex] != '\0'; charIndex++) {
            if (inputString[charIndex] >= 'A' && inputString[charIndex] <= 'Z') {
                inputString[charIndex] = inputString[charIndex] + 32; // ASCII difference between 'a' and 'A'
            }
        }
        printf("%s\n", inputString);
    }

    return 0; // Indicate successful execution
}
