/*
 * Purpose: Demonstrates assigning a pointer to a specific element of an array and dereferencing it.
 * Topic: Pointers, Arrays
 */

#include <stdio.h>

int main()
{
    int numbers[5] = {1, 2, 3, 4, 5}; // Initialize an integer array
    int *pointerToArrayElement;       // Declare a pointer to an integer

    // Assign the pointer to the address of the last element (index 4) of the array
    pointerToArrayElement = &numbers[4];

    // Print the value at the memory location pointed to by pointerToArrayElement
    printf("Value of the last array element (using pointer): %d\n", *pointerToArrayElement);

    return 0;
}
