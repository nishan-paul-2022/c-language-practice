/*
 * Purpose: Demonstrates basic pointer declaration and dereferencing.
 * Topic: Pointers, Memory Addresses, Dereferencing
 */

#include <stdio.h>

void change_value(int number, int *pointer_to_number) {
    printf("number: %d\n", number);
    printf("*pointer_to_number: %d\n", *pointer_to_number);
    printf("&number: %p\n", &number);
    printf("pointer_to_number: %p\n", pointer_to_number);
}

int main(void) {
    int number = 5;
    int *pointer_to_number = &number;

    printf("Before chnaging the value of number.\n");
    change_value(number, pointer_to_number);

    *pointer_to_number = 10;

    printf("\nAfter chnaging the value of number.\n");
    change_value(number, pointer_to_number);

    return 0;
}
