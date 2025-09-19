/*
 * Purpose: Demonstrates how a character pointer can be used to access both the value
 *          of a character variable and the memory address of a character variable.
 * Topic: Pointers, Character Variables, Dereferencing, Memory Addresses
 */

#include <stdio.h>

int main(void) {
    char c = 'a';
    char *pointer_to_c = &c;

    printf("Via varaible : Value - %c | Address - %p\n", c, (void *)&c);
    printf("Via pointer : Value - %c | Address - %p\n", *pointer_to_c, (void *)pointer_to_c);

    return 0;
}
