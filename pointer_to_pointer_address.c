/*
 * Purpose: Demonstrates printing the address of a pointer to a pointer in C.
 * Topic: Pointers, Pointer to Pointer
 */

#include <stdio.h>

void print_pointer_address(int **ptr) {
    printf("Address of ptr_to_ptr: %p\n", (void *)ptr);
}

int main(void) {
    int value = 10;
    int *ptr_to_value = &value;
    int **ptr_to_ptr = &ptr_to_value;

    print_pointer_address(ptr_to_ptr);
    return 0;
}
