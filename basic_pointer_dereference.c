/*
 * Purpose: Demonstrates basic pointer declaration and dereferencing.
 * Topic: Pointers, Memory Addresses, Dereferencing
 */

#include <stdio.h>

int main(void) {
    int number = 5; // Declare an integer variable
    int *pointer_to_number; // Declare a pointer to an integer

    // Assign the memory address of 'number' to 'pointer_to_number'
    pointer_to_number = &number;

    // Dereference the pointer to access and print the value it points to
    printf("The value of the variable pointed to by the pointer is: %d\n", *pointer_to_number);

    return 0;
}
