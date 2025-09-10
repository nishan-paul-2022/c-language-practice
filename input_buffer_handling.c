/*
 * Purpose: Demonstrates reading input using fgets() and clearing the input buffer.
 * Topic: Input/Output, Buffer Handling
 */

#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 100

// Function to clear the standard input buffer
// Portable method reading characters until newline
void clear_input_buffer() {
    int c;
    // Read characters until newline or EOF
    // Consumes leftover characters in input buffer
    while ((c = getchar()) != '\n' && c != EOF);
}

int main(void) {
    char input_string[BUFFER_SIZE];
    int loop_count = 2; // Loop twice for demonstration

    printf("This program will ask for input twice.\n");

    // Loop to demonstrate reading input multiple times
    while (loop_count--) {
        printf("Enter a string: ");
        
        // Read input using fgets for safety
        // gets() is unsafe as it doesn't check buffer boundaries
        if (fgets(input_string, BUFFER_SIZE, stdin) == NULL) {
            fprintf(stderr, "Error reading input.\n");
            // If fgets fails, clear buffer and continue
            clear_input_buffer(); // Attempt to clear buffer on error
            continue; // Skip to next iteration
        }

        // fflush(stdin) has undefined behavior
        // Use portable buffer clearing function instead
        // fflush(stdin); // Non-standard, removed
        clear_input_buffer(); // Clear buffer using portable function

        // Print the input string that was read
        printf("You entered: %s", input_string); // fgets includes newline
    }

    printf("\nProgram finished.\n");
    return 0;
}
