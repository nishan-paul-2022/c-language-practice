// Purpose: Demonstrates how to use a pointer to access and modify the value of a variable.
// Topic: Pointers, Dereferencing, Variable Modification

#include <stdio.h>

int main(void) {
    float original_value = 3.1416; // Declare a float variable and initialize it.
    float *pointer_to_value;      // Declare a pointer to a float.

    // Assign the memory address of 'original_value' to 'pointer_to_value'.
    pointer_to_value = &original_value;

    // Print the original value of the variable.
    printf("Original value: %f\\n", original_value);

    // Use the pointer to modify the value of the variable.
    // Dereferencing the pointer (*pointer_to_value) allows us to access and change
    // the data at the memory address it holds.
    *pointer_to_value = 5.67;

    // Print the modified value of the variable.
    printf("Modified value: %f\\n", original_value);

    return 0; // Indicate successful execution.
}
