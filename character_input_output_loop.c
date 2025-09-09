/*
 * Purpose: Reads characters from standard input one by one and prints them to standard output.
 *          The loop continues until the End-Of-File (EOF) character is received.
 * Topic: Basic I/O, Character Handling, Loops
 */

#include <stdio.h>

int main() {
    int character_input; // Use int to store character to properly handle EOF

    printf("Enter characters. Press Ctrl+D (Unix/Linux) or Ctrl+Z (Windows) to signal End-Of-File.\n");

    // Loop to read characters until EOF is encountered
    // getchar() returns an int to accommodate EOF, which is typically a negative integer.
    while ((character_input = getchar()) != EOF) {
        putchar(character_input); // Print the character to standard output
    }

    printf("\nEnd of input detected.\n");

    return 0;
}
