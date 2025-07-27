// Purpose: Reads and prints multiple lines of text entered by the user until end-of-file or error.
// Topic: String Input/Output, Reading Multiple Lines, Input Safety

#include <stdio.h>
#include <string.h> // For strcspn

int main() {
    int bufferSize;
    char inputString[256]; // Use a reasonably sized buffer

    // Prompt user for buffer size (though we'll use a fixed buffer for simplicity and safety)
    printf("Enter the maximum string length for each line (e.g., 255 for a buffer of 256):\n");
    if (scanf("%d", &bufferSize) != 1 || bufferSize <= 0 || bufferSize >= sizeof(inputString)) {
        fprintf(stderr, "Invalid buffer size entered. Using default buffer size of %lu.\n", sizeof(inputString) - 1);
        bufferSize = sizeof(inputString) - 1; // Use the maximum allowed size
    }
    // Consume the newline character after reading the integer
    while (getchar() != '\n');

    printf("Enter lines of text (press Ctrl+D or Ctrl+Z on a new line to end input):\n");

    // Read lines safely using fgets until end-of-file or error
    while (fgets(inputString, sizeof(inputString), stdin) != NULL) {
        // Remove trailing newline character if present
        inputString[strcspn(inputString, "\n")] = 0;

        // Print the read line
        printf("%s\n", inputString);
    }

    // Check if the loop terminated due to an error other than EOF
    if (ferror(stdin)) {
        fprintf(stderr, "An error occurred during input.\n");
        return 1; // Indicate an error
    }

    return 0; // Indicate successful execution
}
