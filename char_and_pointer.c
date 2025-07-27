// Purpose: Demonstrates how a character pointer can be used to access both the value
// and the memory address of a character variable.
// Topic: Pointers, Character Variables, Dereferencing, Memory Addresses

#include <stdio.h>

int main(void) {
    char my_char = 'a';         // Declare a character variable and initialize it.
    char *pointer_to_char;      // Declare a character pointer.

    // Assign the memory address of 'my_char' to 'pointer_to_char'.
    pointer_to_char = &my_char;

    // Print the character variable directly.
    printf("The character value directly: %c\\n", my_char);

    // Print the memory address of the character variable.
    printf("The memory address of the character variable: %p\\n", (void *)&my_char);

    // Print the character value using the pointer (dereferencing).
    // Print the memory address stored in the pointer.
    printf("The character value via pointer: %c, The address via pointer: %p\\n", *pointer_to_char, (void *)pointer_to_char);

    return 0; // Indicate successful execution.
}
