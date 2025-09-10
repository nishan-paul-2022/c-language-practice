/*
 * Purpose: Converts all uppercase letters in a string to lowercase.
 * Topic: String Manipulation, Character Conversion, Input Validation
 */

#include <stdio.h>
#include <string.h>

int main() {
    int buffer_size;
    char input_string[256]; // Use a reasonably sized buffer
    int str_length;
    int char_index;

    // Prompt user for buffer size (though we'll use a fixed buffer for simplicity and safety)
    // In a real-world scenario, you might dynamically allocate or use a fixed, sufficiently large buffer.
    // For this example, we'll use a fixed buffer and inform the user about its limit.
    printf("Enter the maximum string length (e.g., 255 for a buffer of 256):\n");
    if (scanf("%d", &buffer_size) != 1 || buffer_size <= 0 || buffer_size >= sizeof(input_string)) {
        fprintf(stderr, "Invalid buffer size entered. Using default buffer size of %lu.\n", sizeof(input_string) - 1);
        buffer_size = sizeof(input_string) - 1; // Use the maximum allowed size
    }
    // Consume the newline character after reading the integer
    while (getchar() != '\n');

    printf("Enter a string (max %d characters):\n", buffer_size);
    // Read the input string safely using fgets
    if (fgets(input_string, sizeof(input_string), stdin) == NULL) {
        fprintf(stderr, "Error reading input string.\n");
        return 0;
    }

    // Remove trailing newline character if present
    input_string[strcspn(input_string, "\n")] = 0;

    str_length = strlen(input_string);

    // Check if the string length exceeds the intended buffer size (though fgets handles overflow)
    // This check is more for logical consistency with the original code's intent.
    if (str_length > buffer_size) {
        printf("ERROR: Input string exceeds the specified buffer size.\n");
    } else {
        // Convert uppercase characters to lowercase
        for (char_index = 0; input_string[char_index] != '\0'; char_index++) {
            if (input_string[char_index] >= 'A' && input_string[char_index] <= 'Z') {
                input_string[char_index] = input_string[char_index] + 32; // ASCII difference between 'a' and 'A'
            }
        }
        printf("%s\n", input_string);
    }

    return 0;
}
