/*
 * Purpose: Demonstrates the concept of a pointer to a pointer.
 * Topic: Pointers, Pointer to Pointer
 */

#include <stdio.h>

void print_pointer_details(int *p_value, int **p_ptr) {
    printf("Address of ptr_to_value: %p\n", (void *)p_value);
    printf("Value pointed to by ptr_to_ptr: %d\n", **p_ptr);
    printf("Address of ptr_to_ptr: %p\n", (void *)p_ptr);
}

int main(void) {
    int value = 10;
    int *ptr_to_value = &value;
    int **ptr_to_ptr = &ptr_to_value;

    print_pointer_details(ptr_to_value, ptr_to_ptr);

    return 0;
}
