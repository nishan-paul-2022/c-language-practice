/*
 * Purpose: Safely reads multiple lines of input and prints them.
 * Topic: Safe String Input and Line Printing
 */

#include <stdio.h>
#include <string.h> // For strlen, strcspn

int main() {
    // Define a buffer size for the string.
    // Using a fixed size buffer, but dynamic allocation would be more robust for very large inputs.
    const int BUFFER_SIZE = 1024;
    char input_string[BUFFER_SIZE];

    // Prompt user to enter strings (press Enter after each string, Ctrl+D or Ctrl+Z to end)
    printf("Enter strings (press Enter after each string, Ctrl+D or Ctrl+Z to end):\n");

    // Read strings using fgets for safety until EOF or error
    while (fgets(input_string, sizeof(input_string), stdin) != NULL) {
        // Remove the trailing newline character if it exists
        input_string[strcspn(input_string, "\n")] = '\0';

        // Print the string and a newline
        printf("%s\n", input_string);
    }

    // Check if the loop terminated due to an error
    if (ferror(stdin)) {
        fprintf(stderr, "Error: An input error occurred.\n");
        return 0;
    }

    return 0; // Exit successfully
}
