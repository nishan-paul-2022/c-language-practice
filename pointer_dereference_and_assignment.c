// Purpose: Illustrates pointer assignment, dereferencing to read, and dereferencing to write,
// showing how changes through a pointer affect the original variable and how a previously
// copied value remains unchanged.
// Topic: Pointers, Dereferencing, Variable Assignment, Value Copying

#include <stdio.h>

int main(void) {
    int original_number = 10; // Declare an integer variable and initialize it.
    int copied_value;         // Declare a variable to hold a copy of the value.
    int *pointer_to_number;   // Declare a pointer to an integer.

    // Assign the memory address of 'original_number' to 'pointer_to_number'.
    // Now, 'pointer_to_number' points to 'original_number'.
    pointer_to_number = &original_number;

    // Dereference the pointer to get the value of 'original_number' and assign it to 'copied_value'.
    // 'copied_value' now holds the value 10.
    copied_value = *pointer_to_number;

    // Print the current value of 'original_number'.
    printf("Initial value of original_number: %d\\n", original_number);

    // Dereference the pointer and assign a new value (20) to the memory location it points to.
    // This directly changes the value of 'original_number' to 20.
    *pointer_to_number = 20;

    // Print the values:
    // - original_number: will be 20 (changed via the pointer).
    // - copied_value: will still be 10 (it's a separate variable that held the value before the change).
    // - *pointer_to_number: will be 20 (the current value at the address pointer_to_number points to).
    printf("After modification via pointer:\\n");
    printf("original_number: %d\\n", original_number);
    printf("copied_value: %d\\n", copied_value);
    printf("*pointer_to_number: %d\\n", *pointer_to_number);

    return 0;
}
