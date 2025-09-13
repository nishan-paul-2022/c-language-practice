/*
 * Purpose: Demonstrates how to print the memory address of a variable using a pointer.
 * Topic: Pointers, Memory Addresses
 */

#include <stdio.h>

void print_variable_address(int *ptr) {
    printf("The memory address of 'variable' is: %p\n", (void *)ptr);
}

int main(void) {
    int variable = 5;
    print_variable_address(&variable);
    return 0;
}
