/*
 * Purpose: Demonstrates assigning a pointer to a specific element of an array and dereferencing it.
 * Topic: Pointers, Arrays
 */

#include <stdio.h>

int main()
{
    int numbers[5] = {1, 2, 3, 4, 5}; // Initialize an integer array
    int *pointer_to_array_element;       // Declare a pointer to an integer

    // Assign the pointer to the address of the last element (index 4) of the array
    pointer_to_array_element = &numbers[4];

    // Print the value at the memory location pointed to by pointer_to_array_element
    printf("Value of the last array element (using pointer): %d\n", *pointer_to_array_element);

    return 0;
}
