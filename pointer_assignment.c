/*
 * Purpose: Demonstrates how assigning one pointer to another changes the target of the first pointer,
 * and how this affects the values accessed through it.
 * Topic: Pointers, Pointer Assignment, Pointer Manipulation
 */

#include <stdio.h>

void print_before_assignment(int fv, int sv, int *p1, int *p2) {
    printf("Before pointer assignment:\n");
    printf("first_variable: %d (Address: %p)\n", fv, (void *)&fv);
    printf("second_variable: %d (Address: %p)\n", sv, (void *)&sv);
    printf("pointer1 points to address: %p\n", (void *)p1);
    printf("pointer2 points to address: %p\n", (void *)p2);
    printf("\n");
}

void print_after_assignment(int fv, int sv, int *p1, int *p2) {
    printf("After pointer assignment (pointer1 = pointer2):\n");
    printf("first_variable: %d\n", fv);
    printf("*pointer1: %d\n", *p1);
    printf("second_variable: %d\n", sv);
    printf("*pointer2: %d\n", *p2);
}

int main(void) {
    int first_variable = 10;
    int second_variable = 20;
    int *pointer1 = &first_variable;
    int *pointer2 = &second_variable;

    print_before_assignment(first_variable, second_variable, pointer1, pointer2);

    pointer1 = pointer2;

    print_after_assignment(first_variable, second_variable, pointer1, pointer2);

    return 0;
}
