// Purpose: Demonstrates using two pointers to manage and modify two separate integer variables.
// Topic: Pointers, Multiple Pointers, Dereferencing, Variable Modification

#include <stdio.h>

int main(void) {
    int first_number;       // Declare the first integer variable.
    int second_number;      // Declare the second integer variable.
    int *ptr_to_first;      // Declare a pointer to an integer for the first variable.
    int *ptr_to_second;     // Declare a pointer to an integer for the second variable.

    // Initialize the first variable.
    first_number = 10;

    // Assign the memory address of 'first_number' to 'ptr_to_first'.
    ptr_to_first = &first_number;

    // Assign the memory address of 'second_number' to 'ptr_to_second'.
    ptr_to_second = &second_number;

    // Dereference 'ptr_to_first' to get the value of 'first_number' (10)
    // and assign it to 'second_number'.
    second_number = *ptr_to_first;

    // Dereference 'ptr_to_first' and assign a new value (20) to 'first_number'.
    *ptr_to_first = 20;

    // Dereference 'ptr_to_second' and assign a new value (30) to 'second_number'.
    *ptr_to_second = 30;

    // Print the values:
    // - first_number: will be 20 (changed via *ptr_to_first).
    // - *ptr_to_first: will be 20 (the current value at the address ptr_to_first points to).
    // - second_number: will be 30 (changed via *ptr_to_second).
    // - *ptr_to_second: will be 30 (the current value at the address ptr_to_second points to).
    printf("Values after operations:\\n");
    printf("first_number: %d\\n", first_number);
    printf("*ptr_to_first: %d\\n", *ptr_to_first);
    printf("second_number: %d\\n", second_number);
    printf("*ptr_to_second: %d\\n", *ptr_to_second);

    return 0;
}
