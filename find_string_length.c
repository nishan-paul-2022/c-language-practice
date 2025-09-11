/*
 * Purpose: Calculates and prints the length of a given string.
 * Topic: String Manipulation, String Length Calculation, Input Validation
 */

#include <stdio.h>
#include <string.h>

int main(void) {
    int buffer_size;
    char input_string[256]; // Use a reasonably sized buffer
    int string_length;

    // Prompt user to enter buffer size (though we'll use a fixed buffer for simplicity and safety)
    printf("Enter the maximum string length (e.g., 255 for a buffer of 256):\n");
    // Read buffer size and validate it
    if (scanf("%d", &buffer_size) != 1 || buffer_size <= 0 || buffer_size >= sizeof(input_string)) {
        fprintf(stderr, "Invalid buffer size entered. Using default buffer size of %lu.\n", sizeof(input_string) - 1);
        buffer_size = sizeof(input_string) - 1; // Use the maximum allowed size
    }
    // Consume the newline character after reading the integer
    while (getchar() != '\n');

    // Prompt user to enter a string
    printf("Enter a string (max %d characters):\n", buffer_size);
    // Read the input string safely using fgets
    if (fgets(input_string, sizeof(input_string), stdin) == NULL) {
        fprintf(stderr, "Error reading input string.\n");
        return 0;
    }

    // Remove trailing newline character if present
    input_string[strcspn(input_string, "\n")] = 0;

    // Calculate the string length using strlen
    string_length = strlen(input_string);

    // The original code had a check `if(i<n)` which was related to buffer overflow.
    // With fgets, we are safer, but we can still check if the input length
    // respects the user-provided buffer size for logical consistency.
    if (string_length > buffer_size) {
        printf("ERROR: Input string length exceeds the specified buffer size.\n");
    } else {
        // Display the string length
        printf("%d\n", string_length);
    }

    return 0;
}
