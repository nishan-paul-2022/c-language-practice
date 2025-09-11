/*
 * Purpose: Reads characters from standard input one by one and prints them to standard output.
 *          The loop continues until the End-Of-File (EOF) character is received.
 * Topic: Basic I/O, Character Handling, Loops
 */

#include <stdio.h>

int main(void) {
    int character_input;

    printf("Enter characters. Press Ctrl+D (Unix/Linux) or Ctrl+Z (Windows) to signal End-Of-File.\n");

    while ((character_input = getchar()) != EOF) {
        putchar(character_input);
    }

    printf("\nEnd of file detected.\n");

    return 0;
}
