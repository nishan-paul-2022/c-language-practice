/*
 * Purpose: Demonstrates assigning a pointer to a specific element of an array and dereferencing it.
 * Topic: Pointers, Arrays
 */

#include <stdio.h>

void print_last_element(int *ptr) {
    printf("Value of the last array element (using pointer): %d\n", *ptr);
}

int main(void) {
    int numbers[5] = {1, 2, 3, 4, 5};
    int *pointer_to_array_element = &numbers[4];
    print_last_element(pointer_to_array_element);
    return 0;
}
