/*
 * Purpose: Demonstrates the concept of a pointer to a pointer (double pointer) and how to access the original variable's value through it.
 * Topic: Pointers to Pointers, Double Pointers, Dereferencing
 */

#include <stdio.h>

void print_double_pointer_info(int *ptr, int **dptr) {
    printf("Address of 'number' (via pointer_to_number): %p\n", (void *)ptr);
    printf("Value of 'number' (via pointer_to_pointer): %d\n", **dptr);
}

int main(void) {
    int number = 10;
    int *pointer_to_number = &number;
    int **pointer_to_pointer = &pointer_to_number;

    print_double_pointer_info(pointer_to_number, pointer_to_pointer);

    return 0;
}
