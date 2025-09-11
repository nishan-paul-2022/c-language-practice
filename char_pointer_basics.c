/*
 * Purpose: Demonstrates the basic usage of a character pointer to read and print a single character.
 * Topic: Pointers, Characters, Input/Output
 */

#include <stdio.h>

void consume_newline() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main(void) {
    char char_variable;
    char *char_pointer = &char_variable;

    // Character using variable
    printf("Enter a single character: ");
    if (scanf("%c", &char_variable) != 1) {
        printf("Invalid input. No character was read.\n");
        return 0;
    }
    printf("Value: %c | Address: %p\n", char_variable, &char_variable);

    consume_newline();

    // Character using pointer
    printf("Enter a single character: ");
    if (scanf("%c", char_pointer) != 1) {
        printf("Invalid input. No character was read.\n");
        return 0;
    }
    printf("Value: %c | Address: %p\n", *char_pointer, char_pointer);

    printf("char_variable: %c | char_pointer: %c\n", char_variable, *char_pointer);

    return 0;
}
