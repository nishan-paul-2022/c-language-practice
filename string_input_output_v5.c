/*
 * Purpose: Reads a string from input and prints it.
 * Topic: Basic string I/O
 */

#include <stdio.h>
#include <string.h>

int main(void) {
    char input_str[10000];

    printf("Enter a string: ");
    if (fgets(input_str, sizeof(input_str), stdin) == NULL) {
        fprintf(stderr, "Error reading input.\n");
        return 1;
    }

    // Remove trailing newline if present
    input_str[strcspn(input_str, "\n")] = '\0';

    printf("You entered: %s\n", input_str);

    return 0;
}
