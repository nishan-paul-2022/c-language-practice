/*
 * Purpose: Demonstrates how to print the memory address of a character variable using a pointer.
 * Topic: Pointers, Memory Addresses, Character Types
 */

#include <stdio.h>

int main(void) {
    char c = 'a';
    printf("memory address of 'c' is: %p\n", (void *)&c);
    return 0;
}
