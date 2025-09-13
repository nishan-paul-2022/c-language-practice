/*
 * Purpose: Demonstrates the basic concept of dereferencing a pointer to access the value
 * of the variable it points to.
 * Topic: Pointers, Dereferencing, Variable Access
 */

#include <stdio.h>

void print_value(int *ptr) {
    printf("The value of my_integer (accessed via pointer) is: %d\n", *ptr);
}

int main(void) {
    int my_integer = 10;
    int *pointer_to_integer = &my_integer;
    print_value(pointer_to_integer);
    return 0;
}
