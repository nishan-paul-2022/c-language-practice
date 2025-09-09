// Purpose: Reads strings from input and prints them until a string starting with 'x' is encountered.
// Topic: String input, loops, conditional execution, input buffer handling.

#include <stdio.h>
#include <string.h> // For strcspn
#include <stdlib.h> // For exit()

#define BUFFER_SIZE 256 // Define a reasonable buffer size for input strings

int main(void) {
    char input_string[BUFFER_SIZE];
    int max_string_length;

    printf("Enter the maximum length for strings (e.g., 50): ");
    // Read the maximum length for strings and validate input
    if (scanf("%d", &max_string_length) != 1 || max_string_length <= 0 || max_string_length >= BUFFER_SIZE) {
        printf("Invalid length entered. Please enter a positive integer less than %d.\\n", BUFFER_SIZE);
        return 0;
    }

    // Consume the newline character left by scanf
    while (getchar() != '\\n');

    printf("Enter strings. Type a string starting with 'x' to exit.\\n");

    // Loop to read strings until an exit condition is met
    while (1) {
        printf("Enter a string: ");
        // Use fgets for safe input, reading up to max_string_length - 1 characters
        if (fgets(input_string, max_string_length, stdin) == NULL) {
            printf("Error reading input string or end of input reached.\\n");
            break; // Exit loop on error or EOF
        }

        // Remove the trailing newline character if it exists
        input_string[strcspn(input_string, "\\n")] = 0;

        // Check if the string starts with 'x' to exit the loop
        if (input_string[0] == 'x') {
            printf("Exiting program as input starts with 'x'.\\n");
            break; // Exit the loop
        } else {
            // Print the string if it does not start with 'x'
            printf("You entered: %s\\n", input_string);
        }
    }

    return 0;
}
