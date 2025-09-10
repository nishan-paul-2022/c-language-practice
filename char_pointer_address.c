/*
 * Purpose: Demonstrates how to print the memory address of a character variable using a pointer.
 * Topic: Pointers, Memory Addresses, Character Types
 */

#include <stdio.h>

int main(void) {
    char sample_char = 'a'; // Declare a character variable and initialize it.

    // Print the memory address of the character variable.
    // The %p format specifier is used to print pointer values.
    // We cast the address to (void *) for compatibility with %p.
    printf("The memory address of 'sample_char' is: %p\n", (void *)&sample_char);

    return 0;
}
