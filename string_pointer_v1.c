/*
 * Purpose: Demonstrates basic pointer usage with strings, including array-pointer equivalence.
 * Topic: Pointers, String Manipulation
 */

#include <stdio.h>

void demonstrate_string_pointer(void) {
    char str[] = "BANGLADESH";
    char *ptr = str; // Pointer to first element

    printf("Original string: %s\n", str);
    printf("String via pointer: %s\n", ptr);

    printf("Characters via pointer:\n");
    for (int i = 0; str[i] != '\0'; i++) {
        printf("  str[%d]: %c, ptr[%d]: %c\n", i, str[i], i, ptr[i]);
    }
}

int main(void) {
    demonstrate_string_pointer();
    return 0;
}
