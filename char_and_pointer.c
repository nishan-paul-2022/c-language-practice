/*
 * Purpose: Demonstrates how a character pointer can be used to access both the value
 *          of a character variable and the memory address of a character variable.
 * Topic: Pointers, Character Variables, Dereferencing, Memory Addresses
 */

#include <stdio.h>

int main(void) {
    char my_char = 'a';         // Character variable
    char *pointer_to_char;      // Character pointer

    // Assign memory address of 'my_char' to 'pointer_to_char'
    pointer_to_char = &my_char;

    // Print character value directly
    printf("The character value directly: %c\n", my_char);

    // Print memory address of character variable
    printf("The memory address of the character variable: %p\n", (void *)&my_char);

    // Print character value via pointer (dereferencing)
    // Print memory address stored in pointer
    printf("The character value via pointer: %c, The address via pointer: %p\n", *pointer_to_char, (void *)pointer_to_char);

    return 0;
}
