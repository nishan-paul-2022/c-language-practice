/*
 * Purpose: Demonstrates reading an entire line of text from standard input using fgets.
 * Topic: Strings, Input/Output Functions, Buffer Handling
 */

#include <stdio.h>
#include <string.h>

int main(void) {
    char input_line[100000];

    printf("Enter a line of text: ");
    if (fgets(input_line, sizeof(input_line), stdin) != NULL) {
        size_t len = strlen(input_line);
        if (len > 0 && input_line[len - 1] == '\n') {
            input_line[len - 1] = '\0'; // Remove newline
        }
        printf("Entered string: %s\n", input_line);
    } else {
        printf("Error reading input.\n");
    }

    return 0;
}
