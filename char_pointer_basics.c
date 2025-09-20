/*
 * Purpose: Demonstrates the basic usage of a character pointer to read and print a single character.
 * Topic: Pointers, Characters, Input/Output
 */

#include <stdio.h>

void consume_newline() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int read_char_via_variable(char *char_variable) {
    printf("Enter a single character: ");
    if (scanf("%c", char_variable) != 1) {
        printf("Invalid input. No character was read.\n");
        return -1;
    }
    return 0;
}

int read_char_via_pointer(char *char_pointer) {
    printf("Enter a single character: ");
    if (scanf("%c", char_pointer) != 1) {
        printf("Invalid input. No character was read.\n");
        return -1;
    }
    return 0;
}

void display_char_info(char char_value, void *address, const char *label) {
    printf("%s - Value: %c | Address: %p\n", label, char_value, address);
}

void compare_char_values(char char_variable, char char_from_pointer) {
    printf("char_variable: %c | char_pointer: %c\n", char_variable, char_from_pointer);
}

int main(void) {
    char char_variable;
    char *char_pointer = &char_variable;

    if (read_char_via_variable(&char_variable) == -1) {
        return 0;
    }
    display_char_info(char_variable, &char_variable, "Via variable");

    consume_newline();

    if (read_char_via_pointer(char_pointer) == -1) {
        return 0;
    }
    display_char_info(*char_pointer, char_pointer, "Via pointer");

    compare_char_values(char_variable, *char_pointer);

    return 0;
}
