// Purpose: Demonstrates how to print the memory address of a variable using a pointer.
// Topic: Pointers, Memory Addresses

#include <stdio.h>

int main(void) {
    int variable = 5; // Declare an integer variable and initialize it.

    // Print the memory address of the variable.
    // The %p format specifier is used to print pointer values.
    printf("The memory address of 'variable' is: %p\\n", (void *)&variable);

    return 0;
}
