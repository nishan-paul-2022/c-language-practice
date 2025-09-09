// Purpose: Demonstrates printing a character's value, its address, and the pointer's address.
// Topic: Pointers, Memory Addresses, Dereferencing, Character Pointers

#include <stdio.h>

int main(void) {
    char character_variable = 'A';      // Declare and initialize a character variable
    char *char_pointer;                 // Declare a pointer to a character

    // Assign the memory address of 'character_variable' to 'char_pointer'
    char_pointer = &character_variable;

    // Print:
    // 1. The value pointed to by char_pointer (*char_pointer)
    // 2. The address stored in char_pointer (char_pointer)
    // 3. The memory address of the pointer variable itself (&char_pointer)
    printf("Character value: %c\n", *char_pointer);
    printf("Address of character: %p\n", (void *)char_pointer); // Cast to void* for %p
    printf("Address of the pointer: %p\n", (void *)&char_pointer); // Cast to void* for %p

    return 0;
}
