// Purpose: Demonstrates the concept of a pointer to a pointer (double pointer)
// and how to access the original variable's value through it.
// Topic: Pointers to Pointers, Double Pointers, Dereferencing

#include <stdio.h>

int main(void) {
    int number = 10;          // Declare an integer variable.
    int *pointer_to_number;   // Declare a pointer to an integer.
    int **pointer_to_pointer; // Declare a pointer to a pointer to an integer.

    // Assign the address of 'number' to 'pointer_to_number'.
    // 'pointer_to_number' now points to 'number'.
    pointer_to_number = &number;

    // Assign the address of 'pointer_to_number' to 'pointer_to_pointer'.
    // 'pointer_to_pointer' now points to 'pointer_to_number'.
    pointer_to_pointer = &pointer_to_number;

    // Print the address stored in 'pointer_to_number' (which is the address of 'number').
    // Use %p for printing addresses.
    printf("Address of 'number' (via pointer_to_number): %p\\n", (void *)pointer_to_number);

    // Print the value of 'number' by dereferencing 'pointer_to_pointer' twice.
    // *pointer_to_pointer gives the value of pointer_to_number (address of number).
    // **pointer_to_pointer dereferences that address, giving the value of number.
    printf("Value of 'number' (via pointer_to_pointer): %d\\n", **pointer_to_pointer);

    // You can also print the address of 'pointer_to_number' itself:
    // printf("Address of 'pointer_to_number' (stored in pointer_to_pointer): %p\\n", (void *)pointer_to_pointer);

    return 0; // Indicate successful execution.
}
