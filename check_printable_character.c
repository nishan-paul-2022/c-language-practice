#include <stdio.h>
#include <ctype.h>

int main() {
    int input_value; // Variable to store the integer input

    // Loop indefinitely to continuously check input values
    while (1) {
        // Prompt the user for input (optional, but good for clarity)
        // printf("Enter an integer (ASCII value): "); 
        
        // Read an integer from standard input
        // Note: scanf might leave a newline in the buffer if the input is not just an integer.
        // For this specific loop, it might be okay as the next scanf will try to read again.
        if (scanf("%d", &input_value) != 1) {
            // If scanf fails (e.g., non-integer input), clear the input buffer and break or continue.
            // For simplicity, we'll just break if input is invalid.
            fprintf(stderr, "Invalid input. Exiting.\n");
            // Clear the rest of the line to prevent infinite loops on bad input
            while (getchar() != '\n' && !feof(stdin)); 
            break; 
        }

        // Check if the integer corresponds to a printable character using isprint()
        // isprint() returns a non-zero value if the character is printable, 0 otherwise.
        // Printable characters include letters, digits, punctuation, and space.
        if (isprint(input_value)) {
            printf("1\n"); // Output 1 if printable
        } else {
            printf("0\n"); // Output 0 if not printable
        }
    }

    return 0;
}
