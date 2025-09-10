/*
 * Purpose: Demonstrates how to print the memory address of a character variable using a pointer.
 * Topic: Pointers, Memory Addresses, Character Types
 */

#include <stdio.h>

int main(void) {
    char sample_char = 'a'; // Character variable

    // Print memory address of character variable
    // %p format specifier prints pointer values
    // Cast address to (void *) for compatibility with %p
    printf("The memory address of 'sample_char' is: %p\n", (void *)&sample_char);

    return 0;
}
