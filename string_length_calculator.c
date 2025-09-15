/*
 * Purpose: Reads lines from standard input and prints their lengths.
 * Topic: Strings, Input/Output, Length Calculation
 */

#include <stdio.h>
#include <string.h>

int main(void) {
    char buffer[2000000]; // Large buffer for input lines
    int length;

    while (fgets(buffer, sizeof(buffer), stdin) != NULL) {
        // Remove trailing newline if present
        buffer[strcspn(buffer, "\n")] = '\0';
        length = strlen(buffer);
        printf("Length: %d\n", length);
    }

    return 0;
}
