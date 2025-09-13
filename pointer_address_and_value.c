/*
 * Purpose: Demonstrates printing a character's value, its address, and the pointer's address.
 * Topic: Pointers, Memory Addresses, Dereferencing, Character Pointers
 */

#include <stdio.h>

void print_character_info(char *ptr) {
    printf("Character value: %c\n", *ptr);
    printf("Address of character: %p\n", (void *)ptr);
    printf("Address of the pointer: %p\n", (void *)&ptr);
}

int main(void) {
    char ch = 'A';
    char *ptr = &ch;
    print_character_info(ptr);
    return 0;
}
