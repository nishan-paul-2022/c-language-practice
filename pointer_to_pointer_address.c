/*
 * Purpose: Demonstrates printing the address of a pointer to a pointer in C.
 * Topic: Pointers, Pointer to Pointer
 */

#include <stdio.h>

int main() {
    int value = 10;         // An integer variable
    int *ptr_to_value;      // A pointer to an integer
    int **ptr_to_ptr;       // A pointer to a pointer to an integer

    // Initialize the pointers
    ptr_to_value = &value;  // ptr_to_value now holds the address of 'value'
    ptr_to_ptr = &ptr_to_value; // ptr_to_ptr now holds the address of 'ptr_to_value'

    // Print the address of 'ptr_to_ptr' itself.
    // %p is used to print pointer addresses.
    printf("Address of ptr_to_ptr: %p\n", ptr_to_ptr);

    return 0;
}
