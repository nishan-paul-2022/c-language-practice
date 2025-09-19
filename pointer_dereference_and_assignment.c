/*
 * Purpose: Illustrates pointer assignment, dereferencing to read, and dereferencing to write,
 *          showing how changes through a pointer affect the original variable and how a previously
 *          copied value remains unchanged.
 * Topic: Pointers, Dereferencing, Variable Assignment, Value Copying
 */

#include <stdio.h>

void print_initial(int val) {
    printf("Initial value of original_number: %d\n", val);
}

void print_after_modification(int original, int copied, int *ptr) {
    printf("After modification via pointer:\n");
    printf("original_number: %d\n", original);
    printf("copied_value: %d\n", copied);
    printf("*pointer_to_number: %d\n", *ptr);
}

int main(void) {
    int original_number = 10;
    int copied_value;
    int *pointer_to_number = &original_number;

    copied_value = *pointer_to_number;

    print_initial(original_number);

    *pointer_to_number = 20;

    print_after_modification(original_number, copied_value, pointer_to_number);

    return 0;
}
