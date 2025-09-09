/*
 * Purpose: Demonstrates the basic usage of a character pointer to read and print a single character.
 * Topic: Pointers, Characters, Input/Output
 */

#include <stdio.h>

int main()
{
    char characterVariable; // Declare a character variable
    char *charPointer;      // Declare a pointer to a character

    // Assign the address of characterVariable to charPointer
    charPointer = &characterVariable;

    printf("Enter a single character: ");
    // Read a character using the pointer
    if (scanf("%c", charPointer) != 1)
    {
        printf("Invalid input. No character was read.\n");
        return 0;
    }

    // Print the character using pointer dereferencing
    printf("You entered: %c\n", *charPointer);

    return 0;
}
