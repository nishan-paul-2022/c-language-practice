// Purpose: Demonstrates the concept of a pointer to a pointer in C.
// Topic: Pointers, Pointer to Pointer

#include <stdio.h>

int main() {
    int value = 10;         // An integer variable
    int *ptr_to_value;      // A pointer to an integer
    int **ptr_to_ptr;       // A pointer to a pointer to an integer

    // Initialize the pointers
    ptr_to_value = &value;  // ptr_to_value now holds the address of 'value'
    ptr_to_ptr = &ptr_to_value; // ptr_to_ptr now holds the address of 'ptr_to_value'

    // Print the address of 'ptr_to_value' and the value pointed to by 'ptr_to_ptr'
    // %p is used to print pointer addresses.
    // The first printf argument is the address of 'ptr_to_value' (which is what ptr_to_ptr holds).
    // The second printf argument is the value of 'value' (obtained by dereferencing ptr_to_ptr twice).
    printf("Address of ptr_to_value: %p\n", ptr_to_value);
    printf("Value pointed to by ptr_to_ptr: %d\n", **ptr_to_ptr);

    // You can also print the address of the pointer to the pointer
    printf("Address of ptr_to_ptr: %p\n", ptr_to_ptr);

    return 0; // Indicate successful execution
}
