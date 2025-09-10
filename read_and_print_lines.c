/*
 * Purpose: Reads and prints multiple lines of text entered by the user until end-of-file or error.
 * Topic: String Input/Output, Reading Multiple Lines, Input Safety
 */

#include <stdio.h>
#include <string.h>

int main() {
    int buffer_size;
    char input_string[256]; // Use a reasonably sized buffer

    // Prompt user for buffer size (though we'll use a fixed buffer for simplicity and safety)
    printf("Enter the maximum string length for each line (e.g., 255 for a buffer of 256):\n");
    if (scanf("%d", &buffer_size) != 1 || buffer_size <= 0 || buffer_size >= sizeof(input_string)) {
        fprintf(stderr, "Invalid buffer size entered. Using default buffer size of %lu.\n", sizeof(input_string) - 1);
        buffer_size = sizeof(input_string) - 1; // Use the maximum allowed size
    }
    // Consume the newline character after reading the integer
    while (getchar() != '\n');

    printf("Enter lines of text (press Ctrl+D or Ctrl+Z on a new line to end input):\n");

    // Read lines safely using fgets until end-of-file or error
    while (fgets(input_string, sizeof(input_string), stdin) != NULL) {
        // Remove trailing newline character if present
        input_string[strcspn(input_string, "\n")] = 0;

        // Print the read line
        printf("%s\n", input_string);
    }

    // Check if the loop terminated due to an error other than EOF
    if (ferror(stdin)) {
        fprintf(stderr, "An error occurred during input.\n");
        return 0;
    }

    return 0;
}
