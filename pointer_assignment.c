/*
 * Purpose: Demonstrates how assigning one pointer to another changes the target of the first pointer,
 * and how this affects the values accessed through it.
 * Topic: Pointers, Pointer Assignment, Pointer Manipulation
 */

#include <stdio.h>

int main(void) {
    int first_variable = 10;  // Declare and initialize the first integer variable.
    int second_variable = 20; // Declare and initialize the second integer variable.
    int *pointer1;            // Declare a pointer to an integer.
    int *pointer2;            // Declare another pointer to an integer.

    // Assign the address of 'first_variable' to 'pointer1'.
    // 'pointer1' now points to 'first_variable'.
    pointer1 = &first_variable;

    // Assign the address of 'second_variable' to 'pointer2'.
    // 'pointer2' now points to 'second_variable'.
    pointer2 = &second_variable;

    // Print initial values to show the state before pointer assignment.
    printf("Before pointer assignment:\\n");
    printf("first_variable: %d (Address: %p)\\n", first_variable, (void *)&first_variable);
    printf("second_variable: %d (Address: %p)\\n", second_variable, (void *)&second_variable);
    printf("pointer1 points to address: %p\\n", (void *)pointer1);
    printf("pointer2 points to address: %p\\n", (void *)pointer2);
    printf("\\n");

    // Assign the value of 'pointer2' (which is the address of 'second_variable') to 'pointer1'.
    // Now, 'pointer1' also points to 'second_variable'. The original address of 'first_variable'
    // stored in 'pointer1' is lost.
    pointer1 = pointer2;

    // Print the values after the pointer assignment:
    // - first_variable: remains 10, as it was never modified directly or indirectly after initialization.
    // - *pointer1: accesses the value at the address pointer1 points to. Since pointer1 now points to second_variable, this will be 20.
    // - second_variable: remains 20, as it was never modified.
    // - *pointer2: accesses the value at the address pointer2 points to. Since pointer2 points to second_variable, this will be 20.
    printf("After pointer assignment (pointer1 = pointer2):\\n");
    printf("first_variable: %d\\n", first_variable);
    printf("*pointer1 (value at address pointer1 points to): %d\\n", *pointer1);
    printf("second_variable: %d\\n", second_variable);
    printf("*pointer2 (value at address pointer2 points to): %d\\n", *pointer2);

    return 0;
}
