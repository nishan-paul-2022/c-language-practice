/*
 * Purpose: Demonstrates the basic usage of a character pointer to read and print a single character.
 * Topic: Pointers, Characters, Input/Output
 */

#include <stdio.h>

int main() {
    char char_variable; // Declare a character variable
    char *char_pointer;      // Declare a pointer to a character

    // Assign the address of char_variable to char_pointer
    char_pointer = &char_variable;

    printf("Enter a single character: ");
    // Read a character using the pointer
    if (scanf("%c", char_pointer) != 1) {
        printf("Invalid input. No character was read.\n");
        return 0;
    }

    // Print the character using pointer dereferencing
    printf("You entered: %c\n", *char_pointer);

    return 0;
}
