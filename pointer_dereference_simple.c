// Purpose: Demonstrates the basic concept of dereferencing a pointer to access the value
// of the variable it points to.
// Topic: Pointers, Dereferencing, Variable Access

#include <stdio.h>

int main(void) {
    int my_integer = 10;       // Declare an integer variable and initialize it.
    int *pointer_to_integer;   // Declare a pointer to an integer.

    // Assign the address of 'my_integer' to 'pointer_to_integer'.
    // 'pointer_to_integer' now points to 'my_integer'.
    pointer_to_integer = &my_integer;

    // Print the value of 'my_integer' by dereferencing 'pointer_to_integer'.
    // The '*' operator dereferences the pointer, giving the value stored at the address.
    printf("The value of my_integer (accessed via pointer) is: %d\\n", *pointer_to_integer);

    return 0;
}
