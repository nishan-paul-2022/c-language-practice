/*
 * Purpose: Demonstrates reading input using gets() and attempting to clear
 *          the input buffer using fflush(stdin). It also shows the common
 *          practice of printing the input.
 * Topic: Input/Output, Buffer Handling
 */

#include <stdio.h>
#include <stdlib.h> // For EXIT_FAILURE

#define BUFFER_SIZE 100

// Function to clear the standard input buffer.
// This is a common, though non-standard, way to clear stdin.
// A more portable method would involve reading characters until newline.
void clear_input_buffer() {
    int c;
    // Read characters until a newline or EOF is encountered.
    // This loop consumes any leftover characters in the input buffer.
    while ((c = getchar()) != '\n' && c != EOF);
}

int main(void) {
    char input_string[BUFFER_SIZE];
    int loop_count = 2; // The original code loops twice

    printf("This program will ask for input twice.\n");

    // Loop to demonstrate reading input multiple times
    while (loop_count--) {
        printf("Enter a string: ");
        
        // Read input using fgets for safety.
        // gets() is unsafe as it doesn't check buffer boundaries.
        if (fgets(input_string, BUFFER_SIZE, stdin) == NULL) {
            fprintf(stderr, "Error reading input.\n");
            // If fgets fails, we might want to clear the buffer anyway if possible
            // or exit. For this example, we'll try to clear and continue.
            clear_input_buffer(); // Attempt to clear buffer on error
            continue; // Skip to next iteration
        }

        // The original code used fflush(stdin), which has undefined behavior.
        // We replace it with a portable buffer clearing function.
        // fflush(stdin); // This line is non-standard and removed.
        clear_input_buffer(); // Use the portable function to clear the buffer.

        // Print the input string that was read.
        printf("You entered: %s", input_string); // fgets includes the newline, so puts is not needed here.
    }

    printf("\nProgram finished.\n");
    return 0;
}
