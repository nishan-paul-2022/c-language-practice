/*
 * Purpose: Demonstrates using two pointers to manage and modify two separate integer variables.
 * Topic: Pointers, Multiple Pointers, Dereferencing, Variable Modification
 */

#include <stdio.h>

void print_values(int first, int second, int *p_first, int *p_second) {
    printf("Values after operations:\n");
    printf("first_number: %d\n", first);
    printf("*ptr_to_first: %d\n", *p_first);
    printf("second_number: %d\n", second);
    printf("*ptr_to_second: %d\n", *p_second);
}

int main(void) {
    int first_number = 10;
    int second_number;
    int *ptr_to_first = &first_number;
    int *ptr_to_second = &second_number;

    second_number = *ptr_to_first;
    *ptr_to_first = 20;
    *ptr_to_second = 30;

    print_values(first_number, second_number, ptr_to_first, ptr_to_second);

    return 0;
}
