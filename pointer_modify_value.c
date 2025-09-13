/*
 * Purpose: Demonstrates how to use a pointer to access and modify the value of a variable.
 * Topic: Pointers, Dereferencing, Variable Modification
 */

#include <stdio.h>

void print_values(float original, float modified) {
    printf("Original value: %f\n", original);
    printf("Modified value: %f\n", modified);
}

int main(void) {
    float original_value = 3.1416;
    float *pointer_to_value = &original_value;

    float before = original_value;
    *pointer_to_value = 5.67;
    float after = original_value;

    print_values(before, after);

    return 0;
}
