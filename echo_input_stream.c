/*
 * Purpose: Reads characters from standard input until EOF and echoes them to standard output.
 * Topic: Character Input/Output, Reading Input Streams, EOF Handling
 */
#include <stdio.h>
#include <stdlib.h>

int main() {
    int input_char; // Use int to accommodate EOF

    printf("Enter text (press Ctrl+D on Unix/Linux or Ctrl+Z on Windows to signal EOF):\n");

    // Read characters from standard input until EOF is encountered
    while ((input_char = getchar()) != EOF) {
        // Echo the character back to standard output
        putchar((char)input_char);
    }

    // Check if the loop terminated due to an error rather than EOF
    if (ferror(stdin)) {
        perror("Error reading from standard input");
        return EXIT_FAILURE;
    }

    // Optional: add a newline if needed for cleaner output
    // putchar('\n');

    return 0;
}
