/*
 * Purpose: Demonstrates accessing and printing individual characters of a string.
 * Topic: Strings, Characters, Array Indexing, Input/Output
 */

#include <stdio.h>
#include <string.h>

int main(void) {
    char str[] = "UC Berkely";
    size_t length = strlen(str);

    printf("String: %s\n", str);
    printf("Length: %zu\n", length);

    printf("Character at index 0: %c\n", str[0]);
    if (length > 9) {
        printf("Character at index 9: %c\n", str[9]);
    }
    if (length > 0) {
        printf("Last character (index %zu): %c\n", length - 1, str[length - 1]);
    }
    printf("Null terminator at index %zu: %d\n", length, str[length]);

    return 0;
}
