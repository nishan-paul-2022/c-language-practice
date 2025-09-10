/*
 * Purpose: Demonstrates basic pointer declaration and dereferencing.
 * Topic: Pointers, Memory Addresses, Dereferencing
 */

#include <stdio.h>

int main(void) {
    int number = 5;
    int *pointer_to_number;

    pointer_to_number = &number;

    printf("The value of the variable pointed to by the pointer is: %d\n", *pointer_to_number);

    return 0;
}
