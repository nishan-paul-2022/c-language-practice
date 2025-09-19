/*
 * Purpose: Demonstrates returning a pointer to the larger of two integer values.
 * Topic: Pointers, Functions, Return Values, Comparison
 */

#include <stdio.h>

int* find_larger_pointer(int *ptr_val1, int *ptr_val2) {
    if (ptr_val1 == NULL || ptr_val2 == NULL) {
        fprintf(stderr, "NULL pointer passed.\n");
        return NULL;
    }
    if (*ptr_val1 >= *ptr_val2) {
        return ptr_val1;
    } else {
        return ptr_val2;
    }
}

void print_initial_values(int val1, int val2) {
    printf("Initial value1: %d\n", val1);
    printf("Initial value2: %d\n", val2);
}

void print_larger_value(int *larger_ptr) {
    if (larger_ptr != NULL) {
        printf("The larger value is: %d\n", *larger_ptr);
    } else {
        printf("Could not determine the larger value due to an error.\n");
    }
}

int main(void) {
    int value1 = 10;
    int value2 = 20;
    print_initial_values(value1, value2);
    int *larger_value_ptr = find_larger_pointer(&value1, &value2);
    print_larger_value(larger_value_ptr);
    return 0;
}
